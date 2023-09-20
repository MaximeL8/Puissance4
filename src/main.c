#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL_mixer.h>
#include "Puissance4.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

void SDL_ExitWithError(const char *message);
int Init_SDL(SDL_Window **window, SDL_Renderer **renderer);
int Menu(SDL_Window **window, SDL_Renderer **renderer);

int main(int argc, char **argv)
{
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
    {
      printf("%s", Mix_GetError());
    }
    Mix_Music *musique; //Création du pointeur de type Mix_Music
    musique = Mix_LoadMUS("src/p4.mp3"); //Chargement de la musique
    Mix_PlayMusic(musique, -1); //Jouer infiniment la musique

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    Init_SDL(&window, &renderer);
    Menu(&window, &renderer);
    Mix_FreeMusic(musique); //Libération de la musique
    Mix_CloseAudio(); //Fermeture de l'API
}

void Affiche(SDL_Renderer **renderer, SDL_Texture *texture_JetonRouge, SDL_Rect rectangle_JetonRouge,SDL_Texture *texture_JetonJaune, SDL_Rect rectangle_JetonJaune,int **plateau,Pos **coor)
{
    int i,j;
    for (j=0; j<6; j++){
        for (i=0; i<9; i++){
            if(plateau[i][j]==1){
                PlacerJetonRouge(renderer,texture_JetonRouge,rectangle_JetonRouge,coor[i][j].x-1,coor[i][j].y-1);
            }else if(plateau[i][j]==2){
                PlacerJetonJaune(renderer,texture_JetonJaune,rectangle_JetonJaune,coor[i][j].x-1,coor[i][j].y-1);
            }
        }
    }
}

void PlacerJetonRouge(SDL_Renderer **renderer, SDL_Texture *texture_JetonRouge, SDL_Rect rectangle_JetonRouge, int x, int y)
{
    rectangle_JetonRouge.x = x;
    rectangle_JetonRouge.y = y;
    SDL_RenderCopy(*renderer, texture_JetonRouge, NULL, &rectangle_JetonRouge);
    SDL_RenderPresent(*renderer);
}

void PlacerJetonJaune(SDL_Renderer **renderer, SDL_Texture *texture_JetonJaune, SDL_Rect rectangle_JetonJaune, int x, int y)
{
    rectangle_JetonJaune.x = x;
    rectangle_JetonJaune.y = y;
    SDL_RenderCopy(*renderer, texture_JetonJaune, NULL, &rectangle_JetonJaune);
    SDL_RenderPresent(*renderer);
}


int Init_SDL(SDL_Window **window, SDL_Renderer **renderer)
{
    // Lancement SDL
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        SDL_ExitWithError("Initialisation SDL");


    // Création fenêtre
    *window = (SDL_CreateWindow("Puissance 4", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0));
    if(*window == NULL)
    {
        SDL_ExitWithError("Erreur creation fenetre");
    }

    // Création rendu
    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_SOFTWARE);
    if(*renderer == NULL)
    {
        SDL_ExitWithError("Erreur creation rendu1");
    }
    printf("\n##Init_SDL FAIT##\n");
}

