# ICT-340

## Loik Meylan  
### SI-C3a

# ESXi :

## Pré-réquis instalation ESXi :

Intel VT : https://fr.wikipedia.org/wiki/Intel_VT

Liste de serveurs compatible : http://www.vmware.com/resources/compatibility/search.php

Fichier iso utilisé pour l'instalation : VMware-VMvisor-Installer-201704001-5310538.x86_64.iso

## Installation ESXi

Nom : hyperviseur_H1
Os : VMvisor

### Hardware :

* RAM : 4 GB  
* Disque dur : 40 GB
* Disque dur 2 : 100GB  
* Network adaptater 1 : NAT  
* Network adaptater 2 : Host only

### Configuration Réseau : 

* NAT
  * Hostname : Admin
  * IP : 192.168.164.130
  * Masque : 255.255.255.0
  * Passerelle par défaut : 192.168.164.2
  * DNS : 192.168.164.2
* Host-only
  * Hostname : Data
  * IP : 10.10.10.130
  * Masque : 255.255.255.0
  * Passerelle par défaut : 10.10.10.2

## vSphere Web Client :

Adresse : https://192.168.164.130/ui/#/host

### spécificité : 

#### VM :

* Debian 8
* Windows 10 x64
  
#### Stockage :

* datastore 1 40 GB
  * ISO Debian 8
  * VM Debian 8
* datastore 2 100 GB
  * VM Windows 10 x64

## Installation Linux :

Nom : Debian

### Hardware :

* Bureau : aucun
* RAM : 512
* Disque dur : 6 GB
  
### Service :

* open-vm-tools
* openssh-client
* openssh-server

### Utilisateur :

* Utilisateur :
  * root :
    * mot de passe : Pa$$w0rd
  * cpnv :
    * mot de passe : cpnv
 
### Installation de Open Virtual Machine Tools :

`sudo apt update`

`sudo apt upgrade`

`sudo apt install open-vm-tools`

### Ajout d'un second datastore :

* Arrêter l'hyperviseur_H1
* Ajouter un second disque dur de 100GB
* Redémarrer l'hyperviseur_H1
* Se connecter sur le client web
* Ajouter un second datastore en utilisant le second disque dur
* le nommer "datastore 2"

## Installation Windows :

Nom : Windows 10 x64  
OVA en local dans C:\Users\loik.meylan\Documents\Virtual Machines\Windows 10 x64.ova  
VMware Tools installé

### Hardware : 

* RAM 2 GB
* Disque dur 60 GB

### Upload dans datastore 2 :

Snapshot :
* Avant exécution Sysrep
* Après exécution Sysrep

Effectuer l'outil Sysrep avec l'option généralisée, éteindre puis extraire la machine en .ova (sélectioner la machine puis file -> export to ovx .ovx originellement mais changer en ova),  
cloner la machine (click droit -> manage -> clone), puis l'upload dans le datastore 2 (click droit -> manage -> upload)

## Installation Windows server :

Nom : Windows server 2012

### Hardware : 

* RAM 2 GB
* Disque dur 60 GB

### Service :

Veeam Backup Free edition

### Veeam Backup :

Créer une nouvelle backup avec **New Backup Job**  
<br>
Paramètre : 
* IP cible : 192.168.164.130
* User : root
* Mot de passe : Pa$$w0rd

Sauveguarde Debian 8

# Citrix :

## Pré-requis instalation Citrix :

CPU 64bits avec technologie Inter VT - AMD-V  
2 Go de RAM minimum (8Go recommandé)  
46 Go de Disque minimum (70Go recommandé)  
100 Mo/s pour l'interface réseau (10Go/s recommandé)  

## Pré-réquis instalation XenCenter : 

Framework .NET 3.5  
CPU 750 MHz minimum (1GHz recommandé)  
RAM 2 Go recommandé  
Disque dur minimum 100 Mo  
Interface réseau 100 Mo minimum  

iso : 
* XenServer-7.0.0-main.iso
* debian-8.11.1-amd64-netinst.iso  

## XenServer1 :

Nom : XenServer1  
Os : XenServer  

### Hardware :

Disque dur : 70 Go  
RAM : 4 Go  
Datastore1 : 70 Go  
Datastore2 : 100 Go  

### VM :

* Datastore1 :  
  * instalation Debian 8  
* Datastore2 :  
  * instalation Windows 10  

## XenServer2 :

Nom : Xenserver2  
Os : XenServer  

## Hardware :

Disque dur : 70 Go  
RAM : 2 Go  
Datastore1 : 70 Go  

## Installation XenServer :

