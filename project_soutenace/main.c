#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char nom[100][50];
char prenom[100][50];
char telephone[100][50];
char age[100][50];
char statut[100][40];
char date[100][50];
int reference[100];
int x = 10;
int choix;

void menu( choix) {
    printf("\n------------ menu ----------------------:\n");
    printf("1. ajouter une reservation\n");
    printf("2. modifier une reservation\n");
    printf("3. supprimer une reservation\n");
    printf("4. afficher les details d'une reservation\n");
    printf("5. afficher toute les reservations\n");
    printf("6. statistique\n");
    printf("7. trier les reservations\n");
    printf("8. recherche des reservation\n");
    printf("9. quitter\n");
    printf("choisiez une option: ");
    scanf("%d",choix);
}
void afficher_menu_statut() {
    printf("Choisissez le statut:\n");
    printf("1. valide\n");
    printf("2. reporte\n");
    printf("3. annule\n");
    printf("4. traite\n");
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

    afficher_menu_statut();
    int choix_statut;
    printf("choisissez une option: ");
    scanf("%d", &choix_statut);
    switch (choix_statut) {
        case 1:
            strcpy(statut[x], "valide");
            break;
        case 2:
            strcpy(statut[x], "reporte");
            break;
        case 3:
            strcpy(statut[x], "annule");
            break;
        case 4:
            strcpy(statut[x], "traite");
            break;
        default:
            printf("choix invalide. statut par defaut mis a 'annule'.\n");
            strcpy(statut[x], "annule");
            break;
    }

    printf("entrez la date de reservation (yyyy-mm-dd): ");
    scanf("%s", date[x]);

    reference[x] = x + 1;
    x++;
    printf("reservation ajoutee avec succes. reference: %d\n", reference[x - 1]);
}


