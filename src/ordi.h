#include <stdio.h>
#include <stdlib.h>

// fonctions de l' IA :
void choix_alea(int **plateau,int couleur)
{
    int v;
    srand(time(NULL));
    int colonne=(rand()%9);
    v = remplir(plateau, couleur, colonne);
    if (v==1) {
        choix_alea(plateau,couleur);
        printf("\n\nColonne pleine");
    }
}

void aligne(int **plateau,int couleur,int joueur, int *colonne)
{
    //Sert � d�tecter si 3 jetons de la couleur definis son align� et que la 4 �me case soit vide
    *colonne=NULL;
    int i,j,c2,ligne=0;
    for(i=0;i<9;i++){
        for(j=0;j<6;j++){
            // Lignes et Diagonale vers la droite
            if (i<6){
                //Lignes
                if (plateau[i][j]==couleur && plateau[i+1][j]==couleur && plateau[i+2][j]==couleur && plateau[i+3][j]==0){
                    *colonne=i+3;
                    ligne = j;
                }
                if (plateau[i][j]==couleur && plateau[i+1][j]==couleur && plateau[i+2][j]==couleur && plateau[i-1][j]==0){
                    *colonne=i-1;
                    ligne = j;
                }
                if (plateau[i][j]==couleur && plateau[i+1][j]==couleur && plateau[i+2][j]==0 && plateau[i+3][j]==couleur){
                    *colonne=i+2;
                    ligne = j;
                }
                if (plateau[i][j]==couleur && plateau[i+1][j]==0 && plateau[i+2][j]==couleur && plateau[i+3][j]==couleur){
                    *colonne=i+1;
                    ligne = j;
                }
                //Diagonales en bas
                if (j<3){
                    if (plateau[i][j]==couleur && plateau[i+1][j+1]==couleur && plateau[i+2][j+2]==couleur && plateau[i+3][j+3]==0){
                        *colonne=i+3;
                        ligne = j+3;
                    }
                    if (plateau[i][j]==couleur && plateau[i+1][j+1]==couleur && plateau[i+2][j+2]==couleur && plateau[i-1][j-1]==0){
                        *colonne=i-1;
                        ligne = j-1;
                    }
                    if (plateau[i][j]==couleur && plateau[i+1][j+1]==couleur && plateau[i+2][j+2]==0 && plateau[i+3][j+3]==couleur){
                        *colonne=i+2;
                        ligne = j+2;
                    }
                    if (plateau[i][j]==couleur && plateau[i+1][j+1]==0 && plateau[i+2][j+2]==couleur && plateau[i+3][j+3]==couleur){
                        *colonne=i+1;
                        ligne = j+1;
                    }
                }
                //Diagonales en haut
                if (j>2){
                    if (plateau[i][j]==couleur && plateau[i+1][j-1]==couleur && plateau[i+2][j-2]==couleur && plateau[i+3][j-3]==0){
                        *colonne=i+3;
                        ligne = j-3;
                    }
                    if (plateau[i][j]==couleur && plateau[i+1][j-1]==couleur && plateau[i+2][j-2]==couleur && plateau[i-1][j+1]==0){
                        *colonne=i-1;
                        ligne = j+1;
                    }
                    if (plateau[i][j]==couleur && plateau[i+1][j-1]==couleur && plateau[i+2][j-2]==0 && plateau[i+3][j-3]==couleur){
                        *colonne=i+2;
                        ligne = j-2;
                    }
                    if (plateau[i][j]==couleur && plateau[i+1][j-1]==0 && plateau[i+2][j-2]==couleur && plateau[i+3][j-3]==couleur){
                        *colonne=i+1;
                        ligne = j-1;
                    }
                }

            }
            //Colonnes
            if(j<4 && j>0){
                if (plateau[i][j]==couleur && plateau[i][j+1]==couleur && plateau[i][j+2]==couleur && plateau[i][j-1]==0){
                    *colonne=i;
                    ligne = j-1;
                }
            }
        }
    }
    // pour ne pas donner la victoire � l'adversaire en remplissant la cas juste en dessous de celle qui lui permet d'avoir les 4 align�s
    if (joueur!=couleur && plateau[*colonne][ligne+1]==0 && ligne<5 && ligne>=0){
        *colonne=NULL;
    }
}

 // n'a pas de fonctionnalité car je n'ai pa eu le temps d'implementer la version difficile
void strategie(int **plateau,int couleur,int *strat)
{
    // EOF end of file / EOL end of line
    FILE *f = fopen("strat.txt", "r");
    rewind(f);
    if (f!=NULL){
        while(fscanf(f,"strat ""%d",&strat) != EOF){

        }
    }else {
        printf("Erreur d'ouverture de fichier ");
    }

    // � finir
    fclose(f);
}

void facile(int **plateau,int couleur)
{
    choix_alea(plateau,couleur);
}

void normal(int **plateau,int couleur)
{
    int colonne,v;
    if (couleur==1){
        printf("\n1");
        aligne(plateau,2,1,&colonne);
        if (colonne==NULL){
            aligne(plateau,1,1,&colonne);
        }
    }else {
        printf("\n2");
        aligne(plateau,1,2,&colonne);
        if (colonne==NULL){
            aligne(plateau,2,2,&colonne);
        }
    }
    printf("\n3");
    if (colonne!=NULL){
        printf("\n4");
        v=remplir(plateau,couleur,colonne);
        if(v==1){
            printf("\n Colonne pleine");
            choix_alea(plateau,couleur);
        }
    }else{
        printf("\n5");
        choix_alea(plateau,couleur);
    }
}

void difficile(int **plateau,int couleur,int *strat)
{
    int colonne;
    if (couleur==1){
        aligne(plateau,2,1,&colonne);
        if (colonne==NULL){
            aligne(plateau,1,1,&colonne);
        }
    }else {
        aligne(plateau,1,2,&colonne);
        if (colonne==NULL){
            aligne(plateau,2,2,&colonne);
        }
    }
    if (colonne!=NULL){
        remplir(plateau,couleur,colonne);
    }else{
        strategie(plateau,couleur,strat);
    }if (strat==0){
        choix_alea(plateau,couleur);
    }

    // a finir
}
