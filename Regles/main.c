#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#pragma execution_character_set("utf-8")


int main() {
    int sortie = 0;
    SetConsoleOutputCP(65001);
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


        printf("  ----- Début de partie -----\n\n");

        printf(" Au début de la partie le joueur doit placer ses bateaux.\n\n");

        printf("  ----- Déroulement de la partie -----\n\n");

        printf(" Une fois fait il doit choisir quelle case de l'adversaire qu'il décide d'attaquer.\n");
        printf(" L'ordinateur attaque ensuite le joueur.\n");
        printf(" si le joueur ou l'ordi ne touche pas un bateau de l'autre alors c'est 'Loupé !!'.\n");
        printf(" si le joueur ou l'ordi touche un bateau de l'autre alors c'est 'Touché !!'.\n");
        printf(" si le joueur ou l'ordi touche le dernier morceau de bateau de l'autre alors c'est 'Coulé !!'.\n\n");

        printf("  ----- Fin de partie -----\n\n");

        printf(" Pour gagner la partie il faut couler tout les joueurs de l'adversaire.\n\n\n");

        printf("  1 - fermer");
        scanf("%d",&sortie);
    }while(sortie != 1);
 return 0;
}