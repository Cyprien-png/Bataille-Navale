#include <stdio.h>
#include <stdlib.h>
#include <rpc.h>

void fenetre() {
    keybd_event(VK_MENU,0x38,0,0);
    keybd_event(VK_RETURN,0x1c,0,0);
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

void easterEgg(){
    system("cls");
    printf("______       _        _ _ _        _   _                  _      \n");
    printf("| ___ \\     | |      (_) | |      | \\ | |                | |     \n");
    printf("| |_/ / __ _| |_ __ _ _| | | ___  |  \\| | __ ___   ____ _| | ___ \n");
    printf("| ___ \\/ _` | __/ _` | | | |/ _ \\ | . ` |/ _` \\ \\ / / _` | |/ _ \\\n");
    printf("| |_/ / (_| | || (_| | | | |  __/ | |\\  | (_| |\\ V / (_| | |  __/\n");
    printf("\\____/ \\__,_|\\__\\__,_|_|_|_|\\___| \\_| \\_/\\__,_| \\_/ \\__,_|_|\\___|\n\n\n");

    printf("Bonjour joueur, Choisissez ce que vous voulez faire : \n\n");

    printf(" 1 - Jouer \n");
    printf(" 2 - Aide du jeu\n");
    printf(" 3 - Scores  (Prochainement)\n");
    printf(" 4 - Pseudo (Prochainement)\n");
    printf(" 5 - Options (Prochainement)\n");
    printf(" 6 - Quitter\n\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("ici?");
    system("pause");
}

void pleinEcran() {
    COORD c;
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_WINDOWED_MODE, &c);
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
                    case 1:
                        printf("    "); //Rien
                        break;
                    case 2:
                        printf("2222"); //bateau de 2
                        break;
                    case 3:
                        printf("3333"); //bateau de 3
                        break;
                    case 4:
                        printf("4444"); //bateau de 4
                        break;
                    case 5:
                        printf("5555"); //bateau de 5
                        break;
                    case 100:
                        printf("////"); //Loupe
                        break;
                    case 8:
                        printf("%c%c%c%c", 219, 219, 219, 219); //Coule
                        break;
                    default:
                        printf("%c%c%c%c", 219, 219, 219, 219);
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

        printf("Bonjour joueur, Choisissez ce que vous voulez faire : \n\n");

        printf(" 1 - Jouer \n");
        printf(" 2 - Aide du jeu\n");
        printf(" 3 - Scores  (Prochainement)\n");
        printf(" 4 - Pseudo (Prochainement)\n");
        printf(" 5 - Options (Prochainement)\n");
        printf(" 6 - Quitter\n\n");

        scanf("%d", &choix);
    }
    return choix;
}

void controles(){
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
        scanf("%d",&sortie);
    }while(sortie != 1);
}

void regles(){
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
        printf(" Vos tires reussis seront represente par :  %c%c%c%c \n\n\n",219,219,219,219);


        printf("  1 - fermer");
        scanf("%d",&sortie);
    }while(sortie != 1);
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