int Menu(SDL_Window **window, SDL_Renderer **renderer)
{

SDL_Surface *image_Menu = NULL;
SDL_Surface *image_Menu_1Jselect = NULL;
SDL_Surface *image_Menu_2Jselect = NULL;
SDL_Surface *image_Menu_CreditsSelect = NULL;
SDL_Surface *image_FacileNormal = NULL;
SDL_Surface *image_Credits = NULL;
SDL_Surface *image_FacileSelect = NULL;
SDL_Surface *image_NormalSelect = NULL;
SDL_Surface *image_FlecheCreditSelect = NULL;
SDL_Surface *image_PlateauVierge = NULL;
SDL_Surface *image_ButtonPause = NULL;
SDL_Surface *image_ButtonPauseSelect = NULL;
SDL_Surface *image_ChoixCouleurBot = NULL;
SDL_Surface *image_RougeSelect = NULL;
SDL_Surface *image_JauneSelect = NULL;
SDL_Surface *image_ChoixCouleur2joueurs = NULL;
SDL_Surface *image_JetonRouge = NULL;
SDL_Surface *image_JetonJaune = NULL;
SDL_Surface *image_Joueur1Rouge = NULL;
SDL_Surface *image_Joueur1Jaune = NULL;
SDL_Surface *image_VousAvezPerdu = NULL;
SDL_Surface *image_Joueur1Gagne = NULL;
SDL_Surface *image_Joueur2Gagne = NULL;
SDL_Surface *image_ReprendreLaPartie = NULL;
SDL_Surface *image_ReprendreLaPartieOUISelect = NULL;
SDL_Surface *image_ReprendreLaPartieNONSelect = NULL;
SDL_Surface *image_ReprendreLaPartieAPPause = NULL;
SDL_Surface *image_ReprendreLaPartieAPPauseSelect = NULL;
SDL_Surface *image_QuitterLaPartie = NULL;
SDL_Surface *image_QuitterLaPartieSelect = NULL;


SDL_Texture *texture_Menu = NULL;
SDL_Texture *texture_Menu_1Jselect = NULL;
SDL_Texture *texture_Menu_2Jselect = NULL;
SDL_Texture *texture_Menu_CreditsSelect = NULL;
SDL_Texture *texture_FacileNormal = NULL;
SDL_Texture *texture_Credits = NULL;
SDL_Texture *texture_FacileSelect = NULL;
SDL_Texture *texture_NormalSelect = NULL;
SDL_Texture *texture_FlecheCreditSelect = NULL;
SDL_Texture *texture_PlateauVierge = NULL;
SDL_Texture *texture_ButtonPause = NULL;
SDL_Texture *texture_ButtonPauseSelect = NULL;
SDL_Texture *texture_ChoixCouleurBot = NULL;
SDL_Texture *texture_RougeSelect = NULL;
SDL_Texture *texture_JauneSelect = NULL;
SDL_Texture *texture_ChoixCouleur2joueurs = NULL;
SDL_Texture *texture_JetonRouge = NULL;
SDL_Texture *texture_JetonJaune = NULL;
SDL_Texture *texture_Joueur1Rouge = NULL;
SDL_Texture *texture_Joueur1Jaune = NULL;
SDL_Texture *texture_VousAvezPerdu = NULL;
SDL_Texture *texture_Joueur1Gagne = NULL;
SDL_Texture *texture_Joueur2Gagne = NULL;
SDL_Texture *texture_ReprendreLaPartie = NULL;
SDL_Texture *texture_ReprendreLaPartieOUISelect = NULL;
SDL_Texture *texture_ReprendreLaPartieNONSelect = NULL;
SDL_Texture *texture_ReprendreLaPartieAPPause = NULL;
SDL_Texture *texture_ReprendreLaPartieAPPauseSelect = NULL;
SDL_Texture *texture_QuitterLaPartie = NULL;
SDL_Texture *texture_QuitterLaPartieSelect = NULL;

image_Menu = SDL_LoadBMP("src/Images/Menu_Puissance4_720.bmp");
image_Menu_1Jselect = SDL_LoadBMP("src/Images/1joueur_720.bmp");
image_Menu_2Jselect = SDL_LoadBMP("src/Images/2joueurs_720.bmp");
image_Menu_CreditsSelect = SDL_LoadBMP("src/Images/credits_720.bmp");
image_FacileNormal = SDL_LoadBMP("src/Images/facile_normal_720.bmp");
image_Credits = SDL_LoadBMP("src/Images/credits_fleche_deselectionnee_720.bmp");
image_FacileSelect = SDL_LoadBMP("src/Images/facile_720.bmp");
image_NormalSelect = SDL_LoadBMP("src/Images/normal_720.bmp");
image_FlecheCreditSelect = SDL_LoadBMP("src/Images/credits_fleche_selectionnee_720.bmp");
image_PlateauVierge = SDL_LoadBMP("src/Images/puissance_4_vierge_720.bmp");
image_ButtonPause = SDL_LoadBMP("src/Images/pause_deselectionne_720.bmp");
image_ButtonPauseSelect = SDL_LoadBMP("src/Images/pause_selectionne_720.bmp");
image_ChoixCouleurBot = SDL_LoadBMP("src/Images/choisissez_votre_couleur_bott_720.bmp");
image_RougeSelect = SDL_LoadBMP("src/Images/bott_rouge_selectionne_720.bmp");
image_JauneSelect = SDL_LoadBMP("src/Images/bott_jaune_selectionne_720.bmp");
image_ChoixCouleur2joueurs = SDL_LoadBMP("src/Images/choisissez_votre_couleur_720.bmp");
image_JetonRouge = SDL_LoadBMP("src/Images/jeton_rouge_720.bmp");
image_JetonJaune = SDL_LoadBMP("src/Images/jeton_jaune_720.bmp");
image_Joueur1Rouge = SDL_LoadBMP("src/Images/joueur1rouge_720.bmp");
image_Joueur1Jaune = SDL_LoadBMP("src/Images/joueur1jaune_720.bmp");
image_VousAvezPerdu = SDL_LoadBMP("src/Images/vous_avez_perdu.bmp");
image_Joueur1Gagne = SDL_LoadBMP("src/Images/joueur1_a_gagne.bmp");
image_Joueur2Gagne = SDL_LoadBMP("src/Images/joueur2_a_gagne.bmp");
image_ReprendreLaPartie = SDL_LoadBMP("src/Images/reprendre_la_partie_selectionne_720.bmp");
image_ReprendreLaPartieOUISelect = SDL_LoadBMP("src/Images/OUI_reprendre_la_partie_720.bmp");
image_ReprendreLaPartieNONSelect = SDL_LoadBMP("src/Images/NON_reprendre_la_partie_720.bmp");
image_ReprendreLaPartieAPPause = SDL_LoadBMP("src/Images/reprendre_la_partie_720.bmp");
image_ReprendreLaPartieAPPauseSelect = SDL_LoadBMP("src/Images/reprendre_selectionne_720.bmp");
image_QuitterLaPartie = SDL_LoadBMP("src/Images/quitter_720.bmp");
image_QuitterLaPartieSelect = SDL_LoadBMP("src/Images/quitter_selectionne_720.bmp");

/*-------------------------------------IMAGE MENU-------------------------------------------------*/
if(image_Menu == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger l'image Menu");
}

texture_Menu = SDL_CreateTextureFromSurface(*renderer, image_Menu);

SDL_FreeSurface(image_Menu);

if(texture_Menu == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de créer la texture");
}

/*-------------------------------------IMAGE MENU_1JSelect----------------------------------------*/
if(image_Menu_1Jselect == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger l'image Menu_1Jselect");
}

texture_Menu_1Jselect = SDL_CreateTextureFromSurface(*renderer, image_Menu_1Jselect);

SDL_FreeSurface(image_Menu_1Jselect);

if(texture_Menu_1Jselect == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de créer la textureMenu1JSelect");
}

/*-------------------------------------IMAGE MENU_2JSelect----------------------------------------*/
if(image_Menu_2Jselect == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger l'image Menu_2Jselect");
}

texture_Menu_2Jselect = SDL_CreateTextureFromSurface(*renderer, image_Menu_2Jselect);

SDL_FreeSurface(image_Menu_2Jselect);

if(texture_Menu_2Jselect == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de créer la textureMenu2JSelect");
}

/*-------------------------------------IMAGE MENU_CreditsSelect----------------------------------------*/
if(image_Menu_CreditsSelect == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger l'image Menu_creditsselect");
}

texture_Menu_CreditsSelect = SDL_CreateTextureFromSurface(*renderer, image_Menu_CreditsSelect);

SDL_FreeSurface(image_Menu_CreditsSelect);

if(texture_Menu_CreditsSelect == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de créer la textureMenuCreditsSelect");
}

/*-------------------------------------IMAGE FacileNormal----------------------------------------*/
if(image_FacileNormal == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger l'image FacileNormal");
}

texture_FacileNormal = SDL_CreateTextureFromSurface(*renderer, image_FacileNormal);

SDL_FreeSurface(image_FacileNormal);

if(texture_FacileNormal == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de créer la textureFacileNormal");
}

/*-------------------------------------IMAGE Credits--------------------------------------------*/
if(image_Credits == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger l'image Credits");
}

texture_Credits = SDL_CreateTextureFromSurface(*renderer, image_Credits);

SDL_FreeSurface(image_Credits);

if(texture_Credits == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de créer la textureCredits");
}

/*-------------------------------------IMAGE FacileSelect--------------------------------------------*/
if(image_FacileSelect == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger l'image FacileSelect");
}

texture_FacileSelect = SDL_CreateTextureFromSurface(*renderer, image_FacileSelect);

SDL_FreeSurface(image_FacileSelect);

if(texture_FacileSelect == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de créer la textureFacileSelect");
}

/*-------------------------------------IMAGE NormalSelect--------------------------------------------*/
if(image_NormalSelect == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger l'image NormalSelect");
}

texture_NormalSelect = SDL_CreateTextureFromSurface(*renderer, image_NormalSelect);

SDL_FreeSurface(image_NormalSelect);

if(texture_NormalSelect == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de créer la textureNormalSelect");
}

/*-------------------------------------IMAGE FlecheCreditSelect--------------------------------------------*/
if(image_FlecheCreditSelect == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger l'image FlecheCreditSelect");
}

texture_FlecheCreditSelect = SDL_CreateTextureFromSurface(*renderer, image_FlecheCreditSelect);

SDL_FreeSurface(image_FlecheCreditSelect);

if(texture_FlecheCreditSelect == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de créer la texture FlecheCreditSelect");
}

/*-------------------------------------IMAGE PlateauVierge--------------------------------------------*/
if(image_PlateauVierge == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger l'image PlateauVierge");
}

texture_PlateauVierge = SDL_CreateTextureFromSurface(*renderer, image_PlateauVierge);

SDL_FreeSurface(image_PlateauVierge);

if(texture_PlateauVierge == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de créer la texture PlateauVierge");
}

/*-------------------------------------IMAGE ButtonPause--------------------------------------------*/
if(image_ButtonPause == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger l'image ButtonPause");
}

texture_ButtonPause = SDL_CreateTextureFromSurface(*renderer, image_ButtonPause);

SDL_FreeSurface(image_ButtonPause);

if(texture_ButtonPause == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de créer la texture ButtonPause");
}

/*-------------------------------------IMAGE ButtonPause--------------------------------------------*/
if(image_ButtonPauseSelect == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger l'image ButtonPauseSelect");
}

texture_ButtonPauseSelect = SDL_CreateTextureFromSurface(*renderer, image_ButtonPauseSelect);

SDL_FreeSurface(image_ButtonPauseSelect);

if(texture_ButtonPauseSelect == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de créer la texture ButtonPauseSelect");
}

/*-------------------------------------IMAGE ChoixCouleurBot--------------------------------------------*/
if(image_ChoixCouleurBot == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger l'image choixCouleurBot");
}

texture_ChoixCouleurBot = SDL_CreateTextureFromSurface(*renderer, image_ChoixCouleurBot);

SDL_FreeSurface(image_ChoixCouleurBot);

if(texture_ChoixCouleurBot == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de créer la texture choixCouleurBot");
}

/*-------------------------------------IMAGE RougeSelect--------------------------------------------*/
if(image_RougeSelect == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger l'image RougeSelect");
}

texture_RougeSelect = SDL_CreateTextureFromSurface(*renderer, image_RougeSelect);

SDL_FreeSurface(image_RougeSelect);

if(texture_RougeSelect == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de créer la texture RougeSelect");
}

/*-------------------------------------IMAGE JauneSelect--------------------------------------------*/
if(image_JauneSelect == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger l'image JauneSelect");
}

texture_JauneSelect = SDL_CreateTextureFromSurface(*renderer, image_JauneSelect);

SDL_FreeSurface(image_JauneSelect);

if(texture_JauneSelect == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de créer la texture JauneSelect");
}

/*-------------------------------------IMAGE ChoixCouleur2joueurs---------------------------------*/
if(image_ChoixCouleur2joueurs == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger l'image ChoixCouleur2joueurs");
}

texture_ChoixCouleur2joueurs = SDL_CreateTextureFromSurface(*renderer, image_ChoixCouleur2joueurs);

SDL_FreeSurface(image_ChoixCouleur2joueurs);

if(texture_ChoixCouleur2joueurs == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de créer la texture ChoixCouleur2joueurs");
}

/*-------------------------------------IMAGE JetonRouge---------------------------------*/
if(image_JetonRouge == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger l'image JetonRouge");
}

texture_JetonRouge = SDL_CreateTextureFromSurface(*renderer, image_JetonRouge);

SDL_FreeSurface(image_JetonRouge);

if(texture_JetonRouge == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de créer la texture JetonRouge");
}

/*-------------------------------------IMAGE JetonJaune---------------------------------*/
if(image_JetonJaune == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger l'image JetonJaune");
}

texture_JetonJaune = SDL_CreateTextureFromSurface(*renderer, image_JetonJaune);

SDL_FreeSurface(image_JetonJaune);

if(texture_JetonJaune == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de créer la texture JetonJaune");
}

/*-------------------------------------IMAGE Joueur1Rouge---------------------------------*/
if(image_Joueur1Rouge == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger l'image Joueur1Rouge");
}

texture_Joueur1Rouge = SDL_CreateTextureFromSurface(*renderer, image_Joueur1Rouge);

SDL_FreeSurface(image_Joueur1Rouge);

if(texture_Joueur1Rouge == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de créer la texture Joueur1Rouge");
}

/*-------------------------------------IMAGE Joueur1Jaune---------------------------------*/
if(image_Joueur1Jaune == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger l'image Joueur1Jaune");
}

texture_Joueur1Jaune = SDL_CreateTextureFromSurface(*renderer, image_Joueur1Jaune);

SDL_FreeSurface(image_Joueur1Jaune);

if(texture_Joueur1Jaune == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de créer la texture Joueur1Jaune");
}

/*-------------------------------------IMAGE VousAvezPerdu---------------------------------*/
if(image_VousAvezPerdu == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger l'image VousAvezPerdu");
}

texture_VousAvezPerdu = SDL_CreateTextureFromSurface(*renderer, image_VousAvezPerdu);

SDL_FreeSurface(image_VousAvezPerdu);

if(texture_VousAvezPerdu == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de créer la texture VousAvezPerdu");
}

/*-------------------------------------IMAGE Joueur1Gagne---------------------------------*/
if(image_Joueur1Gagne == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger l'image Joueur1Gagne");
}

texture_Joueur1Gagne = SDL_CreateTextureFromSurface(*renderer, image_Joueur1Gagne);

SDL_FreeSurface(image_Joueur1Gagne);

if(texture_Joueur1Gagne == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de créer la texture Joueur1Gagne");
}

/*-------------------------------------IMAGE Joueur2Gagne---------------------------------*/
if(image_Joueur2Gagne == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger l'image Joueur2Gagne");
}

texture_Joueur2Gagne = SDL_CreateTextureFromSurface(*renderer, image_Joueur2Gagne);

SDL_FreeSurface(image_Joueur2Gagne);

if(texture_Joueur2Gagne == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de créer la texture Joueur2Gagne");
}

/*-------------------------------------IMAGE ReprendreLaPartie---------------------------------*/
if(image_ReprendreLaPartie == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger l'image ReprendreLaPartie");
}

texture_ReprendreLaPartie = SDL_CreateTextureFromSurface(*renderer, image_ReprendreLaPartie);

SDL_FreeSurface(image_ReprendreLaPartie);

if(texture_ReprendreLaPartie == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de créer la texture ReprendreLaPartie");
}

/*-------------------------------------IMAGE ReprendreLaPartieOUISelect---------------------------------*/
if(image_ReprendreLaPartieOUISelect == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger l'image ReprendreLaPartieOUISelect");
}

texture_ReprendreLaPartieOUISelect = SDL_CreateTextureFromSurface(*renderer, image_ReprendreLaPartieOUISelect);

SDL_FreeSurface(image_ReprendreLaPartieOUISelect);

if(texture_ReprendreLaPartieOUISelect == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de créer la texture ReprendreLaPartieOUISelect");
}

/*-------------------------------------IMAGE ReprendreLaPartieNONSelect---------------------------------*/
if(image_ReprendreLaPartieNONSelect == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger l'image ReprendreLaPartieNONSelect");
}

texture_ReprendreLaPartieNONSelect = SDL_CreateTextureFromSurface(*renderer, image_ReprendreLaPartieNONSelect);

SDL_FreeSurface(image_ReprendreLaPartieNONSelect);

if(texture_ReprendreLaPartieNONSelect == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de créer la texture ReprendreLaPartieNONSelect");
}

/*-------------------------------------IMAGE ReprendreLaPartieAPPause---------------------------------*/
if(image_ReprendreLaPartieAPPause == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger l'image ReprendreLaPartieAPPause");
}

texture_ReprendreLaPartieAPPause = SDL_CreateTextureFromSurface(*renderer, image_ReprendreLaPartieAPPause);

SDL_FreeSurface(image_ReprendreLaPartieAPPause);

if(texture_ReprendreLaPartieAPPause == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de créer la texture ReprendreLaPartieAPPause");
}

/*-------------------------------------IMAGE ReprendreLaPartieAPPauseSelect---------------------------------*/
if(image_ReprendreLaPartieAPPauseSelect == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger l'image ReprendreLaPartieAPPauseSelect");
}

texture_ReprendreLaPartieAPPauseSelect = SDL_CreateTextureFromSurface(*renderer, image_ReprendreLaPartieAPPauseSelect);

SDL_FreeSurface(image_ReprendreLaPartieAPPauseSelect);

if(texture_ReprendreLaPartieAPPauseSelect == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de créer la texture ReprendreLaPartieAPPauseSelect");
}

/*-------------------------------------IMAGE QuitterLaPartie---------------------------------*/
if(image_QuitterLaPartie == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger l'image QuitterLaPartie");
}

texture_QuitterLaPartie = SDL_CreateTextureFromSurface(*renderer, image_QuitterLaPartie);

SDL_FreeSurface(image_QuitterLaPartie);

if(texture_QuitterLaPartie == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de créer la texture QuitterLaPartie");
}

/*-------------------------------------IMAGE QuitterLaPartieSelect---------------------------------*/
if(image_QuitterLaPartieSelect == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger l'image QuitterLaPartieSelect");
}

texture_QuitterLaPartieSelect = SDL_CreateTextureFromSurface(*renderer, image_QuitterLaPartieSelect);

SDL_FreeSurface(image_QuitterLaPartieSelect);

if(texture_QuitterLaPartieSelect == NULL)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de créer la texture QuitterLaPartieSelect");
}

