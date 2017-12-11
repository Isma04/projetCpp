#include <stdio.h>
#include <SDL/SDL.h>

//int longueurEcran = 690;
//int hauteurEcran = 390;
//SDL_Surface *ecran, *imageDeFond, *zozor;
/*
 * Fonction pour initialiser SDL
 * et les variables globales.
 */
// void init(void)
// {
// 	SDL_Init(SDL_INIT_VIDEO);
// 	ecran = SDL_SetVideoMode(longueurEcran, hauteurEcran, 32, SDL_HWSURFACE);
// 	imageDeFond = SDL_LoadBMP("bahamas.bmp");
// 	zozor = SDL_LoadBMP("goku_mini.bmp");
// 	SDL_SetColorKey(zozor, SDL_SRCCOLORKEY, SDL_MapRGB(zozor->format, 0, 0, 0));
// }

/*
 * Fonction pour être à l'écoute
 * de l'événement SDL_Quit.
 */
// void input_handle(void)
// {
// 	j = Joueur(0,0,"zoro");
// 	SDL_Event event;

// 	while (SDL_PollEvent(&event)) {

// 		switch (event.type) {
// 		case SDL_QUIT:
// 			SDL_Quit();
// 			exit(0);
// 			break;
// 		case SDL_KEYDOWN:
//            switch (event.key.keysym.sym)
//             {
//                 case SDLK_ESCAPE:  Appui sur la touche Echap, on arrête le programme 
//                     SDL_Quit();
//                     exit(0);
//                     break;
//                 case SDLK_RSHIFT:
//                 	j.Deplacement(3,0);
//                 	break;
//                 case SDLK_LSHIFT:
//                 	j.Deplacement(-3,0);
//                 	break;

//             }
//             break;
// 		}
// 	}


// }

/*
 * La fonction qui fera l'animation
 */

// void anime(int x, int y) //position x,y du perso
// {
// 	SDL_Rect positionFond, positionZozor;
// 	int avanceX = 1, avanceY = 1; // Ces variables diront si zozor doit avancer ou reculer.

// 	positionFond.x = 0;
// 	positionFond.y = 0;

// 	positionZozor.x = x;
// 	positionZozor.y = y;


// 	while (1) {

// 		SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // Dessiner le fond
// 		SDL_BlitSurface(zozor, NULL, ecran, &positionZozor); // Dessiner zozor

// 		if (avanceX) {
// 			positionZozor.x++; // Si avance est à 1 alors on incrémente x
// 		} else {
// 			positionZozor.x--; // Sinon on décrémente x 
// 		}

// 		if (avanceY) {
// 			positionZozor.y++;
// 		} else {
// 			positionZozor.y--;
// 		}

//                 /*
//                  * Arrivé à l'une des extrémités, on change la valeur de avance
                 
// /*
// 		if (positionZozor.x == ecran->w - zozor->w - 1)
// 			avanceX = 0;
// 		else if (positionZozor.x == 0)
// 			avanceX = 1;

// 		if (positionZozor.y == ecran->h - zozor->h - 1)
// 			avanceY = 0;
// 		else if (positionZozor.y == 0)
// 			avanceY = 1;
// */
// 		SDL_Flip(ecran); // On affiche réellement l'image.
// 		input_handle(); // On appelle le gestionnaire d'évènements.
// 		//SDL_Delay(10);
// 	}
// }

int main(void)
{
	init();

	anime();
	return 0;
}