* XenServer1 :
  * eth0 (NAT) - Admin
    * IP : 192.168.20.200
    * Masque : 255.255.255.0
    * Parcelle par défaut : 192.168.20.2
    * DNS : 192.168.20.2
  * eth1 (Host-Only) - Data
    * IP : 10.10.10.200
    * Masque : 255.255.255.0
    * Parcelle par défaut : 10.10.10.2
* XenServer2 :
  * eth0 (NAT) - Admin
    * IP : 192.168.20.210
    * Masque : 255.255.255.0
    * Parcelle par défaut : 192.168.20.2
    * DNS : 192.168.20.2
  * eth1 (Host-Only) - Data
    * IP : 10.10.10.210
    * Masque : 255.255.255.0
    * Parcelle par défaut : 10.10.10.2

### Importation Debian dans XenServer1 :

Depuis XenServer1, accéder au terminal et entrer les commandes suivantes

`mkdir -p /var/opt/xen/iso_import`  
`xe sr-create name-label=LocalISO type=iso device-config:location=/var/opt/xen/iso_import device-config:legacy_mode=true content-type=iso`  

Déposer l'iso Debian 8 dans le dossier "iso_import" par le biais de WinSCP.  
À partir de Citrix XenCenter l'iso est utilisable pour créer une vm Debian 8 (installation classique).

### Ajout d'un second datastore :

Après avoir ajouté un nouveau disque dur de 100 GB dans XenServer1, allumer, puis accéder au terminal et taper la commande suivante :

`fdisk –`  
`xe sr-create name-label=<Name of Storage> shared=false device-config:device=<Path of the Storage device> type=lvm`  

### Upload Windows 10 :

Créer une vm Windows 10 (installation basique), puis l'upload dans le XenServer1 (click droit -> manage -> upload)  

## Windows Server :

Nom : WS2012
Os : Windows Server

### Hardware :

Disque dur 1 : 70 Go
Disque dur 2 : 100 Go

### Réseau :

* eth0 (NAT) - Admin
  * 192.168.20.10
* eth1 (Host-Only) - Data
  * 10.10.10.10

### Software :

StarWind (License 30 jours)
  * cluster-xenserver-storage : 100 Go

### Mise en place d'un SAN avec StarWind :

1.	Sous Starwind sélectionner **Add target** et cocher **Allow multiple concurrent ISCSI**
2.	Donner un nom ("cluster-xenserver-storage")
3.	Attribuer le disque de 100GB
4.	Configurer sur chaque XenServer le **NIC1** depuis **Networking**
    1.	Cliquer sur **Add Network**
    2.	Select type > **External Network**
    3.	Nom : Réseau ISCSI
    4.	Interface > Carte NIC1
    5.	Configure > New Interface
    6.	Nom : DATA
    7.	Sélectionner **réseau ISCSI**
    8.	IP static : 10.10.10.200 (XenServer1) ou 10.10.10.210 (XenServer1)

### Ajout d'un nouveau disque partagé :

1.	Cliquer sur **New SR**
2.	Sélectionner **ISCSI**
3.	Nom : Data
4.	IP Cible : 10.10.10.10
5.	Cliquer sur **Discover IQN**
6.	Sélectionner la cible et cliquez sur **Discover LUN** 
7.	Enfin sur **Finish**
8.	Accepter le formatage

### Création d'un POOL :

Depuis Citrix XenCenter, click droit sur **XenCenter** puis **New Pool**, enfin nommer le "POOL"

### Activation du HA (High availability) :

Accéder au paramètre du POOL précédemment créer, dans l'onglet HA clicker sur **configure HA**, sélectionner le disque partagé, sélectionner ensuite la vm Debian 8 et dans "HA restart priority:", sélectionner **Restart if possible**, clicker sur "Next" puis "Finish".

# Docker :

## Debian 9 :

### Hardware :

* Mémoire : 2 GB
* Disque dur : 70GB
* Network adapter : NAT
* iso : debian-9.8.0-amd64-netinst.iso

### Package : 

* sudo
* server-ssh
* lynx

## Installation Docker :

Site : https://docs.docker.com/engine/install/debian/

Installer Docker en executant ses commandes :

`sudo dpkg -i /path/to/package.deb`  
`sudo docker run hello-world`  

Une fois Docker installé, exécuter cette commande :

`sudo docker run hello-world`  

Cela devrait afficher ceci :

`Unable to find image 'hello-world:latest' locally`  
`latest: Pulling from library/hello-world`  
`b901d36b6f2f: Pull complete`  
`0a6ba66e537a: Pull complete` 
`Digest: sha256:.... Status: Downloaded newer image for hello-world:latest`  

