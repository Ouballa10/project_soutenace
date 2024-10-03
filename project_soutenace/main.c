#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char nom[100][50];
char prenom[100][50];
char telephone[100][50];
char age[100][50];
char statut[100][40];
char date[100][50];
int reference = 0;
int x = 0;
char nom_sup[50];

void menu(int *choix) {
    printf("\n------------ menu ----------------------:\n");
    printf("1. ajouter une reservation\n");
    printf("2. modifier une reservation\n");
    printf("3. supprimer une reservation\n");
    printf("4. afficher les details d'une reservation\n");
    printf("5. statistiques\n");
    printf("6. trier les réservations\n");
    printf("7. quitter\n");
    printf("choisissez une option: ");
    scanf("%d", choix);
}

void ajouter() {
    printf("entrez les informations suivantes pour une nouvelle reservation:\n");

    printf("entrez le nom: ");
    scanf("%s", nom[x]);
    printf("entrez le prenom: ");
    scanf("%s", prenom[x]);
    printf("entrez le telephone: ");
    scanf("%s", telephone[x]);
    printf("entrez l'age: ");
    scanf("%s", age[x]);
    printf("entrez le statut (valide, reporte, annule, traite): ");
    scanf("%s", statut[x]);
    printf("entrez la date de reservation (yyyy-mm-dd): ");
    scanf("%s", date[x]);

    reference = x + 1;
    x++;
}

void modifier() {
    char nom_modi[50];
    int found = 0;

    printf("entrez le nom ou la reference a modifier: ");
    scanf("%s", nom_modi);

    for (int i = 0; i < x; i++) {
        if (strcmp(nom_modi, nom[i]) == 0) {
            printf("nouveau nom: ");
            scanf("%s", nom[i]);
            printf("nouveau prenom: ");
            scanf("%s", prenom[i]);
            printf("nouveau telephone: ");
            scanf("%s", telephone[i]);
            printf("nouvel age: ");
            scanf("%s", age[i]);
            printf("nouveau statut: ");
            scanf("%s", statut[i]);
            printf("nouvelle date: ");
            scanf("%s", date[i]);

            printf("les informations ont ete bien mises a jour.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("reservation non trouvee.\n");
    }
}

void afficher() {
    for (int i = 0; i < x; i++) {
        printf("\n---------------------------------------------\n");
        printf("nom: %s\n", nom[i]);
        printf("prenom: %s\n", prenom[i]);
        printf("telephone: %s\n", telephone[i]);
        printf("age: %s\n", age[i]);
        printf("statut: %s\n", statut[i]);
        printf("date: %s\n", date[i]);
    }
}

void supprimer() {
    printf("entrez le nom que vous souhaitez supprimer: ");
    scanf("%s", nom_sup);

    int found = 0;
    for (int i = 0; i < x; i++) {
        if (strcmp(nom_sup, nom[i]) == 0) {
            for (int j = i; j < x - 1; j++) {
                strcpy(nom[j], nom[j + 1]);
                strcpy(prenom[j], prenom[j + 1]);
                strcpy(telephone[j], telephone[j + 1]);
                strcpy(age[j], age[j + 1]);
                strcpy(statut[j], statut[j + 1]);
                strcpy(date[j], date[j + 1]);
            }
            x--;
            found = 1;
            printf("reservation supprimee avec succes.\n");
            break;
        }
    }
    if (!found) {
        printf("reservation non trouvee.\n");
    }
}

int main() {
    int choix;
    while (1) {
        menu(&choix);
        switch (choix) {
            case 1:
                ajouter();
            break;
            case 2:
                modifier();
            break;
            case 3:
                supprimer();
            break;
            case 4:
                afficher();
            break;
            case 5 :
            break ;
            case 6 :
            break ;

            case 7:
                printf("quitter le programme.\n");
                exit(0);
            default:
                printf("choix invalide, reessayez.\n");
                break;
        }
    }
    return 0;
}
