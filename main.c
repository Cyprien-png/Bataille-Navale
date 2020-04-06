/**@author: Cyprien
 * @date: 26.02.2020
 * @what: Battaille Navale
*/

#include <stdio.h>
#include <stdlib.h>
#include <rpc.h>
#include <string.h>
#include <time.h>



//écrit la date et l'heure de l'action dans le fichier "historique.txt"
int date(void) {
    int heure, minute, jour, mois, an;
    time_t now;

    // Renvoie l'heure actuelle
    time(&now);
    // Convertir au format heure locale
    struct tm *local = localtime(&now);
    heure = local->tm_hour;
    minute = local->tm_min;
    jour = local->tm_mday;
    mois = local->tm_mon + 1;
    an = local->tm_year + 1900;

    //pointe le fichier a modifier
    FILE *Historique;

    //ouvre le fichier et ecrit l'heure
    Historique = fopen("historique.txt", "a");
    fprintf(Historique, "Date: %02d/%02d/%d Heure %02d:%02d", jour, mois, an, heure, minute);
    fclose(Historique);
    return 0;
}

//écrit les changements de pseudo
void historiquePseudoDecompose(int valeur){

    int caractereActuel = 0, compteur = 0, fin = 0;
    char pseudo = ' ';

    FILE *Historique;
    FILE *fichier;
    FILE *historique;

    Historique = fopen("historique.txt", "a");
    if (valeur ==1) {
        fprintf(Historique, " changement de pseudo ancien pseudo: <");
    }else if (valeur == 2) {
        fprintf(Historique, "> nouveau pseudo: <");
    }
    fclose(Historique);

    if (fichier != NULL) {
        fichier = fopen("pseudo.txt", "r");
        // compte le nombre de caracteres du pseudo
        do {
            compteur++;
            caractereActuel = fgetc(fichier); //on regarde un seul caractere
        } while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
        fclose(fichier);

        // écrit le pleuso moin le caracteur EOF qui est inutile
        fichier = fopen("pseudo.txt", "r");
        // Boucle de lecture des caractères un à un
        do {
            fin++;
            caractereActuel = fgetc(fichier); // On lit le caractère
            pseudo = caractereActuel;
            fflush(stdin);
            //ouvre le fichier et ecrit le nom de du joueur
            historique = fopen("historique.txt", "a");
            fprintf(historique, "%c", pseudo);
            fclose(historique);
        } while (fin != compteur - 1); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
        if (valeur == 2){
            historique = fopen("historique.txt", "a");
            fprintf(historique,">\n");
            fclose(historique);
        }
    }
}

//écrit qu'un partie a été terminée dans l'historique
void historique() {
    int valeur =0;
    //pointe le fichier a modifier
    FILE *Historique;

    //ouvre le fichier et ecrit l'heure
    Historique = fopen("historique.txt", "a");
    fprintf(Historique, " Une parti a été terminée par <");
    fclose(Historique);
    //écrit le pseudo du joueur
    historiquePseudoDecompose(valeur);
    Historique = fopen("historique.txt", "a");
    fprintf(Historique,">\n");
    fclose(Historique);
}

//écrit qu'un partie a été lancée dans l'historique
void historiquePartie() {
    int valeur =0;
    //écrit la date et l'heure dans le fichier historique
    date();
    //pointe le fichier a modifier
    FILE *Historique;

    //ouvre le fichier et ecrit l'heure
    Historique = fopen("historique.txt", "a");
    fprintf(Historique, " Une parti a été démarée par <");
    fclose(Historique);
    //écrit le pseudo du joueur
    historiquePseudoDecompose(valeur);
    Historique = fopen("historique.txt", "a");
    fprintf(Historique,">\n");
    fclose(Historique);
}

//écrit que les scores on été supprimés dans l'historique
void historiqueScoreSuppression(){
    int valeur =0;
    //ecrit l'heure
    date();
    FILE *Historique;

    //ouvre le fichier et ecrit que les scores ont été supprimés
    Historique = fopen("historique.txt", "a");
    fprintf(Historique, " Les scores ont été supprimés par <");
    fclose(Historique);
    //écrit le pseudo de la personne
    historiquePseudoDecompose(valeur);
    Historique = fopen("historique.txt", "a");
    fprintf(Historique,">\n");
    fclose(Historique);
}

