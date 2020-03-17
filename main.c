#include <stdio.h>
#include <stdlib.h>
#include <rpc.h>
#include <string.h>

void lire(){
    FILE* fichier = NULL;
    int caractereActuel = 0;

    fichier = fopen("pseudo.txt", "r");

    if (fichier != NULL)
    {
        // Boucle de lecture des caractères un à un
        do
        {
            caractereActuel = fgetc(fichier); // On lit le caractère
            printf("%c", caractereActuel); // On l'affiche
        } while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)

        fclose(fichier);
    }
}

/**void creerPseudo(){
}
*/
void fenetre() {
    keybd_event(VK_MENU, 0x38, 0, 0);
    keybd_event(VK_RETURN, 0x1c, 0, 0);
    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}

void pseudoSuggere() {
        char user[255];
        strcpy(user, getenv("username"));

        //pointe le fichier a modifier
        FILE *fptr;
        if (fptr == NULL) {
            printf("Error!");
            exit(1);
        }
        //ouvre le fichier et ecrit le nom de lu joueur
        fptr = fopen("pseudo.txt", "w");
        fprintf(fptr, "%s ", user);
        fclose(fptr);
}

void choixPseudo(int choix){

    switch(choix){
        case 2:
            pseudoSuggere();
            break;
    }
}

int pseudoMenu(){

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

        printf(" 1 - Definir un pseudo par defaut\n");
        printf(" 2 - Pseudo suggere\n\n");

        printf(" 3 - fermer");

        scanf("%d",&choix);
    }while(choix < 1 || choix > 3);
    choixPseudo(choix);
}

void space(int i) {
    for (int e = 0; e < i; e++) {
        printf(" ");
    }
}

void pleinEcran() {
    COORD c;
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_WINDOWED_MODE, &c);
}

void easterEgg() {
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

        printf(" 1 - Jouer \n");
        printf(" 2 - Aide du jeu\n");
        printf(" 3 - Scores  (Prochainement)\n");
        printf(" 4 - Pseudo (Prochainement)\n");
        printf(" 5 - Options (Prochainement)\n");
        printf(" 6 - Quitter\n\n");

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

void option() {

    int choix = 10;
    do {
        system("cls");
        printf("---Affichage---\n\n");

        printf(" 1 - Plein ecran\n");
        printf(" 2 - Fenetre\n\n");

        printf(" 5 - Quitter");

        scanf("%d", &choix);

        switch (choix) {
            case 1:
                pleinEcran();
            case 2:
                fenetre();
        }
    } while (choix > 5);

} //En progressions

int lettre() {
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
        lire();
        printf("Choisissez ce que vous voulez faire : \n\n");

        printf(" 1 - Jouer \n");
        printf(" 2 - Aide du jeu\n");
        printf(" 3 - Scores  (Prochainement)\n");
        printf(" 4 - Pseudo (Prochainement)\n");
        printf(" 5 - Options (Prochainement)\n");
        printf(" 6 - Quitter\n\n");


        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("                                             .\n");
        printf("                           .                 |\n");
        printf("                           +                 |\n");
        printf("                  .        |                *+W+-*\n");
        printf("     .           +y        +W+              . H                 .\n");
        printf("  .  +y            |I.   y  |               ! H= .           .  ^\n");
        printf("  !   \\     .     |H '. /   |  ___.        .! H  !   +--.--y !  V\n");
        printf("  !    \\     \\  +=|H|=='.=+ | |====\\   _  '_H_H__H_. H_/=  J !  !\n");
        printf(". !     \\'    VVV_HHH_/__'._H |  E  \\_|=|_|========|_|==|____H. ! _______.\n");
        printf("I-H_I=I=HH_==_|I_IIIII_I_I_=HH|======.I-I-I-=======-I=I=I=I_=H|=H'===I=I/\n");
        printf("\\                                                                      ,\n");
        printf(" |                                                                    /\n");
        printf(" .___________________________________________________________________'\n");
        printf("\n\n\n\n\n");
        scanf("%d", &choix);
    }
    return choix;
}

void controles() {
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
            regles();
            break;
        case 2:
            controles();
            break;
    }
}

int aideDuJeu() {
    //affiche l'aide du jeu
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
        aideChoix(choix);
    }
    return choix;
}

void finJeu(int tires) {

    system("cls");
    printf("_____                          _ _ \n");
    printf("|  __ \\                        | | |\n");
    printf("| |  \\/ __ _  __ _ _ __   ___  | | |\n");
    printf("| | __ / _` |/ _` | '_ \\ / _ \\ | | |\n");
    printf("| |_\\ \\ (_| | (_| | | | |  __/ |_|_|\n");
    printf(" \\____/\\__,_|\\__, |_| |_|\\___| (_|_)\n");
    printf("              __/ |                 \n");
    printf("             |___/   \n\n\n");

    printf("vous avez effectue %d tires", tires);

    system("pause");
}

void jeu() {

    int tableau[10][10];
    //initialisation des coordonees
    for (int e = 0; e < 10; ++e) {
        for (int i = 0; i < 10; ++i) {
            tableau[e][i] = 1;
        }
    }

    //mise en place des tableaux                //x y         x = lettre     y = chiffre
    tableau[5][5] = 2;
    tableau[5][6] = 2;

    tableau[3][1] = 2;
    tableau[4][1] = 2;

    tableau[1][6] = 3;
    tableau[1][7] = 3;
    tableau[1][8] = 3;

    tableau[6][9] = 3;
    tableau[7][9] = 3;
    tableau[8][9] = 3;

    tableau[0][3] = 4;
    tableau[1][3] = 4;
    tableau[2][3] = 4;
    tableau[3][3] = 4;

    tableau[7][1] = 5;
    tableau[7][2] = 5;
    tableau[7][3] = 5;
    tableau[7][4] = 5;
    tableau[7][5] = 5;

    int calcul = 0;
    for (int e = 0; e < 10; ++e) {
        for (int i = 0; i < 10; ++i) {
            if (tableau[e][i] > 1 && tableau[e][i] < 100) {
                calcul = calcul + tableau[e][i] + 10;
            }
        }
    }
    int tires = 0;
    calcul -= 190;
    affiche(tableau);
    do {
        int choixChiffre;
        int choixLettre;
        system("cls");
        affiche(tableau);
        printf("\n");
        printf("\n");

        choixLettre = lettre();

        printf("Entrez un chiffre: ");
        fflush(stdin);
        scanf("%d", &choixChiffre);
        choixChiffre = choixChiffre - 1;
        if (tableau[choixLettre][choixChiffre] > 1 && tableau[choixLettre][choixChiffre] < 100) {
            calcul = calcul - tableau[choixLettre][choixChiffre];
            tableau[choixLettre][choixChiffre] = 0;
        }
        if (tableau[choixLettre][choixChiffre] == 1) {
            tableau[choixLettre][choixChiffre] = 100;
        }
        tires = tires + 1;
    } while (calcul > 0);
    finJeu(tires);
}

int menuChoix(int choix) {

    int choixAide;
    switch (choix) {

        case 1:
            jeu();
            break;
        case 2:
            //affiche l'aide du jeu
            choixAide = aideDuJeu(choixAide);
            break;
        case 4:
            pseudoMenu();
            break;
        case 5:
            option();
            break;
        case 0:
            easterEgg();
            break;
    }
    return 0;
}

int main() {
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