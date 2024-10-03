#include <stdio.h>
#include <stdlib.h>
#include <string.h>
       char nom [100][50];
       char prenom [100][50];
       char telephone [100][50];
       char age [100][50];
       char statut[100][40];
       int reference =0 ;
       char date[100];
       char nom_modi [100];
       int x=0;
       int i;
        int choix;
        char nom_sup ;
        int S =0;

void menu (){

        printf("\n------------MENU----------------------:\n");
        printf("1. ajouter une reservation\n");
        printf("2. modifier une reservation\n");
        printf("3. supprimer une reservation\n");
        printf("4. afficher les details d'une reservation\n");
        printf("5. afficher toutes les reservations\n");
        printf("6. statistiques\n");
        printf("7. quitter\n");
        printf("choisez une choix: ");
        scanf("%d", &choix);

}
void ajouter()
{
    printf("entrez les information suivent pour nouvelle réservation :\n ");

    printf("Entrez le nom: ");
    scanf("%s",&nom[x]);
    printf("Entrez le prenom: ");
    scanf("%s",&prenom[x]);
    printf("Entrez le telephone: ");
    scanf("%s",&telephone);
    printf("Entrez l'age: ");
    scanf("%s",&age);
    printf("Entrez le statut (valide, reporte, annule, trait): ");
    scanf("%s",&statut);
    reference = x+ 1;
    printf("Entrez la date de réservation (yyy-mm-dd): ");
    scanf("%s", &date);
    x++;
}
void modifier()
{
    int reference ;
    char nom_modi ;
    printf("entrez le nom  or referance que vous souhaitez a modifier :\n");
    printf("Nom : ");
    printf("entrez SVP  refrence  ou nom:\n");

    scanf("%s""%s",reference,nom);
    printf("entrez de nouvelies informations :\n");
     int T=0;
    for(int i=0;i<x;i++)
    {
        if(strcmp( nom_modi ,nom[x])==0 || reference<x)
        {
             printf("Nouveau nom : ");
            scanf("%s",&nom[i]);
             printf("Nouveau prenom : ");
            scanf("%s",&prenom[i]);
            printf("Nouveau telephone : ");
            scanf("%s",&telephone[i]);
            printf("Nouveau age : ");
            scanf("%s",&age[i]);
            printf("Nouveau statut : ");
            scanf("%s",&statut[i]);
            printf("Nouveau date : ");
            scanf("%s",&date[i]);
            printf("les informations a bien  mise ajoure");
            T++;
        }
    }
    if(T==0)printf("le nom no trouve pas");
}
void afichage()
{
    for (int i=0;i<x;i++)
    {
        printf("\n---------------------------------------------\n");

        printf("*Nom : %s\n",nom);
        printf("*prenom : %s\n",prenom);
        printf("*telephone : %s\n",telephone);
        printf("*age : %s\n",age);
        printf("*statut : %s\n",statut);
        printf("*date : %s\n",date);
    }
}
void supprimer()
{
    printf("entrez le  reference quevous souhaitez superimer :\n");
    printf("Nom : ");
    scanf("%s",nom_sup);
    for(int i=0;i<x;i++)
    {
        if(strcmp(nom_sup,nom[i])==0)
        {
            strcpy(nom[i],nom[i-1]);
            strcpy(prenom[i],prenom[i-1]);
            strcpy(telephone[i],telephone[i-1]);
            strcpy(age[i],age[i-1]);
            strcpy(statut[i],statut[i-1]);
            strcpy(date[i],date[i-1]);
            x--;
            S++;
            printf("element bien superimer");

        }
    }
        if (S==0){printf("element non trouver");}
}



int main()
{
    debu :

    menu () ;


   switch (choix){
   case 1 :
       ajouter() ;
       goto debu ;

    break ;
    case 2 :
       modifier () ;
       goto debu ;
    break ;
    case 3 :
       supprimer () ;
       goto debu ;
    break ;
    case 4 :
       afichage () ;
    goto debu ;
    break ;





   }







    return 0;
}