//lis et écrit le pseudo qui est enregistré dans le fichier pseudo.txt
void lire() {
    FILE *fichier = NULL;
    int caractereActuel = 0;

    fichier = fopen("pseudo.txt", "r");

    if (fichier != NULL) {
        // Boucle de lecture des caractères un à un
        do {
            caractereActuel = fgetc(fichier); // On lit le caractère
            printf("%c", caractereActuel); // On l'affiche
        } while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)

        fclose(fichier);
    }
}

//écrit un nouveau score a la fin de la partie
void scoresAjout() {
    char curseur;
    //pointe le fichier a modifier
    FILE *scores;

    if (scores != NULL) {
        int supprimer = 0;
        //ouvre le fichier et ecrit le nom de du joueur
        scores = fopen("scores.txt", "r");
        fscanf(scores, "%c", &curseur);
        if (curseur == '#') {
            supprimer = 1;
        }
        //fonction qui supprime le # sensé être la pour afficher qu'il n'y a pas de score deja enregistré
        fclose(scores);
        if (supprimer == 1) {
            scores = fopen("scores.txt", "w");
            fprintf(scores, ";");
            fclose(scores);

        }
    }
}

//efface tout les scores
void effacerLesScores() {
    historiqueScoreSuppression();
    //pointe le fichier a modifier
    FILE *score;

    //ouvre le fichier et ecrit le nom de du joueur
    score = fopen("scores.txt", "w");
    fprintf(score, "#");
    fclose(score);
}


void afficheScore() {
    char curseur;
    int sortie = 0, compteur = 0;
    do {
        system("cls");
        printf(" ___  ___ ___  _ __ ___  ___ \n");
        printf("/ __|/ __/ _ \\| '__/ _ \\/ __|\n");
        printf("\\__ \\ (_| (_) | | |  __/\\__ \\\n");
        printf("|___/\\___\\___/|_|  \\___||___/\n\n\n");

        FILE *scores;
        scores = fopen("scores.txt", "r");
        if (scores != NULL) {
            do {
                fscanf(scores, "%c", &curseur);
                if (curseur == ':') {
                    printf("\t\t\t\t");
                } else if (curseur == ';') {
                    printf("\n");
                } else if (curseur == '#') {
                    compteur++;
                } else {
                    printf("%c", curseur);
                }
            } while (!feof(scores));
            fclose(scores);
            if (compteur > 0) {
                printf("il n'y a pas de scores enregistre");
            }
        }
        printf("\n\n\n");
        printf(" 1 - Retour");
        scanf("%d", &sortie);
    } while (sortie != 1);
}


void scoresEcriturePseudo() {
//pointe le fichier a modifier
    FILE *fptr;
    FILE *fichier = NULL;
    int caractereActuel = 0, compteur = 0, fin = 0;
    char pseudo = ' ';
    fichier = fopen("pseudo.txt", "r");

    if (fichier != NULL) {
        fichier = fopen("pseudo.txt", "r");
        // compte le nombre de caracteres du pseudo
        do {
            compteur++;
            caractereActuel = fgetc(fichier); //on regarde un seul caractere
        } while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
        fclose(fichier);

        // écrit le pleuso moin le caracteur EOF qui est inutile
        fichier = fopen("pseudo.txt", "r");
        // Boucle de lecture des caractères un à un
        do {
            fin++;
            caractereActuel = fgetc(fichier); // On lit le caractère
            pseudo = caractereActuel;
            fflush(stdin);
            //ouvre le fichier et ecrit le nom de du joueur
            fptr = fopen("scores.txt", "a");
            fprintf(fptr, "%c", pseudo);
            fclose(fptr);
        } while (fin != compteur - 1); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
        fclose(fichier);
        fptr = fopen("scores.txt", "a");
        fprintf(fptr, ":");
        fclose(fptr);
    }
}


void scoreEcriture(int tires) {
    //pointe le fichier a modifier
    FILE *fptr;

    //ouvre le fichier et ecrit le nom de du joueur
    fptr = fopen("scores.txt", "a");
    fprintf(fptr, "%d;", tires);
    fclose(fptr);
}


void pseudoJoueur() {
    int valeur = 1;

    //écrit le changement de pseudo
    date();
    historiquePseudoDecompose(valeur);
    valeur ++;

    //pointe le fichier a modifier
    FILE *fptr;

    //ouvre le fichier et ecrit le pseudo "joueur"
    fptr = fopen("pseudo.txt", "w");
    fprintf(fptr, "Joueur");
    fclose(fptr);

    //écrit le changement de pseudo
    historiquePseudoDecompose(valeur);
}