/*-----------------------------------------------------------------------------------------------*/
SDL_Rect rectangle_Menu;
SDL_Rect rectangle_Menu1Jselect;
SDL_Rect rectangle_Menu2Jselect;
SDL_Rect rectangle_MenuCreditsSelect;
SDL_Rect rectangle_FacileNormal;
SDL_Rect rectangle_Credits;
SDL_Rect rectangle_FacileSelect;
SDL_Rect rectangle_NormalSelect;
SDL_Rect rectangle_FlecheCreditSelect;
SDL_Rect rectangle_PlateauVierge;
SDL_Rect rectangle_ButtonPause;
SDL_Rect rectangle_ButtonPauseSelect;
SDL_Rect rectangle_ChoixCouleurBot;
SDL_Rect rectangle_RougeSelect;
SDL_Rect rectangle_JauneSelect;
SDL_Rect rectangle_ChoixCouleur2joueurs;
SDL_Rect rectangle_JetonRouge;
SDL_Rect rectangle_JetonJaune;
SDL_Rect rectangle_Joueur1Rouge;
SDL_Rect rectangle_Joueur1Jaune;
SDL_Rect rectangle_VousAvezPerdu;
SDL_Rect rectangle_Joueur1Gagne;
SDL_Rect rectangle_Joueur2Gagne;
SDL_Rect rectangle_ReprendreLaPartie;
SDL_Rect rectangle_ReprendreLaPartieOUISelect;
SDL_Rect rectangle_ReprendreLaPartieNONSelect;
SDL_Rect rectangle_ReprendreLaPartieAPPause;
SDL_Rect rectangle_ReprendreLaPartieAPPauseSelect;
SDL_Rect rectangle_QuitterLaPartie;
SDL_Rect rectangle_QuitterLaPartieSelect;

// Pour le Menu
if(SDL_QueryTexture(texture_Menu, NULL, NULL, &rectangle_Menu.w, &rectangle_Menu.h) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger la texture");
}

rectangle_Menu.x = (WINDOW_WIDTH - rectangle_Menu.w) / 2;
rectangle_Menu.y = (WINDOW_HEIGHT - rectangle_Menu.h) / 2;

if(SDL_RenderCopy(*renderer, texture_Menu, NULL, &rectangle_Menu) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible d'afficher la texture Menu");
}

// Pour image Menu 1J select
if(SDL_QueryTexture(texture_Menu_1Jselect, NULL, NULL, &rectangle_Menu1Jselect.w, &rectangle_Menu1Jselect.h) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger la texture2");
}

rectangle_Menu1Jselect.x = (WINDOW_WIDTH - rectangle_Menu1Jselect.w) / 2;
rectangle_Menu1Jselect.y = (WINDOW_HEIGHT - rectangle_Menu1Jselect.h) / 2;

if(SDL_RenderCopy(*renderer, texture_Menu_1Jselect, NULL, &rectangle_Menu1Jselect) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible d'afficher la texture2");
}

// Pour image Menu 2J select
if(SDL_QueryTexture(texture_Menu_2Jselect, NULL, NULL, &rectangle_Menu2Jselect.w, &rectangle_Menu2Jselect.h) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger la texture3");
}

rectangle_Menu2Jselect.x = (WINDOW_WIDTH - rectangle_Menu2Jselect.w) / 2;
rectangle_Menu2Jselect.y = (WINDOW_HEIGHT - rectangle_Menu2Jselect.h) / 2;

if(SDL_RenderCopy(*renderer, texture_Menu_2Jselect, NULL, &rectangle_Menu2Jselect) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible d'afficher la texture3");
}

// Pour image Menu Credits Select
if(SDL_QueryTexture(texture_Menu_CreditsSelect, NULL, NULL, &rectangle_MenuCreditsSelect.w, &rectangle_MenuCreditsSelect.h) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger la texture4");
}

rectangle_MenuCreditsSelect.x = (WINDOW_WIDTH - rectangle_MenuCreditsSelect.w) / 2;
rectangle_MenuCreditsSelect.y = (WINDOW_HEIGHT - rectangle_MenuCreditsSelect.h) / 2;

if(SDL_RenderCopy(*renderer, texture_Menu_CreditsSelect, NULL, &rectangle_MenuCreditsSelect) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible d'afficher la texture4");
}

// Pour FacileNormal
if(SDL_QueryTexture(texture_FacileNormal, NULL, NULL, &rectangle_FacileNormal.w, &rectangle_FacileNormal.h) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger la texture5");
}

rectangle_FacileNormal.x = (WINDOW_WIDTH - rectangle_FacileNormal.w) / 2;
rectangle_FacileNormal.y = (WINDOW_HEIGHT - rectangle_FacileNormal.h) / 2;

if(SDL_RenderCopy(*renderer, texture_FacileNormal, NULL, &rectangle_FacileNormal) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible d'afficher la texture5");
}

// Pour Credits
if(SDL_QueryTexture(texture_Credits, NULL, NULL, &rectangle_Credits.w, &rectangle_Credits.h) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger la texture6");
}

rectangle_Credits.x = (WINDOW_WIDTH - rectangle_Credits.w) / 2;
rectangle_Credits.y = (WINDOW_HEIGHT - rectangle_Credits.h) / 2;

if(SDL_RenderCopy(*renderer, texture_Credits, NULL, &rectangle_Credits) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible d'afficher la texture6");
}

// Pour Facile Select
if(SDL_QueryTexture(texture_FacileSelect, NULL, NULL, &rectangle_FacileSelect.w, &rectangle_FacileSelect.h) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger la texture7");
}

