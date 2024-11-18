# Born2beroot
            
             BORN2BEROOT CORRECTION
            ------------------------
            
            PARTIE I : UFW / PARE-FEU
 
 ***A quoi sert une machine virtuel?
 -permet d'utiliser une autre systeme d'exploitation.
 -permet de tester un virus (ou tout type de programme douteux) car c'est un environnement isoler et sur donc on ne risque rien.(L'ordi principal ne sera pas affecter).
 -utilise un logiciel pour executer les programmes ou applications.
 
 ***Qu est ce qu une machine virtuelle?
 Est une ressource qui utilise un logiciel au lieu d’un ordinateur physique pour exécuter des programmes ou des applications. Chaque VM possède son propre système d'exploitation et fonctionne séparément, on peut avoir plus d'une VM par machine. Peut être utilisé pour tester des applications dans un environnement sûr et séparé.
 
 ***Difference entre rocky et debian ?(systeme d'exploitation)
 -rocky est plutot pour les entreprises et debian pour le grand public. (debian est plus facile a utiliser pour un debutant).
 
 
 ***Verifier que UFW est installe sur la VM
 sudo ufw status
 (Status : active)
 
 
 ***C'est quoi UFW?
 Un outil qui permet de gerer les pare-feu. 
 Un pare-feu = dispositif de securite qui controle les trafics grace au port ouvert ou fermer.
 
 Un pare-feu = outil qui gere la securite de l'ordi ou du serveur.
 utilisé pour protéger l'ordinateur ou le serveur contre les connexions non autorisées et les attaques venant de l'extérieur.
 
 ufw = agent de securite qui decide qui peut entrer ou pas
 pare-feu = la porte d'entree. 
 
 ***Enumerer les regles actives dans UFW
 sudo ufw status
 
 Ex: Port 4242 Allow Anywhere = le port 4242 est ouvert et autorisé à accepter des connexions venant de n'importe où.
 
 ***Ajouter une nouvelle regle au port ouvert 8080
 sudo ufw allow 8080
 Puis pour verifier : sudo ufw status
 
 ***Supprimer un port
 On affiche avec : sudo ufw status numbered
 Puis on supprime : sudo ufw delete [ 3] 
 
 ----------------------------------------------------------------------------------------------------

		PARTIE II : Nom d'hote et partitions

***Vérifier que le nom d'hôte de la machine est formaté comme suit: nolecler42
 hostnamectl

***Changez ce nom d'hôte en remplaçant la connexion par celui de l evaluateur
 hostnamectl set-hostname new_hostname- 

***Redémarrez votre machine virtuelle.

***Verifier si le nom d'hote a bien ete modifier lors du demarrage
 hostnamectl


***Vous pouvez maintenant restaurer le nom d'hôte original de la machine.
 sudo nano /etc/hosts-  
 sudo vim /etc/hosts-  A REVOIR
 
***Afficher les partitions de la machine virtuelle
 lsblk

***Expliquer le fonctionnement de LVM
c'est un systeme de gestion de disque qui permet de gerer l'espace de stockage de maniere plus flexible que les partitions classiques. C est a dire qu on peut ajuster facilement. 
Logical volume Management , permet de gerer l'espace d'un disque dur et ce disque peut etre redimensionnes sans interrompre le system.

-----------------------------------------------------------------------------------------------------

		PARTIE III : Directives generales
		
***Vérifiez que le fichier "signature.txt" est présent à la racine du référentiel cloné.
Aller la ou on a stocker la machine virtuel et tape : sha1sum nom.vdi

***S'assurer que la signature contenue dans "signature.txt" correspond à celle du fichier ".vdi" de la machine virtuelle évaluée.

***Savoir ou se trouve le fichier ".vdi"

Par mesure de précaution, vous pouvez dupliquer la machine virtuelle d'origine pour en conserver une copie.

Lancer la machine virtuelle à évaluer.
 
-----------------------------------------------------------------------------------------------------

		PARTIE IV : SUDO
	
la commande SUDO = SuperUtilisateurDO 
		
***Vérifier que le programme "sudo" est bien installé sur la machine virtuelle.
 sudo -V
 dpkg -l | grep sudo –

 

***La personne évaluée doit maintenant montrer comment affecter votre nouvel utilisateur au groupe "sudo".
- sudo adduser new username : ajouter un nouvel utilisateur (Nouveau MDP a ecrire)
- sudo addgroup groupname   : creer un groupe 
- sudo usermod -aG groupname username : ajouter le nouvel utilisateur au groupe sudo
 
- getent group sudo 
- getent group user42 

 ***Expliquer le but et le fonctionnement de sudo avec des exemples de son choix. Ils doivent alors démontrer la mise en œuvre des règles imposées par le sujet.
 A FAIRE
 Dans une entreprise , sudo c'est un id c'est celui qui gere des utilisateurs
 
 ***Vérifier que le répertoire "/var/log/sudo/" existe et contient au moins un fichier.
 A FAIRE
 
 *** Vérifiez le contenu des fichiers dans ce répertoire; vous devriez voir un historique des commandes utilisées avec le sudo.
 A FAIRE
 
 ***Enfin, tenter d'exécuter une commande via sudo. Vérifiez si le(s) fichier(s) du répertoire "/var/log/sudo/" ont été mis à jour. 
 A FAIRE
 
 --------------------------------------------------------------------------------------------------
 
 	Essais preliminaire
 
 Vérifier les points suivants:

Les conditions d'accès à la défense sont remplies: la ou les personnes évaluées sont présentes, la soumission est non vide et leur appartient véritablement, etc.

Pour ce projet, vous devez cloner le dépôt Git sur l'ordinateur de la personne évaluée.
 
 --------------------------------------------------------------------------------------------------
 
 	Utilisateur

*** Le sujet exige qu'un utilisateur avec le nom de connexion de la personne évaluée soit présent sur la machine virtuelle.

***Vérifier que cet utilisateur a été ajouté et qu'il appartient aux groupes "sudo" et "user42". 

***Veiller à ce que les règles imposées en la matière concernant la politique de mot de passe aient été mises en œuvre en suivant les étapes ci-dessous

***Tout d'abord, créer un nouvel utilisateur. L'attribuer un mot de passe de votre choix, en respectant les règles du sujet. La personne évaluée doit maintenant expliquer comment elle a pu mettre en œuvre les règles demandées sur sa machine virtuelle. Normalement, un ou deux fichiers auraient été modifiés.

***Maintenant que vous avez un nouvel utilisateur, demandez à la personne évaluée de créer un groupe nommé "évaluant" devant vous et de l'affecter à cet utilisateur.

***vérifiez que cet utilisateur appartient bien au groupe "évaluateur".

***demander à la personne évaluée d'expliquer l'objectif de cette politique de mot de passe, ainsi que les avantages et les inconvénients de sa mise en œuvre.


----------------------------------------------------------------------------------------------------

		Vue d'ensemble :
		
***Expliquer Le fonctionnement de base de leur machine virtuelle

***Expliquer Leur choix de système d'exploitation

***Expliquer Les différences fondamentales entre Rocky et Debian

***Expliquer Les avantages des machines virtuelles
-permet de tester ou d'exécuter des applications dans un environnement sécurisé sans affecter ton système principal.

***Expliquer la différence entre l'aptitude et l'APT (Advanced Packaging Tool)

- APT et Aptitude sont des gestionnaires de paquets pour Linux qui facilitent l'installation et la gestion des applications en utilisant des paquets logiciels.  
- Aptitude est plus intelligent et supprimera automatiquement les packages inutilisés ou suggérera l'installation de packages dépendants.


- Aptitude est souvent décrit comme plus intelligent que APT, car il peut proposer des solutions pour résoudre des conflits de dépendances automatiquement, là où APT se contenterait de les signaler sans proposer de solution.

package(paquet) = un fichier qui contient tous les elements necessaires pour installer une application 
 ou un outil sur un ordi.
 

***Expliquer ce qu'est APPArmor.
 
 - c'est un outil de securite sur linux qui protege le systeme contre les comportements indesirables ou malveillants des applications en limitant ce qu'elles peuvent faire.
 
  Exécutez aa-status pour vérifier s'il est en cours d'exécution.
 

Pendant la défense, un script doit afficher des informations toutes les 10 minutes.


----------------------------------------------------------------------------------------------------
 	
 		Configuration simple
 	
 ***Vérifier que la machine n'a pas d'environnement graphique au démarrage.
 
 ***Un mot de passe sera demandé avant toute tentative de connexion sur cette machine. Connectez-vous avec un utilisateur non racine.
 
 ***Vérifier que le mot de passe choisi respecte les règles imposées en la matière.
 
 ***assurez-vous que : Le système d'exploitation choisi est en effet Debian.

 ***assurez-vous que : Le service UFW est correctement lancé

 ***assurez-vous que : Le service SSH est correctement lancé.
 
 ---------------------------------------------------------------------------------------------------

		SSH
		
***Vérifier que le service SSH est bien installé sur la machine virtuelle.

***Vérifier que le service SSH fonctionne correctement.

***Donner une explication de base de ce qu'est SSH et pourquoi il est important de l'utiliser.
 SSH ou Secure Shell est un mécanisme d'authentification entre un client et un hôte. Il utilise des techniques de cryptage afin que toutes les communications entre les clients et les hôtes se fassent sous forme cryptée. Les utilisateurs sous Mac ou Linux peuvent utiliser SSH le terminal pour travailler sur leur serveur via SSH.
 
 
 ***Vérifier que le service SSH n'utilise que le port 4242.
 
 ***La personne évaluée doit vous aider à utiliser SSH pour se connecter au nouvel utilisateur créé. Pour cela, vous pouvez utiliser une clé ou un simple mot de passe, en fonction de la personne évaluée. Bien entendu, vous devez vous assurer que le SSH ne peut pas être utilisé avec l'utilisateur "racineux" comme indiqué dans le sujet.
 
 --------------------------------------------------------------------------------------------------
 
 		Surveillance du SCRIPT
 		
 ***Expliquer :Le fonctionnement du script en affichant son code
 
 ***Qu'est-ce que le "cron"
  Cron ou cron job est un utilitaire de ligne de commande permettant de planifier des commandes ou des scripts à des intervalles spécifiques ou à une heure précise chaque jour. Utile si vous souhaitez configurer votre serveur pour qu'il redémarre à une heure précise chaque jour.
  
 
 
***Comment ils ont mis en place leur script pour exécuter toutes les 10 minutes à partir du lancement du serveur. Une fois le bon fonctionnement du script vérifié, la personne évaluée doit s'assurer que ce script s'exécute toutes les minutes. Vous pouvez lancer tout ce que vous souhaitez garantir que le script s'exécute correctement avec des valeurs dynamiques. Enfin, la personne évaluée doit s'assurer que le script ne s'exécute plus au lancement du serveur, sans modifier le script lui-même. Pour vérifier ce point, le serveur devra être redémarré une dernière fois. Au démarrage, il faut vérifier que le script existe toujours au même endroit, que ses permissions sont restées inchangées, et qu'il n'a pas été modifié.

	BONUS
La mise en œuvre des partitions vaudra 2 points


-------------------------------------------------------------------------------------------------------------






***Règles de mot de passe
Pour les règles de mot de passe, nous utilisons la bibliothèque de vérification de la qualité des mots de passe et il existe deux fichiers : le fichier de mot de passe commun qui définit les règles telles que les caractères majuscules et minuscules, les caractères en double, etc. et le fichier login.defs qui stocke les règles d'expiration des mots de passe (30 jours, etc.). Sudo nano /etc/login.defs Sudo nano /etc/pam.d/common-password





	cd /usr/local/bin– pour afficher monitoring.sh
	sudo crontab -u root -e– pour éditer la tâche cron
	change script to */1 * * * * sleep 30s && script path– pour l’exécuter toutes les 	
	30 secondes, supprimez la ligne pour arrêter l’exécution du travail.

***Commandes d'évaluation pour UFW, Group, Host, lsblk et SSH

- sudo ufw status

- sudo systemctl status ssh

- getent group sudo
- getent group user42

- sudo adduser new username : ajouter un nouvel utilisateur 
- sudo groupadd groupname   : creer un groupe sudo
- sudo usermod -aG groupname username : ajouter le nouvel utilisateur au groupe sudo
- sudo chage -l username- vérifier les règles d'expiration du mot de passe

- hostnamectl
- hostnamectl set-hostname new_hostname- pour changer le nom d'hôte actuel

- Redémarrez votre machine virtuelle.

- sudo nano /etc/hosts- changer le nom d'hôte actuel en nouveau nom d'hôte

- lsblk pour afficher les partitions

- dpkg -l | grep sudo –pour montrer que sudo est installé

- sudo ufw status numbered
- sudo ufw allow port-id
- sudo ufw delete rule number

- ssh your_user_id@127.0.0.1 -p 4242- faites ceci dans le terminal pour montrer que SSH sur le port 4242 fonctionne












 