void creerPseudo() {
    char user[20];
    int valeur = 1;

    //écrit le changement de pseudo
    date();
    historiquePseudoDecompose(valeur);
    valeur ++;

    //affiche La page
    system("cls");
    printf("                          _       \n");
    printf("                         | |      \n");
    printf(" _ __  ___  ___ _   _  __| | ___  \n");
    printf("| '_ \\/ __|/ _ \\ | | |/ _` |/ _ \\ \n");
    printf("| |_) \\__ \\  __/ |_| | (_| | (_) |\n");
    printf("| .__/|___/\\___|\\__,_|\\__,_|\\___/ \n");
    printf("| |                               \n");
    printf("|_|                               \n\n\n");

    printf("Votre pseudo actuel est : ");
    lire();
    printf("\n\n");

    printf("tapez votre nouveau pseudo, ne mettez pas de caracteres speciaux\n");
    scanf("%s", user);

    //pointe le fichier a modifier
    FILE *fptr;

    //ouvre le fichier et ecrit le nom de du joueur
    fptr = fopen("pseudo.txt", "w");
    fprintf(fptr, "%s", user);
    fclose(fptr);
    //écrit le changement de pseudo
    historiquePseudoDecompose(valeur);
}


void ecran() {
    //met la console en fenêtré
    keybd_event(VK_MENU, 0x38, 0, 0);
    keybd_event(VK_RETURN, 0x1c, 0, 0);
    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}


void pseudoSuggere() {
    int valeur = 1;
    char user[255];
    //va chercher le nom de la session windows de l'utilisateur
    strcpy(user, getenv("username"));

    //écrit le changement de pseudo
    date();
    historiquePseudoDecompose(valeur);
    valeur ++;

    //pointe le fichier a modifier
    FILE *fptr;

    //ouvre le fichier et ecrit le nom de du joueur
    fptr = fopen("pseudo.txt", "w");
    fprintf(fptr, "%s", user);
    fclose(fptr);
   // historiquepseudo(user);

    //écrit le changement de pseudo
    historiquePseudoDecompose(valeur);
}


void choixPseudo(int choix) {
    //redirige vers les options
    switch (choix) {
        case 1:
            //lutilisateur tape lui meme son pseudo
            creerPseudo();
            break;
        case 2:
            //choisi un pseudo pour l'utilisateur
            pseudoSuggere();
            break;
        case 3:
            //choisi un pseudo pour l'utilisateur
            pseudoJoueur();
            break;
    }
}


void pseudoMenu() {
    //affiche le menu d'authenfication
    int choix = 0;
    do {

        system("cls");
        printf("                          _       \n");
        printf("                         | |      \n");
        printf(" _ __  ___  ___ _   _  __| | ___  \n");
        printf("| '_ \\/ __|/ _ \\ | | |/ _` |/ _ \\ \n");
        printf("| |_) \\__ \\  __/ |_| | (_| | (_) |\n");
        printf("| .__/|___/\\___|\\__,_|\\__,_|\\___/ \n");
        printf("| |                               \n");
        printf("|_|                               \n\n\n");

        printf("Votre pseudo actuel est : ");
        lire();
        printf("\n\n");

        printf(" 1 - Definir un pseudo\n");
        printf(" 2 - Pseudo suggere\n");
        printf(" 3 - Enlever votre pseudo\n\n");

        printf(" 4 - fermer");

        scanf("%d", &choix);
    } while (choix < 1 || choix > 4);
    //redirige vers le selecteur de choix
    choixPseudo(choix);
}


void space(int i) {
    //gere les espaces de l'easter Egg
    for (int e = 0; e < i; e++) {
        printf(" ");
    }
}


