#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#pragma execution_character_set("utf-8")


int menu(int choix) {
    choix = 6;

    // Affiche le menu
    while (choix < 1 || choix > 5) {
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
        printf(" 3 - Scores\n");
        printf(" 4 - Pseudo\n");
        printf(" 5 - Quitter\n\n");

        scanf("%d", &choix);
    }
    return choix;
}

void aideChoix(int choix) {


    switch (choix) {

        case 1:
            system("Regles\\cmake-build-debug\\Regles.exe");
        case 2:

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

    printf(" 1 - Règles du jeu\n");
    printf(" 2 - Contrôles du jeu\n");
    printf(" 3 - Retour\n");

    scanf("%d",&choix);
    aideChoix(choix);
    }
    return choix;
}

int menuChoix(int choix) {

    int choixAide;
    switch (choix) {

        case 1:
            return 0;
            break;
        case 2:
            //affiche l'aide du jeu
            choixAide = aideDuJeu(choixAide);
            break;
        case 3:
            return 0;
            break;
        case 4:
            return 0;
            break;
    }
}

int main() {

    int choixMenu;

    do {
        SetConsoleOutputCP(65001);
        //affiche le Menu
        choixMenu = menu(choixMenu);

        //redirige en fonction du choix du joueur
        menuChoix(choixMenu);


    } while (choixMenu != 5);
    return 0;
}