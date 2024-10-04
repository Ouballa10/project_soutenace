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
int x = 0;

void menu(int choix)
{
    printf("\n------------ menu ----------------------:\n");
    printf("1. ajouter une reservation\n");
    printf("2. modifier une reservation\n");
    printf("3. supprimer une reservation\n");
    printf("4. afficher les details d'une reservation\n");
    printf("5. afficher toutes les reservations\n");
    printf("6. statistique\n");
    printf("7. trier les reservations\n");
    printf("8. recherche des reservations par refrence\n");
    printf("9. recherche des reservations par nome\n");
    printf("10. quitter\n");
    printf("choisissez une option: ");
    scanf("%d", choix);
}

void afficher_menu_statut()
{
    printf("choisisez le statut:\n");
    printf("1. valide\n");
    printf("2. reporte\n");
    printf("3. annule\n");
    printf("4. traite\n");
}

void ajouter()
{
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
    switch (choix_statut)
        {
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
            printf("choix invalide statut par defaut mis a 'annule'.\n");
            strcpy(statut[x], "annule");
            break;
        }

    printf("entrez la date de reservation (yyyy-mm-dd): ");
    scanf("%s", date[x]);

    reference[x] = x + 1;
    x++;
    printf("reservation ajoutee avec succes reference: %d\n", reference[x - 1]);
}

void modifier()
{
    int ref_modif;
    printf("entrez la reference a modifier: ");
    scanf("%d", &ref_modif);

    int found = 0;
    for (int i = 0; i < x; i++)
        {
            if (reference[i] == ref_modif)
                {
                    printf("nouveau telephone: ");
                    scanf("%s", telephone[i]);
                    printf("nouvel age: ");
                    scanf("%s", age[i]);
                    printf("nouveau statut: ");
                    scanf("%s", statut[i]);
                    printf("nouvelle date: ");
                    scanf("%s", date[i]);

                    printf("Les informations ont ete mises a jour.\n");
                    found = 1;
                    break;
                }
        }
    if (!found)
        {
            printf("reservation non trouvee.\n");
        }
}

void supprimer()
{
    int ref_sup;
    printf("entrez la reference que vous souhaitez supprimer: ");
    scanf("%d", &ref_sup);

    int found = 0;
    for (int i = 0; i < x; i++)
        {
            if (reference[i] == ref_sup)
                {
                    for (int j = i; j < x - 1; j++)
                        {
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
    if (!found)
        {
            printf("reservation non trouvee.\n");
        }
}

void afficher()
{
    for (int i = 0; i < x; i++)
        {
            printf("\n---------------------------------------------\n");
            printf("reference: %d\n", reference[i]);
            printf("nom: %s\n", nom[i]);
            printf("prenom: %s\n", prenom[i]);
            printf("telephone: %s\n", telephone[i]);
            printf("age: %s\n", age[i]);
            printf("statut: %s\n", statut[i]);
            printf("date: %s\n", date[i]);
        }
}

void afficher_details_par_reference()
{
    int ref;
    printf("entrez la reference : ");
    scanf("%d", &ref);

    for (int i = 0; i < x; i++)
        {
            if (reference[i] == ref)
                {
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

void trier_par_nom()
{
    for (int i = 0; i < x - 1; i++)
        {
            for (int j = i + 1; j < x; j++)
                {
                    if (strcmp(nom[i], nom[j]) > 0)
                        {

                            char temp[50];// CHANGE
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
    printf("reservations tries par nom.\n");
}

void trier_par_statut()
{
    for (int i = 0; i < x - 1; i++)
        {
            for (int j = i + 1; j < x; j++)
                {
                    if (strcmp(statut[i], statut[j]) > 0)
                        {
                            // Swap the data
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
    printf("reservations tries par statut.\n");
}


void fakedata()
{
    char fake_nom[10][50] = {"ABDO", "ABDOD", "ChOOCC", "TELE", "TALHA", "AZIZ", "VEVE", "HIUS", "HSGD", "HDHDH"};
    char fake_prenom[10][50] = {"ZUZ", "SBDVD", "NSBD", "BBRBR", "YETRT", "UEUEUE", "TETETE", "TETEE", "HOUSSAM", "TELE"};
    char fake_telephone[10][50] = {"1234567890", "2345678901", "3456789012", "4567890123", "5678901234",
                                   "6789012345", "7890123456", "8901234567", "9012345678", "0123456789"
                                  };
    char fake_age[10][50] = {"25", "30", "22", "40", "35", "28", "50", "45", "33", "29"};
    char fake_statut[10][40]= {"valide", "reporte", "annule", "traite", "valide", "annule", "reporte", "traite", "valide", "traite"};
    char fake_date[10][50] = {"2023-01-01", "2023-02-01", "2023-03-01", "2023-04-01", "2023-05-01",
                              "2023-06-01", "2023-07-01", "2023-08-01", "2023-09-01", "2023-10-01"
                             };

    for (int i = 0; i < 10; i++)
        {
            strcpy(nom[x], fake_nom[i]);
            strcpy(prenom[x], fake_prenom[i]);
            strcpy(telephone[x], fake_telephone[i]);
            strcpy(age[x], fake_age[i]);
            strcpy(statut[x], fake_statut[i]);
            strcpy(date[x], fake_date[i]);
            reference[x] = x + 1;
            x++;
        }
}
void recherche_refrence()
{
    int ref;
    printf("entrez la reference : ");
    scanf("%d", &ref);

    for (int i = 0; i < x; i++)
        {
            if (reference[i] == ref)
                {
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
void recherche_nom()
{
    char rech_nom[50];
    printf("entrez le nom : ");
    scanf("%s", rech_nom);

    int found = 0;  // To track if any reservation is found
    for (int i = 0; i < x; i++)
        {
            if (strcmp(nom[i], rech_nom) == 0)
                {
                    printf("\n---------------------------------------------\n");
                    printf("reference: %d\n", reference[i]);
                    printf("nom: %s\n", nom[i]);
                    printf("prenom: %s\n", prenom[i]);
                    printf("telephone: %s\n", telephone[i]);
                    printf("age: %s\n", age[i]);
                    printf("statut: %s\n", statut[i]);
                    printf("date: %s\n", date[i]);
                    found = 1;  // Mark as found
                }
        }
    if (!found)
        {
            printf("reservation non trouvee.\n");
        }
}



int main()
{
    fakedata();

    int choix;
    while (1)
        {
            menu(&choix);
            switch (choix)
                {
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
                    break;
                case 6:

                    break;
                case 7:
                    printf("1. trier par nom\n2. trier par statut\n");
                    int tri_choix;
                    scanf("%d", &tri_choix);
                    if (tri_choix == 1)
                        {
                            trier_par_nom();
                        }
                    else if (tri_choix == 2)
                        {
                            trier_par_statut();
                        }
                    else
                        {
                            printf("choix invalide.\n");
                        }
                    break;
                case 8:
                    recherche_refrence() ;

                    break;
                case 9:
                    recherche_nom() ;

                    break;
                case 10:
                    printf("quitter le programme.\n");
                    exit(0);
                default:
                    printf("choix invalide, reessayez.\n");
                    break;
                }
        }

    return 0;
}