rectangle_FacileSelect.x = (WINDOW_WIDTH - rectangle_FacileSelect.w) / 2;
rectangle_FacileSelect.y = (WINDOW_HEIGHT - rectangle_FacileSelect.h) / 2;

if(SDL_RenderCopy(*renderer, texture_FacileSelect, NULL, &rectangle_FacileSelect) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible d'afficher la texture7");
}

// Pour Normal Select
if(SDL_QueryTexture(texture_NormalSelect, NULL, NULL, &rectangle_NormalSelect.w, &rectangle_NormalSelect.h) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger la texture8");
}

rectangle_NormalSelect.x = (WINDOW_WIDTH - rectangle_NormalSelect.w) / 2;
rectangle_NormalSelect.y = (WINDOW_HEIGHT - rectangle_NormalSelect.h) / 2;

if(SDL_RenderCopy(*renderer, texture_NormalSelect, NULL, &rectangle_NormalSelect) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible d'afficher la texture8");
}

// Pour FlecheCreditSelect
if(SDL_QueryTexture(texture_FlecheCreditSelect, NULL, NULL, &rectangle_FlecheCreditSelect.w, &rectangle_FlecheCreditSelect.h) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger la texture9");
}

rectangle_FlecheCreditSelect.x = (WINDOW_WIDTH - rectangle_FlecheCreditSelect.w) / 2;
rectangle_FlecheCreditSelect.y = (WINDOW_HEIGHT - rectangle_FlecheCreditSelect.h) / 2;

if(SDL_RenderCopy(*renderer, texture_FlecheCreditSelect, NULL, &rectangle_FlecheCreditSelect) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible d'afficher la texture9");
}

// Pour PlateauVierge
if(SDL_QueryTexture(texture_PlateauVierge, NULL, NULL, &rectangle_PlateauVierge.w, &rectangle_PlateauVierge.h) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger la texture10");
}

rectangle_PlateauVierge.x = (WINDOW_WIDTH - rectangle_PlateauVierge.w) / 2;
rectangle_PlateauVierge.y = (WINDOW_HEIGHT - rectangle_PlateauVierge.h) / 2;

if(SDL_RenderCopy(*renderer, texture_PlateauVierge, NULL, &rectangle_PlateauVierge) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible d'afficher la texture10");
}

// Pour ButtonPause
if(SDL_QueryTexture(texture_ButtonPause, NULL, NULL, &rectangle_ButtonPause.w, &rectangle_ButtonPause.h) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger la texture11");
}

rectangle_ButtonPause.x = 1180;
rectangle_ButtonPause.y = 56;

if(SDL_RenderCopy(*renderer, texture_ButtonPause, NULL, &rectangle_ButtonPause) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible d'afficher la texture11");
}

// Pour ButtonPauseSelect
if(SDL_QueryTexture(texture_ButtonPauseSelect, NULL, NULL, &rectangle_ButtonPauseSelect.w, &rectangle_ButtonPauseSelect.h) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger la texture12");
}

rectangle_ButtonPauseSelect.x = 1180;
rectangle_ButtonPauseSelect.y = 56;

if(SDL_RenderCopy(*renderer, texture_ButtonPauseSelect, NULL, &rectangle_ButtonPauseSelect) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible d'afficher la texture12");
}

// Pour ChoixCouleurBot
if(SDL_QueryTexture(texture_ChoixCouleurBot, NULL, NULL, &rectangle_ChoixCouleurBot.w, &rectangle_ChoixCouleurBot.h) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger la texture13");
}

rectangle_ChoixCouleurBot.x = (WINDOW_WIDTH - rectangle_ChoixCouleurBot.w) / 2;
rectangle_ChoixCouleurBot.y = (WINDOW_HEIGHT - rectangle_ChoixCouleurBot.h) / 2;

if(SDL_RenderCopy(*renderer, texture_ChoixCouleurBot, NULL, &rectangle_ChoixCouleurBot) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible d'afficher la texture13");
}

// Pour RougeSelect
if(SDL_QueryTexture(texture_RougeSelect, NULL, NULL, &rectangle_RougeSelect.w, &rectangle_RougeSelect.h) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger la texture14");
}

rectangle_RougeSelect.x = (WINDOW_WIDTH - rectangle_RougeSelect.w) / 2;
rectangle_RougeSelect.y = (WINDOW_HEIGHT - rectangle_RougeSelect.h) / 2;

if(SDL_RenderCopy(*renderer, texture_RougeSelect, NULL, &rectangle_RougeSelect) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible d'afficher la texture14");
}

// Pour JauneSelect
if(SDL_QueryTexture(texture_JauneSelect, NULL, NULL, &rectangle_JauneSelect.w, &rectangle_JauneSelect.h) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger la texture15");
}

rectangle_JauneSelect.x = (WINDOW_WIDTH - rectangle_JauneSelect.w) / 2;
rectangle_JauneSelect.y = (WINDOW_HEIGHT - rectangle_RougeSelect.h) / 2;

if(SDL_RenderCopy(*renderer, texture_JauneSelect, NULL, &rectangle_JauneSelect) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible d'afficher la texture15");
}

//Pour ChoixCouleur2joueurs
if(SDL_QueryTexture(texture_ChoixCouleur2joueurs, NULL, NULL, &rectangle_ChoixCouleur2joueurs.w, &rectangle_ChoixCouleur2joueurs.h) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger la texture16");
}

rectangle_ChoixCouleur2joueurs.x = (WINDOW_WIDTH - rectangle_ChoixCouleur2joueurs.w) / 2;
rectangle_ChoixCouleur2joueurs.y = (WINDOW_HEIGHT - rectangle_ChoixCouleur2joueurs.h) / 2;

if(SDL_RenderCopy(*renderer, texture_ChoixCouleur2joueurs, NULL, &rectangle_ChoixCouleur2joueurs) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible d'afficher la texture16");
}

//Pour JetonRouge
if(SDL_QueryTexture(texture_JetonRouge, NULL, NULL, &rectangle_JetonRouge.w, &rectangle_JetonRouge.h) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger la texture17");
}

rectangle_JetonRouge.x = (WINDOW_WIDTH - rectangle_JetonRouge.w) / 2;
rectangle_JetonRouge.y = (WINDOW_HEIGHT - rectangle_JetonRouge.h) / 2;

if(SDL_RenderCopy(*renderer, texture_JetonRouge, NULL, &rectangle_JetonRouge) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible d'afficher la texture17");
}

//Pour JetonJaune
if(SDL_QueryTexture(texture_JetonJaune, NULL, NULL, &rectangle_JetonJaune.w, &rectangle_JetonJaune.h) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger la texture18");
}

rectangle_JetonJaune.x = (WINDOW_WIDTH - rectangle_JetonJaune.w) / 2;
rectangle_JetonJaune.y = (WINDOW_HEIGHT - rectangle_JetonJaune.h) / 2;

if(SDL_RenderCopy(*renderer, texture_JetonJaune, NULL, &rectangle_JetonJaune) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible d'afficher la texture18");
}

//Pour Joueur1Rouge
if(SDL_QueryTexture(texture_Joueur1Rouge, NULL, NULL, &rectangle_Joueur1Rouge.w, &rectangle_Joueur1Rouge.h) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger la texture19");
}

rectangle_Joueur1Rouge.x = (WINDOW_WIDTH - rectangle_Joueur1Rouge.w) / 2;
rectangle_Joueur1Rouge.y = (WINDOW_HEIGHT - rectangle_Joueur1Rouge.h) / 2;

if(SDL_RenderCopy(*renderer, texture_Joueur1Rouge, NULL, &rectangle_Joueur1Rouge) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible d'afficher la texture19");
}

//Pour Joueur1Jaune
if(SDL_QueryTexture(texture_Joueur1Jaune, NULL, NULL, &rectangle_Joueur1Jaune.w, &rectangle_Joueur1Jaune.h) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger la texture20");
}

rectangle_Joueur1Jaune.x = (WINDOW_WIDTH - rectangle_Joueur1Jaune.w) / 2;
rectangle_Joueur1Jaune.y = (WINDOW_HEIGHT - rectangle_Joueur1Jaune.h) / 2;

if(SDL_RenderCopy(*renderer, texture_Joueur1Jaune, NULL, &rectangle_Joueur1Jaune) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible d'afficher la texture20");
}

//Pour VousAvezPerdu
if(SDL_QueryTexture(texture_VousAvezPerdu, NULL, NULL, &rectangle_VousAvezPerdu.w, &rectangle_VousAvezPerdu.h) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger la texture21");
}

rectangle_VousAvezPerdu.x = (WINDOW_WIDTH - rectangle_VousAvezPerdu.w) / 2;
rectangle_VousAvezPerdu.y = (WINDOW_HEIGHT - rectangle_VousAvezPerdu.h) / 2;

if(SDL_RenderCopy(*renderer, texture_VousAvezPerdu, NULL, &rectangle_VousAvezPerdu) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible d'afficher la texture21");
}

//Pour Joueur1Gagne
if(SDL_QueryTexture(texture_Joueur1Gagne, NULL, NULL, &rectangle_Joueur1Gagne.w, &rectangle_Joueur1Gagne.h) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger la texture22");
}

rectangle_Joueur1Gagne.x = (WINDOW_WIDTH - rectangle_Joueur1Gagne.w) / 2;
rectangle_Joueur1Gagne.y = (WINDOW_HEIGHT - rectangle_Joueur1Gagne.h) / 2;

if(SDL_RenderCopy(*renderer, texture_Joueur1Gagne, NULL, &rectangle_Joueur1Gagne) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible d'afficher la texture22");
}