`Hello from Docker.`  
`This message shows that your installation appears to be working correctly. [...]`  

Ensuite executer cette commande :

`docker pull ubuntu`  

Puis celle-ci :

`docker images`  

## Création du container Apache :

Créer le répertoire : *~/Docker/Apache*
Depuis ce répertoire, créer le fichier *Dockerfile* et mettre les commandes :

`FROM ubuntu:latest`  
  `MAINTAINER votre_nom`  
  `RUN apt -yqq update && apt install -yqq apache2`  

`WORKDIR /var/www/html`  

`ENV APACHE_RUN_USER www-data`  
`ENV APACHE_RUN_GROUP www-data`  
`ENV APACHE_LOG_DIR /var/log/apache2`  
`ENV APACHE_PID_FILE /var/run/apache2.pid`  
`ENV APACHE_RUN_DIR /var/run/apache2`  
`ENV APACHE_LOCK_DIR /var/lock/apache2`  

`RUN mkdir -p $APACHE_RUN_DIR $APACHE_LOCK_DIR $APACHE_LOG_DIR`  

`ENTRYPOINT [ "/usr/sbin/apache2" ]`  
`CMD ["-D", "FOREGROUND"]`  
`EXPOSE 80`  

Ensuite, éxecuter la commande suivante :

`sudo docker build -t="votre_nom/apache" .`  

## Installation Oracle et SQLDeveloper avec Docker :

Installer Kitematic, Si vous n'avez pas Windows 10 Pro ou Éducation, installer Docker Toolbox,  
Chercher "docker-oracle-xe-11g" dans Kitematic (celle réalisée par alexeiled)  

Installer SQLDeveloper puis clicker sur "créer manuellement une connexion"

* Nom de connexion : local
* Nom d'utilisateur : system
* Mot de passe : oracle
* Nom de l'hôte : localhost
* Port : 49160
* SID : xe

## Faire fonctionner Microsoft SQL Server dans un container Linux avec Docker

Ouvrir Powershell et exécuter cette commande :

`docker pull microsoft/mssql-server-linux:2017-latest`

Si cela ne fonctionne pas, se rendre sur https://hub.docker.com/r/microsoft/mssql-server-linux/ et exécuter la commande affichée

Exécuter ensuite cette commande : 

`docker run -e 'ACCEPT_EULA=Y' -e 'SA_PASSWORD=Str0ngPassword!'`  
`-p 1401:1433 -d --name=tomssl_sql microsoft/mssql-server-`  
`linux:latest`  

Afin de vérifier que tout fonctionne correctement, exécuter cette commande afin d'ouvrir une console de commande SQL :

`docker exec -it tomssl_sql /opt/mssql-tools/bin/sqlcmd -S localhost -U sa`  

vous serez demandé d'entrer un mot de passe que l'ont a déjà défini dans la commande précédente sous cette section : 

`'SA_PASSWORD=Str0ngPassword!'`  

Entrer donc le mot de passe afin d'être accueilli par ceci : `1>`  

entrer ensuite ces deux commandes :

`1> SELECT @@VERSION`    
`2> GO`  

Télécharger ensuite SQL Server Management Studio 2017 : https://docs.microsoft.com/en-us/sql/ssms/download-sql-server-management-studio-ssms

Dans la fenêtre "Connect to server" vous devrez entrer des informations afin de vous connecter à votre container :

* Server type : Database engine
* Server name : localhost, 1401
* Authentification : SQL Server Authentification
  * login : sa
  * Password : le mot de passe défini dans `'SA_PASSWORD=Str0ngPassword!'`

Après vous être connecté, rexécuter cette commande :

`SELECT @@VERSION`

# Conclusion

En conclusion, c'était un sympathique module mais qui avait son lot de problème, la majorité des difficultés était dues à des fonctionnalitées qui ne fonctionnaient plus du jours au lendemain. Par exemple je me souviendrai toujours du vendredi 8.10 où j'ai passé toute les trois périodes à régler problèmes après problèmes alors qu'il me reste une ou deux tâches avant de pouvoir faire le POC Citrix, j'ai eu aussi des problèmes avec Docker mais pas autant que Citrix heureusement, le début était compliqué malgré-tout. Je ne me souviens pas avoir trop de problème avec Esxi donc je pense que c'était plus simple, malgré-tout j'ai personellement préféré Docker car ça m'a semblé plus simpliste que les deux autres façon, une simplisité que j'ai accueilli à bras ouvert.

En bref le module est bon mais les outils sont hazardeux.