void oeufDePaques() {
    //petit easter Egg
    for (int i = 0; i < 152; i++) {
        system("cls");
        printf("______       _        _ _ _        _   _                  _      \n");
        printf("| ___ \\     | |      (_) | |      | \\ | |                | |     \n");
        printf("| |_/ / __ _| |_ __ _ _| | | ___  |  \\| | __ ___   ____ _| | ___ \n");
        printf("| ___ \\/ _` | __/ _` | | | |/ _ \\ | . ` |/ _` \\ \\ / / _` | |/ _ \\\n");
        printf("| |_/ / (_| | || (_| | | | |  __/ | |\\  | (_| |\\ V / (_| | |  __/\n");
        printf("\\____/ \\__,_|\\__\\__,_|_|_|_|\\___| \\_| \\_/\\__,_| \\_/ \\__,_|_|\\___|\n\n\n");

        printf("Bonjour ");
        lire();
        printf("Choisissez ce que vous voulez faire : \n\n");

        printf(" 1 - Jouer\n");
        printf(" 2 - Aide du jeu\n");
        printf(" 3 - Scores\n");
        printf(" 4 - Pseudo\n");
        printf(" 5 - Options \n\n");
        printf(" 6 - Quitter\n\n");
        //fais en sorte que le bateau se déplace
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        space(i);
        printf("                                             .\n");
        space(i);
        printf("                           .                 |\n");
        space(i);
        printf("                           +                 |\n");
        space(i);
        printf("                  .        |                *+W+-*\n");
        space(i);
        printf("     .           +y        +W+              . H                 .\n");
        space(i);
        printf("  .  +y            |I.   y  |               ! H= .           .  ^\n");
        space(i);
        printf("  !   \\     .     |H '. /   |  ___.        .! H  !   +--.--y !  V\n");
        space(i);
        printf("  !    \\     \\  +=|H|=='.=+ | |====\\   _  '_H_H__H_. H_/=  J !  !\n");
        space(i);
        printf(". !     \\'    VVV_HHH_/__'._H |  E  \\_|=|_|========|_|==|____H. ! _______.\n");
        space(i);
        printf("I-H_I=I=HH_==_|I_IIIII_I_I_=HH|======.I-I-I-=======-I=I=I=I_=H|=H'===I=I/\n");
        space(i);
        printf("\\                                                                      ,\n");
        space(i);
        printf(" |                                                                    /\n");
        space(i);
        printf(" .___________________________________________________________________'\n");
    }

    system("pause");
}


void optionsChoix(int choix) {
    //redirige vers l'options souhaitée
    switch (choix) {
        case 1:
            //change l'affichage de la console
            ecran();
            break;
        case 2:
            //efface tout les scores
            effacerLesScores();
            break;
    }
}


void option() {
    //affiche les options
    int choix = 10;
    do {
        system("cls");
        printf("---Affichage---\n\n");
        printf(" 1 - Plein ecran On/Off\n\n\n");

        printf("---Scores---\n\n");
        printf(" 2 - Effacer tout les scores\n\n\n");

        printf(" 5 - Quitter");

        scanf("%d", &choix);
        optionsChoix(choix);
    } while (choix > 5);

} //En progressions


int lettre() {
    //traduit la coordonnée lettre en une valeur décimal
    char choixLettre = ' ';
    int resultat;
    printf("Entrez une lettre: ");
    fflush(stdin);
    scanf("%c", &choixLettre);
    resultat = choixLettre - 'a';
    return resultat;
}


void affiche(int tableau[10][10]) {

    //affichage de la grille
    printf("\n");
    for (int i = 1; i < 11; i++) {
        printf("%5.d", i);
        printf(" ");
    }
    printf("\n");
    printf("\n");
    for (int o = 0; o < 9; ++o) { // hauteur
        for (int i = 0; i < 62; ++i) {
            printf("%c", 219);
        }
        for (int e = 0; e < 2; ++e) { // hauteur des cases
            printf("\n%c", 219);
            for (int i = 0; i < 10; ++i) { // 10 Horizontal
                printf("%c", 219);



                //affichage des coordonnees en fonction des evenements
                switch (tableau[o][i]) {
                    case 100:
                        printf("////"); //Loupe
                        break;
                    case 0:
                        printf("%c%c%c%c", 219, 219, 219, 219); //touche
                        break;
                    default:
                        printf("    "); //Rien
                }
                printf("%c", 219);
            }
            printf("%c", 219);
            printf("%5c", o + 'A');
        }
        printf("\n");
    }
    for (int i = 0; i < 62; ++i) {
        printf("%c", 219);
    }
    printf("\n");
    printf("\n");
}


int menu() {
    int choix = 5678;

    // Affiche le menu
    while (choix < 0 || choix > 6) {
        system("cls");
        printf("______       _        _ _ _        _   _                  _      \n");
        printf("| ___ \\     | |      (_) | |      | \\ | |                | |     \n");
        printf("| |_/ / __ _| |_ __ _ _| | | ___  |  \\| | __ ___   ____ _| | ___ \n");
        printf("| ___ \\/ _` | __/ _` | | | |/ _ \\ | . ` |/ _` \\ \\ / / _` | |/ _ \\\n");
        printf("| |_/ / (_| | || (_| | | | |  __/ | |\\  | (_| |\\ V / (_| | |  __/\n");
        printf("\\____/ \\__,_|\\__\\__,_|_|_|_|\\___| \\_| \\_/\\__,_| \\_/ \\__,_|_|\\___|\n\n\n");

        printf("Bonjour ");
        //va chercher le nom d'utilisateur
        lire();
        printf("Choisissez ce que vous voulez faire : \n\n");

        printf(" 1 - Jouer\n");
        printf(" 2 - Aide du jeu\n");
        printf(" 3 - Scores\n");
        printf(" 4 - Pseudo\n");
        printf(" 5 - Options \n\n");
        printf(" 6 - Quitter\n\n");


        scanf("%d", &choix);
    }
    return choix;
}