//Pour Joueur2Gagne
if(SDL_QueryTexture(texture_Joueur2Gagne, NULL, NULL, &rectangle_Joueur2Gagne.w, &rectangle_Joueur2Gagne.h) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger la texture23");
}

rectangle_Joueur2Gagne.x = (WINDOW_WIDTH - rectangle_Joueur2Gagne.w) / 2;
rectangle_Joueur2Gagne.y = (WINDOW_HEIGHT - rectangle_Joueur2Gagne.h) / 2;

if(SDL_RenderCopy(*renderer, texture_Joueur2Gagne, NULL, &rectangle_Joueur2Gagne) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible d'afficher la texture23");
}

//Pour ReprendreLaPartie
if(SDL_QueryTexture(texture_ReprendreLaPartie, NULL, NULL, &rectangle_ReprendreLaPartie.w, &rectangle_ReprendreLaPartie.h) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger la texture24");
}

rectangle_ReprendreLaPartie.x = (WINDOW_WIDTH - rectangle_ReprendreLaPartie.w) / 2;
rectangle_ReprendreLaPartie.y = (WINDOW_HEIGHT - rectangle_ReprendreLaPartie.h) / 2;

if(SDL_RenderCopy(*renderer, texture_ReprendreLaPartie, NULL, &rectangle_ReprendreLaPartie) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible d'afficher la texture24");
}

//Pour ReprendreLaPartieOUISelect
if(SDL_QueryTexture(texture_ReprendreLaPartieOUISelect, NULL, NULL, &rectangle_ReprendreLaPartieOUISelect.w, &rectangle_ReprendreLaPartieOUISelect.h) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger la texture25");
}

rectangle_ReprendreLaPartieOUISelect.x = (WINDOW_WIDTH - rectangle_ReprendreLaPartieOUISelect.w) / 2;
rectangle_ReprendreLaPartieOUISelect.y = (WINDOW_HEIGHT - rectangle_ReprendreLaPartieOUISelect.h) / 2;

if(SDL_RenderCopy(*renderer, texture_ReprendreLaPartieOUISelect, NULL, &rectangle_ReprendreLaPartieOUISelect) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible d'afficher la texture25");
}

//Pour ReprendreLaPartieNONSelect
if(SDL_QueryTexture(texture_ReprendreLaPartieNONSelect, NULL, NULL, &rectangle_ReprendreLaPartieNONSelect.w, &rectangle_ReprendreLaPartieNONSelect.h) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger la texture26");
}

rectangle_ReprendreLaPartieNONSelect.x = (WINDOW_WIDTH - rectangle_ReprendreLaPartieNONSelect.w) / 2;
rectangle_ReprendreLaPartieNONSelect.y = (WINDOW_HEIGHT - rectangle_ReprendreLaPartieNONSelect.h) / 2;

if(SDL_RenderCopy(*renderer, texture_ReprendreLaPartieNONSelect, NULL, &rectangle_ReprendreLaPartieNONSelect) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible d'afficher la texture26");
}

//Pour ReprendreLaPartieAPPause
if(SDL_QueryTexture(texture_ReprendreLaPartieAPPause, NULL, NULL, &rectangle_ReprendreLaPartieAPPause.w, &rectangle_ReprendreLaPartieAPPause.h) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger la texture27");
}

rectangle_ReprendreLaPartieAPPause.x = (WINDOW_WIDTH - rectangle_ReprendreLaPartieAPPause.w) / 2;
rectangle_ReprendreLaPartieAPPause.y = 200;

if(SDL_RenderCopy(*renderer, texture_ReprendreLaPartieAPPause, NULL, &rectangle_ReprendreLaPartieAPPause) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible d'afficher la texture27");
}

//Pour ReprendreLaPartieAPPauseSelect
if(SDL_QueryTexture(texture_ReprendreLaPartieAPPauseSelect, NULL, NULL, &rectangle_ReprendreLaPartieAPPauseSelect.w, &rectangle_ReprendreLaPartieAPPauseSelect.h) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger la texture28");
}

rectangle_ReprendreLaPartieAPPauseSelect.x = (WINDOW_WIDTH - rectangle_ReprendreLaPartieAPPauseSelect.w) / 2;
rectangle_ReprendreLaPartieAPPauseSelect.y = 200;

if(SDL_RenderCopy(*renderer, texture_ReprendreLaPartieAPPauseSelect, NULL, &rectangle_ReprendreLaPartieAPPauseSelect) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible d'afficher la texture28");
}

//Pour QuitterLaPartie
if(SDL_QueryTexture(texture_QuitterLaPartie, NULL, NULL, &rectangle_QuitterLaPartie.w, &rectangle_QuitterLaPartie.h) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger la texture29");
}

rectangle_QuitterLaPartie.x = (WINDOW_WIDTH - rectangle_QuitterLaPartie.w) / 2;
rectangle_QuitterLaPartie.y = 350;

if(SDL_RenderCopy(*renderer, texture_QuitterLaPartie, NULL, &rectangle_QuitterLaPartie) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible d'afficher la texture29");
}

//Pour QuitterLaPartieSelect
if(SDL_QueryTexture(texture_QuitterLaPartieSelect, NULL, NULL, &rectangle_QuitterLaPartieSelect.w, &rectangle_QuitterLaPartieSelect.h) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible de charger la texture30");
}

rectangle_QuitterLaPartieSelect.x = (WINDOW_WIDTH - rectangle_QuitterLaPartieSelect.w) / 2;
rectangle_QuitterLaPartieSelect.y = 350;

if(SDL_RenderCopy(*renderer, texture_QuitterLaPartieSelect, NULL, &rectangle_QuitterLaPartieSelect) != 0)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_ExitWithError("Impossible d'afficher la texture30");
}

//----------------------------------------------------------------------------------------


