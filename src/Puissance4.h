#include <stdio.h>
#include <stdlib.h>
#include "ordi.h"

typedef struct Pos
{
    int x;
    int y;

}Pos;

int chargement(int **plateau, int *joueur, int *couleurJ1,char save[])
{
    int i = 0, j = 0,v;
    FILE *f = fopen(save, "r");
    if(f != NULL) {
        while(j<6 || i!=0){
            fscanf(f,"%d",&v);
            /*
            printf("\nFgetc = %c",fgetc(f));
            printf("\nFscanf = %d",v);
            */
            plateau[i][j]=v;
            i++;
            if(i==9){
                j++;
                i=0;
            }
        }
        //fseek(f,7,SEEK_CUR);
        fscanf(f,"%d",joueur);
        fscanf(f,"%d",couleurJ1);
        fscanf(f,"%d",&i);
        fclose(f);
        return i;
    }
    //fprintf(stderr, "Erreur a l’ouverture du fichier\n");
    return -1;
}

int chargementcoor(Pos **coor)
{
    char save[] = "coor.txt";
    int i = 0, j = 0,v;
    FILE *f = fopen(save, "r");
    if(f != NULL) {
        while(j<6 || i!=0){
            fscanf(f,"%d",&v);
            coor[i][j].x=v;
            fscanf(f,"%d",&v);
            coor[i][j].y=v;
            i++;
            if(i==9){
                j++;
                i=0;
            }
        }
        fclose(f);
        return 1;
    }
    return 0;
}

int sauvegarde(int **plateau, int joueur, int couleurJ1,int h,char save[])
{
    int i = 0, j = 0;
    FILE *f = fopen(save, "w");
    if(f != NULL) {
        while(j<6 || i!=0){
            fprintf(f,"%d ",plateau[i][j]);
            i++;
            if(i==9){
                j++;
                i=0;
                fputs("\n",f);
            }
        }
        fprintf(f,"%d\n",joueur);
        fprintf(f,"%d\n",couleurJ1);
        fprintf(f,"%d",h);
        fclose(f);
        return i;
    }
    printf("\nErreur a l’ouverture du fichier\n");
    return -1;
}

int reprendre1(char save[])
{
    //si save existe alors renvoie 1;
    int c;
    FILE *f = NULL;
    f=fopen(save,"r");
    if(f!=NULL){
        fclose(f);
        return 1;
    }else return 0;
}

void initialisation (int **plateau)
{
    int i,j;
    for (i=0; i < 9; i++){
        for (j=0; j < 6; j++){
            plateau[i][j]=0;
        }
    }
}

int remplir (int **plateau, int couleur, int colonne)
{
    int ligne=0;
    while(plateau[colonne][ligne]==0 && ligne<6){
        ligne++;
    }
    if(ligne>0){
        ligne--;
        plateau[colonne][ligne]=couleur;

        return 0;

    }else {

        return 1;}
}

void affichage(int **plateau){
    int i,j;
    printf("\n");
    for (j=0; j<6; j++){
        for (i=0; i<9; i++){
            printf("%d ",plateau[i][j]);
        }
        printf("\n");
    }
}

int pileouface(){
    srand(time(NULL));
    int piece=(rand()%2);
    if (piece==0){
        printf("\nLe J1 est le jaune");
        return 2;
    }
    else{
        printf("\nLe J1 est le rouge");
        return 1;
    }
}

int victoire(int **plateau, int couleur){
    //ne detecte pas les colonne ne haut
    int i,j;
    for (i=0; i<9; i++){
        for (j=0; j<6; j++){
            if (plateau[i][j]==couleur && plateau[i][j+1]==couleur && plateau[i][j+2]==couleur && plateau[i][j+3]==couleur){
                return 1;
            }
            if(i<6){
                if(plateau[i][j]==couleur && plateau[i+1][j]==couleur && plateau[i+2][j]==couleur && plateau[i+3][j]==couleur){
                    return 1;
                }
                if(j>2){
                    if(plateau[i][j]==couleur && plateau[i+1][j-1]==couleur && plateau[i+2][j-2]==couleur && plateau[i+3][j-3]==couleur){
                        return 1;
                    }
                }
                if(j<3){
                    if(plateau[i][j]==couleur && plateau[i+1][j+1]==couleur && plateau[i+2][j+2]==couleur && plateau[i+3][j+3]==couleur){
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int jvsj1 (int **plateau,int couleur1,int couleur2,int joueur, int colonne)
{
    int v;
    if(joueur==1){
            v=remplir(plateau,couleur1,colonne);
            sauvegarde(plateau,2,couleur1,-1,"save2J.txt");
            return v;
        }
    else {
            v=remplir(plateau,couleur2,colonne);
            sauvegarde(plateau,1,couleur1,-1,"save2J.txt");
            return v;
        }
}

void jvsb1(int **plateau,int c,int couleur,int couleurbot, int joueur, int colonne)
{
    int v;
    if (joueur==1){
        switch(c)
        {
        case 1:
            sauvegarde(plateau,1,couleur,c,"saveBot.txt");
            v=remplir(plateau,couleur,colonne);
            if(victoire(plateau,couleur)==0 && v==0){
                sauvegarde(plateau,2,couleur,c,"saveBot.txt");
                facile(plateau,couleurbot);
                sauvegarde(plateau,1,couleur,c,"saveBot.txt");
            }
        break;

        case 2:
            sauvegarde(plateau,1,couleur,c,"saveBot.txt");
            v=remplir(plateau,couleur,colonne);
            if(victoire(plateau,couleur)==0 && v==0){
                sauvegarde(plateau,2,couleur,c,"saveBot.txt");
                normal(plateau,couleurbot);
                sauvegarde(plateau,1,couleur,c,"saveBot.txt");
            }
        break;

        default : printf("\nMode de jeu indisponible !!");
        }
    }else {
        switch(c)
        {
        case 1:
            sauvegarde(plateau,2,couleur,c,"saveBot.txt");
            facile(plateau,couleurbot);
            if(victoire(plateau,couleurbot)==0){
                sauvegarde(plateau,1,couleur,c,"saveBot.txt");
                remplir(plateau,couleur,colonne);
                sauvegarde(plateau,2,couleur,c,"saveBot.txt");
            }
        break;

        case 2:
            sauvegarde(plateau,2,couleur,c,"saveBot.txt");
            normal(plateau,couleurbot);
            if(victoire(plateau,couleurbot)==0){
                sauvegarde(plateau,1,couleur,c,"saveBot.txt");
                remplir(plateau,couleur,colonne);
                sauvegarde(plateau,2,couleur,c,"saveBot.txt");
            }
            break;

        default : printf("\nMode de jeu indisponible !!");
        }
    }
}