void controles() {
    //affiche les contrôles
    int sortie = 0;
    do {
        system("cls");
        printf("_____             _             _           \n");
        printf("/  __ \\           | |           | |          \n");
        printf("| /  \\/ ___  _ __ | |_ _ __ ___ | | ___  ___ \n");
        printf("| |    / _ \\| '_ \\| __| '__/ _ \\| |/ _ \\/ __|\n");
        printf("| \\__/\\ (_) | | | | |_| | | (_) | |  __/\\__ \\\n");
        printf(" \\____/\\___/|_| |_|\\__|_|  \\___/|_|\\___||___/\n\n\n");

        printf("pour jouer il faut commencer par donner une lettre de A a I\n");
        printf("ensuite donner un chiffre entre 1 et 10\n\n\n");

        printf(" 1 - Fermer");
        scanf("%d", &sortie);
    } while (sortie != 1);
}


void regles() {
    //affiche les relges
    int sortie = 0;
    do {
        system("cls");
        printf("______           _           \n");
        printf("| ___ \\         | |          \n");
        printf("| |_/ /___  __ _| | ___  ___ \n");
        printf("|    // _ \\/ _` | |/ _ \\/ __|\n");
        printf("| |\\ \\  __/ (_| | |  __/\\__ \\\n");
        printf("\\_| \\_\\___|\\__, |_|\\___||___/\n");
        printf("            __/ |            \n");
        printf("           |___/             \n\n\n\n");


        printf(" Comment jouer :\n\n");

        printf(" Devant vous vous trouverez une grille.\n");
        printf(" vous devrez taper des coordonnees pour couler les bateaux.\n");
        printf(" Votre but est de couler tout les bateaux en un minimum de tires.\n\n");
        printf(" Vos tires loupes seront represente par :  ////\n");
        printf(" Vos tires reussis seront represente par :  %c%c%c%c \n\n\n", 219, 219, 219, 219);


        printf("  1 - fermer");
        scanf("%d", &sortie);
    } while (sortie != 1);
}


void aideChoix(int choix) {

    switch (choix) {

        case 1:
            //affiche les règles
            regles();
            break;
        case 2:
            //affiche les contrôles
            controles();
            break;
    }
}


int aideDuJeu() {
    //affiche le menu de l'aide du jeu
    int choix = 4;

    while (choix < 1 || choix > 3) {
        system("cls");
        printf("  ___  _     _            _           _            \n");
        printf(" / _ \\(_)   | |          | |         (_)           \n");
        printf("/ /_\\ \\_  __| | ___    __| |_   _     _  ___ _   _ \n");
        printf("|  _  | |/ _` |/ _ \\  / _` | | | |   | |/ _ \\ | | |\n");
        printf("| | | | | (_| |  __/ | (_| | |_| |   | |  __/ |_| |\n");
        printf("\\_| |_/_|\\__,_|\\___|  \\__,_|\\__,_|   | |\\___|\\__,_|\n");
        printf("                                    _/ |           \n");
        printf("                                   |__/            \n\n\n");

        printf(" 1 - Regles du jeu\n");
        printf(" 2 - Controles du jeu \n");
        printf(" 3 - Retour\n");

        scanf("%d", &choix);
        //va au selecteur de choix
        aideChoix(choix);
    }
    return choix;
}


void finJeu(int tires) {
    //affiche message de fin de partie
    system("cls");
    printf("_____                          _ _ \n");
    printf("|  __ \\                        | | |\n");
    printf("| |  \\/ __ _  __ _ _ __   ___  | | |\n");
    printf("| | __ / _` |/ _` | '_ \\ / _ \\ | | |\n");
    printf("| |_\\ \\ (_| | (_| | | | |  __/ |_|_|\n");
    printf(" \\____/\\__,_|\\__, |_| |_|\\___| (_|_)\n");
    printf("              __/ |                 \n");
    printf("             |___/   \n\n\n");

    printf("vous avez effectue %d tires\n\n", tires);
    //écrit la date et ce qu'il c'est passé dans l'historique
    date();
    historique();
    system("pause");

    scoresAjout();
    scoresEcriturePseudo();
    scoreEcriture(tires);
}