void modifier() {
    int ref_modif;
    printf("entrez la reference a modifier: ");
    scanf("%d", &ref_modif);

    int found = 0;
    for (int i = 0; i < x; i++) {
        if (reference[i] == ref_modif) {
           /* printf("nouveau nom: ");
            scanf("%s", nom[i]);
            printf("nouveau prenom: ");
            scanf("%s", prenom[i]);*/
            printf("nouveau telephone: ");
            scanf("%s", telephone[i]);
            printf("nouvel age: ");
            scanf("%s", age[i]);
            printf("nouveau statut: ");
            scanf("%s", statut[i]);
            printf("nouvelle date: ");
            scanf("%s", date[i]);

            printf("les informations ont ete mises a jour.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("reservation non trouvee.\n");
    }
}

void supprimer() {
    int ref_sup;
    printf("entrez la reference que vous souhaitez supprimer: ");
    scanf("%d", &ref_sup);

    int found = 0;
    for (int i = 0; i < x; i++) {
        if (reference[i] == ref_sup) {
            for (int j = i; j < x - 1; j++) {
                strcpy(nom[j], nom[j + 1]);
                strcpy(prenom[j], prenom[j + 1]);
                strcpy(telephone[j], telephone[j + 1]);
                strcpy(age[j], age[j + 1]);
                strcpy(statut[j], statut[j + 1]);
                strcpy(date[j], date[j + 1]);
                reference[j] = reference[j + 1];
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

void afficher() {
    for (int i = 0; i < x; i++) {
        printf("\n---------------------------------------------\n");
        printf("reference: %d\n", reference[i]);
        printf("nom: %s\n", nom[i]);
        printf("prenom: %s\n", prenom[i]);
        printf("telephone: %s\n", telephone[i]);
        printf("age: %s\n", age[i]);
        printf("statut: %s\n", statut[i]);
        printf("date: %s\n", date[i]);
    }
    fakedata() ;
}

void afficher_details_par_reference() {
    int ref;
    printf("entrez la reference : ");
    scanf("%d", &ref);

    for (int i = 0; i < x; i++) {
        if (reference[i] == ref) {
            printf("\n---------------------------------------------\n");
            printf("reference: %d\n", reference[i]);
            printf("nom: %s\n", nom[i]);
            printf("prenom: %s\n", prenom[i]);
            printf("telephone: %s\n", telephone[i]);
            printf("age: %s\n", age[i]);
            printf("statut: %s\n", statut[i]);
            printf("date: %s\n", date[i]);
            return;
        }
    }
    printf("reservation non trouvee.\n");
}

void trier_par_nom() {
    for (int i = 0; i < x - 1; i++) {
        for (int j = i + 1; j < x; j++) {
            if (strcmp(nom[i], nom[j]) > 0) {
                char temp[50];
                strcpy(temp, nom[i]);
                strcpy(nom[i], nom[j]);
                strcpy(nom[j], temp);

                strcpy(temp, prenom[i]);
                strcpy(prenom[i], prenom[j]);
                strcpy(prenom[j], temp);

                strcpy(temp, telephone[i]);
                strcpy(telephone[i], telephone[j]);
                strcpy(telephone[j], temp);

                strcpy(temp, age[i]);
                strcpy(age[i], age[j]);
                strcpy(age[j], temp);

                strcpy(temp, statut[i]);
                strcpy(statut[i], statut[j]);
                strcpy(statut[j], temp);

                strcpy(temp, date[i]);
                strcpy(date[i], date[j]);
                strcpy(date[j], temp);

                int temp_ref = reference[i];
                reference[i] = reference[j];
                reference[j] = temp_ref;
            }
        }
    }
    printf("reservations triees par nom.\n");
}

void trier_par_statut() {
    for (int i = 0; i < x - 1; i++) {
        for (int j = i + 1; j < x; j++) {
            if (strcmp(statut[i], statut[j]) > 0) {
                char temp[50];
                strcpy(temp, nom[i]);
                strcpy(nom[i], nom[j]);
                strcpy(nom[j], temp);

                strcpy(temp, prenom[i]);
                strcpy(prenom[i], prenom[j]);
                strcpy(prenom[j], temp);

                strcpy(temp, telephone[i]);
                strcpy(telephone[i], telephone[j]);
                strcpy(telephone[j], temp);

                strcpy(temp, age[i]);
                strcpy(age[i], age[j]);
                strcpy(age[j], temp);

                strcpy(temp, statut[i]);
                strcpy(statut[i], statut[j]);
                strcpy(statut[j], temp);

                strcpy(temp, date[i]);
                strcpy(date[i], date[j]);
                strcpy(date[j], temp);

                int temp_ref = reference[i];
                reference[i] = reference[j];
                reference[j] = temp_ref;
            }
        }
    }
    printf("reservations triees par statut.\n");
}

void calculer_moyenne_age() {
    int total_age = 0;
    for (int i = 0; i < x; i++) {
        total_age += atoi(age[i]);
    }
    if (x > 0) {
        printf("moyenne d'age des patients: %.2f ans.\n", (float)total_age / x);
    } else {
        printf("aucune reservation disponible pour calculer la moyenne d'age.\n");
    }
}

void compter_patients_par_tranche_age() {
    int count_0_18 = 0, count_19_35 = 0, count_36_plus = 0;
    for (int i = 0; i < x; i++) {
        int age_int = atoi(age[i]);
        if (age_int <= 18) {
            count_0_18++;
        } else if (age_int <= 35) {
            count_19_35++;
        } else {
            count_36_plus++;
        }
    }
    printf("nombre de patients (0-18 ans): %d\n", count_0_18);
    printf("nombre de patients (19-35 ans): %d\n", count_19_35);
    printf("nombre de patients (36+ ans): %d\n", count_36_plus);
}

void compter_reservations_par_statut() {
    int count_valide = 0, count_reporte = 0, count_annule = 0, count_traite = 0;
    for (int i = 0; i < x; i++) {
        if (strcmp(statut[i], "valide") == 0) {
            count_valide++;
        } else if (strcmp(statut[i], "reporte") == 0) {
            count_reporte++;
        } else if (strcmp(statut[i], "annule") == 0) {
            count_annule++;
        } else if (strcmp(statut[i], "traite") == 0) {
            count_traite++;
        }
    }
    printf("reservations validees: %d\n", count_valide);
    printf("reservations reporte: %d\n", count_reporte);
    printf("reservations annulees: %d\n", count_annule);
    printf("reservations traitees: %d\n", count_traite);
}

int main() {


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
                afficher_details_par_reference();
                break;
            case 5:
                afficher();
                fakedata() ;

                break;
            case 6:
                calculer_moyenne_age();
                compter_patients_par_tranche_age();
                compter_reservations_par_statut();
                break;
            case 7:
                printf("1. trier par nom\n2. trier par statut\n");
                int tri_choix;
                scanf("%d", &tri_choix);
                if (tri_choix == 1) {
                    trier_par_nom();
                } else if (tri_choix == 2) {
                    trier_par_statut();
                } else {
                    printf("choix invalide.\n");
                }
                break;
            case 8:
                printf("1. recherche par reference\n2. recherche par nom\n");
                int recherche_choix;
                scanf("%d", &recherche_choix);
                if (recherche_choix == 1) {
                    afficher_details_par_reference();
                } else if (recherche_choix == 2) {
                    char nom_recherche[50];
                    printf("entrez le nom a rechercher: ");
                    scanf("%s", nom_recherche);
                    for (int i = 0; i < x; i++) {
                        if (strcmp(nom[i], nom_recherche) == 0) {
                            printf("\nreference: %d, nom: %s, prenom: %s, telephone: %s, age: %s, statut: %s, date: %s\n",
                                   reference[i], nom[i], prenom[i], telephone[i], age[i], statut[i], date[i]);
                        }
                    }
                } else {
                    printf("choix invalide.\n");
                }
                break;
            case 9:
                printf("quitter le programme.\n");
                exit(0);
            default:
                printf("choix invalide, reessayez.\n");
                break;
        }
    }

    return 0;
}

void fakedata() {
    char nom[100][50] = {"ABDO", "ABDOD", "ChOOCC", "TELE", "TALHA", "AZIZ", "VEVE", "HIUS", "HSGD", "HDHDH"};
    char prenom[100][50] = {"ZUZ", "SBDVD", "NSBD", "BBRBR", "YETRT", "UEUEUE", "TETETE", "TETEE", "HOUSSAM", "TELE"};
   char telephone[100][50] = {"1234567890", "2345678901", "3456789012", "4567890123", "5678901234",
                                "6789012345", "7890123456", "8901234567", "9012345678", "0123456789"};
    char age[100][50] = {"25", "30", "22", "40", "35", "28", "50", "45", "33", "29"};
    char statut[100][40]= {"valide", "reporte", "annule", "traite", "valide", "annule", "reporte", "traite", "valide", "traite"};
    char date[100][50] = {"2023-01-01", "2023-02-01", "2023-03-01", "2023-04-01", "2023-05-01",
                           "2023-06-01", "2023-07-01", "2023-08-01", "2023-09-01", "2023-10-01"};
    int reference[100]= {1,2,3,4,5,6,7,8,9,10};



    x = 10; // Set the count of current reservations to 10
}