SDL_RenderCopy(*renderer, texture_Menu, NULL, &rectangle_Menu);
SDL_RenderPresent(*renderer);
int x = 0; //Numero menu
int tempTab = 0; //Contient l'information si c'est tabbot ou tabJvsJ
// Gestion d'évenement
SDL_bool program_launched = SDL_TRUE;
int **plateau=NULL,i,c,joueur=1,couleur,couleurbot,couleur2,v;
Pos **coor=NULL;
plateau = malloc(9 * sizeof(*plateau));
for (i = 0; i < 9; i++) {
    plateau[i] = (int*)malloc(6 * sizeof(**plateau));
}
coor = malloc(9 * sizeof(*coor));
for (i = 0; i < 9; i++) {
    coor[i] = (int*)malloc(6 * sizeof(**coor));
}
if(coor!=NULL){
    if(chargementcoor(coor)==1){
        if(coor[0][0].x==221 && coor[0][0].y==85){
            printf("\n##Chargment des coordonnees reussi");
        }else{
        printf("\n##Erreur de Chargment des coordonnees !!");
        printf("\nX = %d",coor[0][0].x);
        printf("\nY = %d",coor[0][0].y);
        }
    }else{printf("\n##Fichier impossible à charger !!");}
}else{
    printf("\nErreur d'allocation de coor");
}
    if(plateau!=NULL){
    initialisation(plateau);
    while(program_launched)
    {
        SDL_Event event;

        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_MOUSEMOTION:
                    /*printf("%d / %d\n", event.motion.x, event.motion.y);*/
                    //printf("\nX = %d",x);
                    if(x==100)
                    {
                        if(event.motion.x <= 820 && event.motion.x >= 460 && event.motion.y <= 280 && event.motion.y >= 200)
                        {
                            SDL_RenderCopy(*renderer, texture_ReprendreLaPartieAPPauseSelect, NULL, &rectangle_ReprendreLaPartieAPPauseSelect);
                            SDL_RenderPresent(*renderer);
                            SDL_RenderCopy(*renderer, texture_QuitterLaPartie, NULL, &rectangle_QuitterLaPartie);
                            SDL_RenderPresent(*renderer);
                        }
                        else if(event.motion.x <= 820 && event.motion.x >= 460 && event.motion.y <= 430 && event.motion.y >= 350)
                        {
                            SDL_RenderCopy(*renderer, texture_ReprendreLaPartieAPPause, NULL, &rectangle_ReprendreLaPartieAPPause);
                            SDL_RenderPresent(*renderer);
                            SDL_RenderCopy(*renderer, texture_QuitterLaPartieSelect, NULL, &rectangle_QuitterLaPartieSelect);
                            SDL_RenderPresent(*renderer);
                        }
                        else
                        {
                            SDL_RenderCopy(*renderer, texture_ReprendreLaPartieAPPause, NULL, &rectangle_ReprendreLaPartieAPPause);
                            SDL_RenderPresent(*renderer);
                            SDL_RenderCopy(*renderer, texture_QuitterLaPartie, NULL, &rectangle_QuitterLaPartie);
                            SDL_RenderPresent(*renderer);
                        }

                    }
                    if(x==6 || x==7)
                    {
                        //Animation BoutonPauseSelect
                        if(event.motion.x <= 1229 && event.motion.x >= 1180 && event.motion.y <= 105 && event.motion.y >= 56)
                        {
                            SDL_RenderCopy(*renderer, texture_ButtonPauseSelect, NULL, &rectangle_ButtonPauseSelect);
                            SDL_RenderPresent(*renderer);
                        }
                        else
                        {
                            SDL_RenderCopy(*renderer, texture_ButtonPause, NULL, &rectangle_ButtonPause);
                            SDL_RenderPresent(*renderer);
                        }
                    }
                    if(x==11)
                    {
                        if(event.motion.x <= 631 && event.motion.x >= 592 && event.motion.y <= 381 && event.motion.y >= 364)
                        {
                            if(SDL_RenderClear(*renderer) != 0)
                                SDL_ExitWithError("Effacement rendu echouee");
                            SDL_RenderCopy(*renderer, texture_ReprendreLaPartieOUISelect, NULL, &rectangle_ReprendreLaPartieOUISelect);
                            SDL_RenderPresent(*renderer);
                        }
                        else if(event.motion.x <= 695 && event.motion.x >= 654 && event.motion.y <= 381 && event.motion.y >= 364)
                        {
                            if(SDL_RenderClear(*renderer) != 0)
                                SDL_ExitWithError("Effacement rendu echouee");
                            SDL_RenderCopy(*renderer, texture_ReprendreLaPartieNONSelect, NULL, &rectangle_ReprendreLaPartieNONSelect);
                            SDL_RenderPresent(*renderer);
                        }
                        else
                        {
                            if(SDL_RenderClear(*renderer) != 0)
                                SDL_ExitWithError("Effacement rendu echouee");
                            SDL_RenderCopy(*renderer, texture_ReprendreLaPartie, NULL, &rectangle_ReprendreLaPartie);
                            SDL_RenderPresent(*renderer);
                        }
                    }
                    if(x==21)
                    {
                        if(event.motion.x <= 631 && event.motion.x >= 592 && event.motion.y <= 381 && event.motion.y >= 364)
                        {
                            if(SDL_RenderClear(*renderer) != 0)
                                SDL_ExitWithError("Effacement rendu echouee");
                            SDL_RenderCopy(*renderer, texture_ReprendreLaPartieOUISelect, NULL, &rectangle_ReprendreLaPartieOUISelect);
                            SDL_RenderPresent(*renderer);
                        }
                        else if(event.motion.x <= 695 && event.motion.x >= 654 && event.motion.y <= 381 && event.motion.y >= 364)
                        {
                            if(SDL_RenderClear(*renderer) != 0)
                                SDL_ExitWithError("Effacement rendu echouee");
                            SDL_RenderCopy(*renderer, texture_ReprendreLaPartieNONSelect, NULL, &rectangle_ReprendreLaPartieNONSelect);
                            SDL_RenderPresent(*renderer);
                        }
                        else
                        {
                            if(SDL_RenderClear(*renderer) != 0)
                                SDL_ExitWithError("Effacement rendu echouee");
                            SDL_RenderCopy(*renderer, texture_ReprendreLaPartie, NULL, &rectangle_ReprendreLaPartie);
                            SDL_RenderPresent(*renderer);
                        }
                    }
                    if (x==4 || x==5)
                    {
                        //JetonRougeSelect
                        if(event.motion.x <= 590 && event.motion.x >= 501 && event.motion.y <= 415 && event.motion.y >= 331)
                        {
                            if(SDL_RenderClear(*renderer) != 0)
                                SDL_ExitWithError("Effacement rendu echouee");
                            SDL_RenderCopy(*renderer, texture_RougeSelect, NULL, &rectangle_RougeSelect);
                            SDL_RenderPresent(*renderer);
                        }
                            //JetonJauneSelect
                            else if (event.motion.x <= 774 && event.motion.x >= 685 && event.motion.y <= 415 && event.motion.y >= 331)
                            {
                                if(SDL_RenderClear(*renderer) != 0)
                                    SDL_ExitWithError("Effacement rendu echouee");
                                SDL_RenderCopy(*renderer, texture_JauneSelect, NULL, &rectangle_JauneSelect);
                                SDL_RenderPresent(*renderer);
                            }
                        else
                        {
                            if(SDL_RenderClear(*renderer) != 0)
                                SDL_ExitWithError("Effacement rendu echouee");
                            SDL_RenderCopy(*renderer, texture_ChoixCouleurBot, NULL, &rectangle_ChoixCouleurBot);
                            SDL_RenderPresent(*renderer);
                        }
                    }
                    if(x==10 || x==0){
                        //1JSelect
                        if(event.motion.x <= 820 && event.motion.x >= 464 && event.motion.y <= 273 && event.motion.y >= 197)
                        {
                            if(SDL_RenderClear(*renderer) != 0)
                                SDL_ExitWithError("Effacement rendu echouee");
                            SDL_RenderCopy(*renderer, texture_Menu_1Jselect, NULL, &rectangle_Menu1Jselect);
                            SDL_RenderPresent(*renderer);
                        }
                        //2JSelect
                            else if(event.motion.x <= 820 && event.motion.x >= 464 && event.motion.y <= 375 && event.motion.y >= 298)
                            {
                                if(SDL_RenderClear(*renderer) != 0)
                                    SDL_ExitWithError("Effacement rendu echouee");
                                SDL_RenderCopy(*renderer, texture_Menu_2Jselect, NULL, &rectangle_Menu2Jselect);
                                SDL_RenderPresent(*renderer);
                            }
                        //CreditsSelect
                                else if(event.motion.x <= 820 && event.motion.x >= 464 && event.motion.y <= 515 && event.motion.y >= 440)
                                {
                                    if(SDL_RenderClear(*renderer) != 0)
                                        SDL_ExitWithError("Effacement rendu echouee");
                                    SDL_RenderCopy(*renderer, texture_Menu_CreditsSelect, NULL, &rectangle_MenuCreditsSelect);
                                    SDL_RenderPresent(*renderer);
                                }
                        //Menu
                        else
                        {
                            if(SDL_RenderClear(*renderer) != 0)
                                SDL_ExitWithError("Effacement rendu echouee");
                            SDL_RenderCopy(*renderer, texture_Menu, NULL, &rectangle_Menu);
                            SDL_RenderPresent(*renderer);
                        }
                    }
                    if (x==1)
                    {
                        //FacileSelect
                        if(event.motion.x <= 820 && event.motion.x >= 464 && event.motion.y <= 297 && event.motion.y >= 218)
                        {
                            if(SDL_RenderClear(*renderer) != 0)
                                SDL_ExitWithError("Effacement rendu echouee");
                            SDL_RenderCopy(*renderer, texture_FacileSelect, NULL, &rectangle_FacileSelect);
                            SDL_RenderPresent(*renderer);
                        }
                            //NormalSelect
                            else if(event.motion.x <= 820 && event.motion.x >= 464 && event.motion.y <= 405 && event.motion.y >= 326)
                            {
                                if(SDL_RenderClear(*renderer) != 0)
                                SDL_ExitWithError("Effacement rendu echouee");
                                SDL_RenderCopy(*renderer, texture_NormalSelect, NULL, &rectangle_NormalSelect);
                                SDL_RenderPresent(*renderer);
                            }
                        //NormalFacile
                        else
                        {
                            if(SDL_RenderClear(*renderer) != 0)
                                SDL_ExitWithError("Effacement rendu echouee");
                            SDL_RenderCopy(*renderer, texture_FacileNormal, NULL, &rectangle_FacileNormal);
                            SDL_RenderPresent(*renderer);
                        }
                    }
                    if (x==3)
                    {
                        //FlecheCreditSelect
                        if(event.motion.x <= 908 && event.motion.x >= 872 && event.motion.y <= 490 && event.motion.y >= 461)
                        {
                            if(SDL_RenderClear(*renderer) != 0)
                                SDL_ExitWithError("Effacement rendu echouee");
                            SDL_RenderCopy(*renderer, texture_FlecheCreditSelect, NULL, &rectangle_FlecheCreditSelect);
                            SDL_RenderPresent(*renderer);
                        }
                        //Credits
                        else
                        {
                            if(SDL_RenderClear(*renderer) != 0)
                                SDL_ExitWithError("Effacement rendu echouee");
                            SDL_RenderCopy(*renderer, texture_Credits, NULL, &rectangle_Credits);
                            SDL_RenderPresent(*renderer);
                        }
                    }
                break;
                case SDL_MOUSEBUTTONDOWN:
                    if(x==7)
                    {
                        tempTab = x;
                        if(event.motion.x < 316 && event.motion.x >= 221 && event.motion.y < 646){v=jvsj1(plateau,couleur,couleur2,joueur,0);}
                        if(event.motion.x < 411 && event.motion.x >= 316 && event.motion.y < 646){v=jvsj1(plateau,couleur,couleur2,joueur,1);}
                        if(event.motion.x < 506 && event.motion.x >= 411 && event.motion.y < 646){v=jvsj1(plateau,couleur,couleur2,joueur,2);}
                        if(event.motion.x < 601 && event.motion.x >= 506 && event.motion.y < 646){v=jvsj1(plateau,couleur,couleur2,joueur,3);}
                        if(event.motion.x < 696 && event.motion.x >= 601 && event.motion.y < 646){v=jvsj1(plateau,couleur,couleur2,joueur,4);}
                        if(event.motion.x < 791 && event.motion.x >= 696 && event.motion.y < 646){v=jvsj1(plateau,couleur,couleur2,joueur,5);}
                        if(event.motion.x < 886 && event.motion.x >= 791 && event.motion.y < 646){v=jvsj1(plateau,couleur,couleur2,joueur,6);}
                        if(event.motion.x < 981 && event.motion.x >= 886 && event.motion.y < 646){v=jvsj1(plateau,couleur,couleur2,joueur,7);}
                        if(event.motion.x < 1069 && event.motion.x >= 981 && event.motion.y < 646){v=jvsj1(plateau,couleur,couleur2,joueur,8);}
                        Affiche(renderer,texture_JetonRouge,rectangle_JetonRouge,texture_JetonJaune,rectangle_JetonJaune,plateau,coor);
                        if(victoire(plateau,couleur)==1){
                            x=71;
                            remove("save2J.txt");
                            initialisation(plateau);
                        }else if (victoire(plateau,couleur2)==1){
                            x=72;
                            remove("save2J.txt");
                            initialisation(plateau);
                        }else{
                            if(v==0){
                                if (joueur==1){
                                    joueur=2;
                                }else{
                                    joueur=1;
                                }
                            }
                        }
                        if(event.motion.x <= 1229 && event.motion.x >= 1180 && event.motion.y <= 105 && event.motion.y >= 56)
                        {
                            //Afficher Reprende la partie et Quitter && x=100 (salle pour ce menu)
                            x=100;
                            SDL_RenderCopy(*renderer, texture_ReprendreLaPartieAPPause, NULL, &rectangle_ReprendreLaPartieAPPause);
                            SDL_RenderPresent(*renderer);
                            SDL_RenderCopy(*renderer, texture_QuitterLaPartie, NULL, &rectangle_QuitterLaPartie);
                            SDL_RenderPresent(*renderer);
                        }
                    }
                    if(x==6){
                        tempTab = x;
                        if(event.motion.x < 316 && event.motion.x > 221 && event.motion.y <= 646){jvsb1(plateau,c,couleur,couleurbot,joueur,0);}
                        if(event.motion.x < 411 && event.motion.x > 316 && event.motion.y <= 646){jvsb1(plateau,c,couleur,couleurbot,joueur,1);}
                        if(event.motion.x < 506 && event.motion.x > 411 && event.motion.y <= 646){jvsb1(plateau,c,couleur,couleurbot,joueur,2);}
                        if(event.motion.x < 601 && event.motion.x > 506 && event.motion.y <= 646){jvsb1(plateau,c,couleur,couleurbot,joueur,3);}
                        if(event.motion.x < 696 && event.motion.x > 601 && event.motion.y <= 646){jvsb1(plateau,c,couleur,couleurbot,joueur,4);}
                        if(event.motion.x < 791 && event.motion.x > 696 && event.motion.y <= 646){jvsb1(plateau,c,couleur,couleurbot,joueur,5);}
                        if(event.motion.x < 886 && event.motion.x > 791 && event.motion.y <= 646){jvsb1(plateau,c,couleur,couleurbot,joueur,6);}
                        if(event.motion.x < 981 && event.motion.x > 886 && event.motion.y <= 646){jvsb1(plateau,c,couleur,couleurbot,joueur,7);}
                        if(event.motion.x < 1069 && event.motion.x >= 981 && event.motion.y <= 646){jvsb1(plateau,c,couleur,couleurbot,joueur,8);}
                        Affiche(renderer,texture_JetonRouge,rectangle_JetonRouge,texture_JetonJaune,rectangle_JetonJaune,plateau,coor);
                        if(victoire(plateau,couleur)==1){
                            x=61;
                            remove("saveBot.txt");
                            initialisation(plateau);
                        }else if (victoire(plateau,couleurbot)==1){
                            x=62;
                            remove("saveBot.txt");
                            initialisation(plateau);
                        }
                        if(event.motion.x <= 1229 && event.motion.x >= 1180 && event.motion.y <= 105 && event.motion.y >= 56)
                        {
                            //Afficher Reprende la partie et Quitter && x=100 (salle pour ce menu)
                            x=100;
                            SDL_RenderCopy(*renderer, texture_ReprendreLaPartieAPPause, NULL, &rectangle_ReprendreLaPartieAPPause);
                            SDL_RenderPresent(*renderer);
                            SDL_RenderCopy(*renderer, texture_QuitterLaPartie, NULL, &rectangle_QuitterLaPartie);
                            SDL_RenderPresent(*renderer);
                        }
                    }
                                        if(x==100)
                    {
                        if(tempTab == 7)
                        {
                            if(event.motion.x <= 820 && event.motion.x >= 460 && event.motion.y <= 280 && event.motion.y >= 200)
                            {
                                //Réaffiche le puissance 4 actualisé affiche() + un clear je pense + bouton pause.
                                chargement(plateau,&joueur,&couleur,"save2J.txt");
                                if(SDL_RenderClear(*renderer) != 0)
                                    SDL_ExitWithError("Effacement rendu echouee");
                                SDL_RenderCopy(*renderer, texture_PlateauVierge, NULL, &rectangle_PlateauVierge);
                                SDL_RenderPresent(*renderer);
                                SDL_RenderCopy(*renderer, texture_ButtonPause, NULL, &rectangle_ButtonPause);
                                SDL_RenderPresent(*renderer);
                                Affiche(renderer,texture_JetonRouge,rectangle_JetonRouge,texture_JetonJaune,rectangle_JetonJaune,plateau,coor);
                                x=7;
                            }
                            else if(event.motion.x <= 820 && event.motion.x >= 460 && event.motion.y <= 430 && event.motion.y >= 350)
                            {
                                x=0;
                                if(SDL_RenderClear(*renderer) != 0)
                                    SDL_ExitWithError("Effacement rendu echouee");
                                SDL_RenderCopy(*renderer, texture_Menu, NULL, &rectangle_Menu);
                                SDL_RenderPresent(*renderer);
                            }
                        }
                        if(tempTab == 6)
                        {
                            if(event.motion.x <= 820 && event.motion.x >= 460 && event.motion.y <= 280 && event.motion.y >= 200)
                            {
                                //Réaffiche le puissance 4 actualisé affiche() + un clear je pense + bouton pause.
                                c=chargement(plateau,&joueur,&couleur,"saveBot.txt");
                                if(SDL_RenderClear(*renderer) != 0)
                                    SDL_ExitWithError("Effacement rendu echouee");
                                SDL_RenderCopy(*renderer, texture_PlateauVierge, NULL, &rectangle_PlateauVierge);
                                SDL_RenderPresent(*renderer);
                                SDL_RenderCopy(*renderer, texture_ButtonPause, NULL, &rectangle_ButtonPause);
                                SDL_RenderPresent(*renderer);
                                Affiche(renderer,texture_JetonRouge,rectangle_JetonRouge,texture_JetonJaune,rectangle_JetonJaune,plateau,coor);
                                x=6;
                            }
                            else if(event.motion.x <= 820 && event.motion.x >= 460 && event.motion.y <= 430 && event.motion.y >= 350)
                            {
                                x=0;
                                if(SDL_RenderClear(*renderer) != 0)
                                    SDL_ExitWithError("Effacement rendu echouee");
                                SDL_RenderCopy(*renderer, texture_Menu, NULL, &rectangle_Menu);
                                SDL_RenderPresent(*renderer);
                            }
                        }
                    }
                    if (x==4 || x==5)
                    {
                        //ChoixRouge
                        if(event.motion.x <= 590 && event.motion.x >= 501 && event.motion.y <= 415 && event.motion.y >= 331)
                        {
                            x = 6;
                            couleur = 1;
                            couleurbot=2;
                            printf("\ncouleur rouge -> %d\n", couleur);
                            if(SDL_RenderClear(*renderer) != 0)
                                SDL_ExitWithError("Effacement rendu echouee");
                            SDL_RenderCopy(*renderer, texture_PlateauVierge, NULL, &rectangle_PlateauVierge);
                            SDL_RenderPresent(*renderer);
                            SDL_RenderCopy(*renderer, texture_ButtonPause, NULL, &rectangle_ButtonPause);
                            SDL_RenderPresent(*renderer);
                            sauvegarde(plateau,1,couleur,c,"saveBot.txt");
                        }
                        //ChoixJaune
                        if (event.motion.x <= 774 && event.motion.x >= 685 && event.motion.y <= 415 && event.motion.y >= 331)
                        {
                            x = 6;
                            couleur = 2;
                            couleurbot=1;
                            printf("\ncouleur jaune -> %d\n", couleur);
                            if(SDL_RenderClear(*renderer) != 0)
                                SDL_ExitWithError("Effacement rendu echouee");
                            SDL_RenderCopy(*renderer, texture_PlateauVierge, NULL, &rectangle_PlateauVierge);
                            SDL_RenderPresent(*renderer);
                            SDL_RenderCopy(*renderer, texture_ButtonPause, NULL, &rectangle_ButtonPause);
                            SDL_RenderPresent(*renderer);
                            sauvegarde(plateau,1,couleur,c,"saveBot.txt");
                        }
                    }
                    if (x==1)
                    {
                    //Partie en mode Facile
                            //affiche voulez-vous reprendre la partie si oui fait r=1, sinon fait r=0
                            if(event.motion.x <= 820 && event.motion.x >= 464 && event.motion.y <= 297 && event.motion.y >= 218)
                            {
                                    printf("mode facile selectionne\n");
                                    x=4;
                                    c=1;
                                    if(SDL_RenderClear(*renderer) != 0)
                                        SDL_ExitWithError("Effacement rendu echouee");
                                    SDL_RenderCopy(*renderer, texture_ChoixCouleurBot, NULL, &rectangle_ChoixCouleurBot);
                                    SDL_RenderPresent(*renderer);
                            }
                            //Partie en mode Normal
                            if(event.motion.x <= 820 && event.motion.x >= 464 && event.motion.y <= 405 && event.motion.y >= 326)
                            {
                                    printf("mode normal selectionne\n");
                                    x=5;
                                    c=2;
                                    if(SDL_RenderClear(*renderer) != 0)
                                        SDL_ExitWithError("Effacement rendu echouee");
                                    SDL_RenderCopy(*renderer, texture_ChoixCouleurBot, NULL, &rectangle_ChoixCouleurBot);
                                    SDL_RenderPresent(*renderer);
                            }
                    }
                    if (x==0){
                        if(event.motion.x <= 820 && event.motion.x >= 464 && event.motion.y <= 273 && event.motion.y >= 197)
                        {
                            if(reprendre1("saveBot.txt")==0){
                                x=10;
                            }else{
                                x=11;
                            }
                        }else if(event.motion.x <= 820 && event.motion.x >= 464 && event.motion.y <= 375 && event.motion.y >= 298)
                            {
                                if(reprendre1("save2J.txt")==0){
                                    x=10;
                                }else{
                                    x=21;
                                }
                            }
                        else if(event.motion.x <= 820 && event.motion.x >= 464 && event.motion.y <= 515 && event.motion.y >= 440)
                                    {
                                        x=10;
                                    }
                    }
                    if(x==11){
                        if(event.motion.x <= 631 && event.motion.x >= 592 && event.motion.y <= 381 && event.motion.y >= 364)
                        {
                            c=chargement(plateau,&joueur,&couleur,"saveBot.txt");
                            if(SDL_RenderClear(*renderer) != 0)
                                SDL_ExitWithError("Effacement rendu echouee");
                            SDL_RenderCopy(*renderer, texture_PlateauVierge, NULL, &rectangle_PlateauVierge);
                            SDL_RenderPresent(*renderer);
                            SDL_RenderCopy(*renderer, texture_ButtonPause, NULL, &rectangle_ButtonPause);
                            SDL_RenderPresent(*renderer);
                            Affiche(renderer,texture_JetonRouge,rectangle_JetonRouge,texture_JetonJaune,rectangle_JetonJaune,plateau,coor);
                            x=6;
                        }
                        else if(event.motion.x <= 695 && event.motion.x >= 654 && event.motion.y <= 381 && event.motion.y >= 364)
                        {
                            initialisation(plateau);
                            x=1;
                        }
                    }
                    if(x==21){
                        if(event.motion.x <= 631 && event.motion.x >= 592 && event.motion.y <= 381 && event.motion.y >= 364)
                        {
                            chargement(plateau,&joueur,&couleur,"save2J.txt");
                            if(SDL_RenderClear(*renderer) != 0)
                                SDL_ExitWithError("Effacement rendu echouee");
                            SDL_RenderCopy(*renderer, texture_PlateauVierge, NULL, &rectangle_PlateauVierge);
                            SDL_RenderPresent(*renderer);
                            SDL_RenderCopy(*renderer, texture_ButtonPause, NULL, &rectangle_ButtonPause);
                            SDL_RenderPresent(*renderer);
                            Affiche(renderer,texture_JetonRouge,rectangle_JetonRouge,texture_JetonJaune,rectangle_JetonJaune,plateau,coor);
                            x=7;
                        }
                        else if(event.motion.x <= 695 && event.motion.x >= 654 && event.motion.y <= 381 && event.motion.y >= 364)
                        {
                            initialisation(plateau);
                            x=2;
                            if(SDL_RenderClear(*renderer) != 0)
                                SDL_ExitWithError("Effacement rendu echouee");
                            SDL_RenderCopy(*renderer, texture_ChoixCouleur2joueurs, NULL, &rectangle_ChoixCouleur2joueurs);
                            SDL_RenderPresent(*renderer);
                        }
                    }
                    if (x==3)
                    {
                        //FlecheCreditSelect
                        if(event.motion.x <= 908 && event.motion.x >= 872 && event.motion.y <= 490 && event.motion.y >= 461)
                        {
                            if(SDL_RenderClear(*renderer) != 0)
                                SDL_ExitWithError("Effacement rendu echouee");
                            SDL_RenderCopy(*renderer, texture_Menu, NULL, &rectangle_Menu);
                            SDL_RenderPresent(*renderer);
                            x=0;
                        }
                    }
                    if(x==10)
                    {
                        //FacileNormal
                            if(event.motion.x <= 820 && event.motion.x >= 464 && event.motion.y <= 273 && event.motion.y >= 197)
                            {
                                do{
                                    x=1;
                                    if(SDL_RenderClear(*renderer) != 0)
                                        SDL_ExitWithError("Effacement rendu echouee");
                                    SDL_RenderCopy(*renderer, texture_FacileNormal, NULL, &rectangle_FacileNormal);
                                    SDL_RenderPresent(*renderer);
                                }while(x==0);
                            }
                                //ChoixCouleur2joueurs
                                else if(event.motion.x <= 820 && event.motion.x >= 464 && event.motion.y <= 375 && event.motion.y >= 298)
                                {
                                    x=2;
                                    if(SDL_RenderClear(*renderer) != 0)
                                        SDL_ExitWithError("Effacement rendu echouee");
                                    SDL_RenderCopy(*renderer, texture_ChoixCouleur2joueurs, NULL, &rectangle_ChoixCouleur2joueurs);
                                    SDL_RenderPresent(*renderer);
                                }
                                    //Credits
                                    else if(event.motion.x <= 820 && event.motion.x >= 464 && event.motion.y <= 515 && event.motion.y >= 440)
                                    {
                                        x=3;
                                        if(SDL_RenderClear(*renderer) != 0)
                                            SDL_ExitWithError("Effacement rendu echouee");
                                        SDL_RenderCopy(*renderer, texture_Credits, NULL, &rectangle_Credits);
                                        SDL_RenderPresent(*renderer);
                                    }
                    }
                break;
                case SDL_KEYDOWN:
                    if (x==1 || x==2 || x==4 || x==5 || x==61 || x==62 || x==71 || x==72)
                    {
                        if(event.key.keysym.sym == SDLK_ESCAPE)
                        {
                            if(SDL_RenderClear(*renderer) != 0)
                                SDL_ExitWithError("Effacement rendu echouee");
                            SDL_RenderCopy(*renderer, texture_Menu, NULL, &rectangle_Menu);
                            SDL_RenderPresent(*renderer);
                            x=0;
                        }
                    }
                    if (x==2)
                    {
                        sauvegarde(plateau,1,couleur,-1,"save2J.txt");
                        if(event.key.keysym.sym == SDLK_SPACE){
                            if(pileouface() == 1)
                            {
                                x=99; // Salle/Etat d'attente ou il ne se passera jamais rien
                                couleur=1;
                                couleur2=2;
                                joueur=1;
                                if(SDL_RenderClear(*renderer) != 0)
                                    SDL_ExitWithError("Effacement rendu echouee");
                                SDL_RenderCopy(*renderer, texture_Joueur1Rouge, NULL, &rectangle_Joueur1Rouge);
                                SDL_RenderPresent(*renderer);
                                SDL_Delay(3000);
                                x=7;
                                if(SDL_RenderClear(*renderer) != 0)
                                    SDL_ExitWithError("Effacement rendu echouee");
                                SDL_RenderCopy(*renderer, texture_PlateauVierge, NULL, &rectangle_PlateauVierge);
                                SDL_RenderPresent(*renderer);
                                SDL_RenderCopy(*renderer, texture_ButtonPause, NULL, &rectangle_ButtonPause);
                                SDL_RenderPresent(*renderer);
                            }
                                else if(pileouface() == 2)
                                {
                                    x=99;
                                    couleur=2;
                                    couleur2=1;
                                    joueur=1;
                                    if(SDL_RenderClear(*renderer) != 0)
                                        SDL_ExitWithError("Effacement rendu echouee");
                                    SDL_RenderCopy(*renderer, texture_Joueur1Jaune, NULL, &rectangle_Joueur1Jaune);
                                    SDL_RenderPresent(*renderer);
                                    SDL_Delay(3000);
                                    x=7;
                                    if(SDL_RenderClear(*renderer) != 0)
                                        SDL_ExitWithError("Effacement rendu echouee");
                                    SDL_RenderCopy(*renderer, texture_PlateauVierge, NULL, &rectangle_PlateauVierge);
                                    SDL_RenderPresent(*renderer);
                                    SDL_RenderCopy(*renderer, texture_ButtonPause, NULL, &rectangle_ButtonPause);
                                    SDL_RenderPresent(*renderer);
                                }
                            else
                            {
                                printf("ERREUR PILE OU FACE");
                                return EXIT_FAILURE;
                            }
                        }
                    }
                break;
                case SDL_QUIT:
                    if(SDL_RenderClear(*renderer) != 0)
                        SDL_ExitWithError("Effacement rendu echouee");
                    program_launched = SDL_FALSE;
                    break;
                default:
                    break;
            }
            if(x==61 || x==71)
            {
                SDL_RenderCopy(*renderer, texture_Joueur1Gagne, NULL, &rectangle_Joueur1Gagne);
                SDL_RenderPresent(*renderer);
                initialisation(plateau);
            }
                else if(x==62)
                {
                    SDL_RenderCopy(*renderer, texture_VousAvezPerdu, NULL, &rectangle_VousAvezPerdu);
                    SDL_RenderPresent(*renderer);
                    initialisation(plateau);
                }
                    else if(x==72)
                    {
                        SDL_RenderCopy(*renderer, texture_Joueur2Gagne, NULL, &rectangle_Joueur2Gagne);
                        SDL_RenderPresent(*renderer);
                        initialisation(plateau);
                    }
        }
    }
}

/*-----------------------------------------------------------------------------------------------------*/

    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_Quit();

    return EXIT_SUCCESS;
}

void SDL_ExitWithError(const char *message)
{
    SDL_Log("Erreur %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}

//Commandes à exécuter dans le dossier Puissance 4
//cd C:\Users\Mathis\Documents\cours\DEVA\TP\code_image\SDL
//Commande de compilation : gcc src/main_non_bug7.6.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_mixer
//Commande de lancement du programme : bin\prog