void jeu() {
    //écrit dans l'historique qu'une partie commence
    historiquePartie();
    int plateau, valeurUne, valeurDeux, traduction, temps = 1;
    char curseur;
    int tableau[10][10];
    //initialisation des coordonees à 0
    for (int e = 0; e < 10; ++e) {
        for (int i = 0; i < 10; ++i) {
            tableau[e][i] = 1;
        }
    }

    //pointe le fichier a lire
    FILE *plateauJeu;
    //prends un des fichier de maniere aleatoir
    srand( (unsigned)time(NULL ) );
    plateau = 1 + rand() % 3;

    switch(plateau){
        case 1:
            plateauJeu = fopen("plateaux\\plateau1.txt", "r");
            break;
        case 2:
            plateauJeu = fopen("plateaux\\plateau2.txt", "r");
            break;
        case 3:
            plateauJeu = fopen("plateaux\\plateau3.txt", "r");
            break;
    }
    //lis le fichier plateau ouvert
    if (plateauJeu != NULL) {
        do {
            fscanf(plateauJeu, "%c", &curseur);
            if (curseur != ':') {
                traduction = curseur-'0';   // prends la valeur litteral du caractere est pas sa valeur ascii
                valeurDeux = traduction;   //mémoire de la seconde coordonnee
                if (temps%2 != 1){          // regard quel est l'instant du processusse pour que les mémoires ne s'échangent pas
                    tableau[valeurUne][valeurDeux] = 5; //signal au programme qu'il y a un bateau
                }
                temps++;
                valeurUne = traduction; //mémoire de la premiere coordonnee
            }
        } while (!feof(plateauJeu));
        fclose(plateauJeu);
    }
    fclose(plateauJeu);

    //calcul si la partie est terminée ou non
    //(les bateaux représentent des point de vie que l'on enlève a chaqued fois qu'on en touche un et si la vie atteint 0 la partie se termine)
    int calcul = 0;
    for (int e = 0; e < 10; ++e) {
        for (int i = 0; i < 10; ++i) {
            if (tableau[e][i] > 1 && tableau[e][i] < 100) {
                calcul = calcul + tableau[e][i];
            }
        }
    }
    int tires = 0;

    affiche(tableau);
    //phase d'attaque
    do {
        int choixChiffre;
        int choixLettre;
        //actualise la grille
        system("cls");
        affiche(tableau);
        printf("\n");
        printf("\n");

        choixLettre = lettre();
        //récupère les coordonnées inscrites par l'utilisateur
        printf("Entrez un chiffre: ");
        fflush(stdin);
        scanf("%d", &choixChiffre);
        choixChiffre = choixChiffre - 1;
        //défini la valeur de la case visée apres quelle se soit faite attaquée
        if (tableau[choixLettre][choixChiffre] > 1 && tableau[choixLettre][choixChiffre] < 100) {
            calcul = calcul - tableau[choixLettre][choixChiffre];
            tableau[choixLettre][choixChiffre] = 0;
        }
        if (tableau[choixLettre][choixChiffre] == 1) {
            tableau[choixLettre][choixChiffre] = 100;
        }
        tires = tires + 1;
    } while (calcul > 0);
    //affiche le message de fin de partie
    finJeu(tires);
}


void menuChoix(int choix) {
    //redirige vers les differents endroits du programme
    int choixAide;
    switch (choix) {

        case 1:
            //jouer
            jeu();
            break;
        case 2:
            //affiche l'aide du jeu
            choixAide = aideDuJeu(choixAide);
            break;
        case 3:
            //affiche les scores
            afficheScore();
            break;
        case 4:
            //redifinir un pseudo
            pseudoMenu();
            break;
        case 5:
            //aller dans les options
            option();
            break;
        case 0:
            //petit easter egg dans les menus
            oeufDePaques();
            break;
    }
} //


int main() {
    //Met la console en plein écran
    COORD c;
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, &c);
    int choixMenu;
    do {
        //affiche le Menu
        choixMenu = menu();

        //redirige en fonction du choix du joueur
        if (choixMenu != 6)menuChoix(choixMenu);


    } while (choixMenu != 6);
    return 0;
}
