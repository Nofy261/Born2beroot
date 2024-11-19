#!/bin/bash 

# Récupère l'architecture et d'autres informations système


arc=$(uname -a)  # 'uname -a' affiche des informations complètes sur le système (noyau, architecture, etc.)

pcpu=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)  # Compte le nombre de CPU physiques en analysant /proc/cpuinfo


vcpu=$(grep "^processor" /proc/cpuinfo | wc -l)  # Compte le nombre de processeurs logiques


fram=$(free -m | awk '$1 == "Mem:" {print $2}')  # Affiche la quantité totale de RAM en MB

uram=$(free -m | awk '$1 == "Mem:" {print $3}')  # Affiche la quantité de RAM utilisée en MB


pram=$(free | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')  # Calcule le pourcentage de RAM utilisée


fdisk=$(df -BG | grep '^/dev/' | grep -v '/boot$' | awk '{ft += $2} END {print ft}')  # Calcule la capacité totale des disques (en GB)


udisk=$(df -BM | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} END {print ut}')  # Calcule l'espace disque utilisé (en MB)


pdisk=$(df -BM | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} {ft+= $2} END {printf("%d"), ut/ft*100}')  # Calcule le pourcentage d'espace disque utilisé


cpul=$(top -bn1 | grep '^%Cpu' | cut -c 9- | xargs | awk '{printf("%.1f%%"), $1 + $3}')  # Calcule l'utilisation du CPU en pourcentage


lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')  # Affiche la date et l'heure du dernier démarrage du système


lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -eq 0 ]; then echo no; else echo yes; fi)  # Vérifie si LVM est utilisé

ctcp=$(ss -Ht state established | wc -l)  # Compte le nombre de connexions TCP établies


ulog=$(users | wc -w)  # Compte le nombre d'utilisateurs connectés (en nombre de sessions)


ip=$(hostname -I)  # Récupère l'adresse IP de la machine

mac=$(ip link show | grep "ether" | awk '{print $2}')  # Affiche l'adresse MAC de l'interface réseau


cmds=$(journalctl _COMM=sudo | grep COMMAND | wc -l)  # Compte le nombre de commandes sudo exécutées

"	#Architecture: $arc
	#CPU physical: $pcpu
	#vCPU: $vcpu
	#Memory Usage: $uram/${fram}MB ($pram%)
	#Disk Usage: $udisk/${fdisk}Gb ($pdisk%)
	#CPU load: $cpul
	#Last boot: $lb
	#LVM use: $lvmu
	#Connections TCP: $ctcp ESTABLISHED
	#User log: $ulog
	#Network: IP $ip ($mac)
	#Sudo: $cmds cmd"  # Affiche un résumé des informations système à tous les utilisateurs connectés
