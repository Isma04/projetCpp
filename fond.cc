#include "fond.hh"


SDL_Surface *ecran, *imageDeFond, *zozor;

void Fond::init(){
	
	SDL_Init(SDL_INIT_VIDEO);
	ecran = SDL_SetVideoMode(_longueurEcran, _hauteurEcran, 32, SDL_HWSURFACE);
	imageDeFond = SDL_LoadBMP("bahamas.bmp");
	zozor = SDL_LoadBMP("goku_mini.bmp");
	SDL_SetColorKey(zozor, SDL_SRCCOLORKEY, SDL_MapRGB(zozor->format, 0, 0, 0));
}

void Fond::anime(int x, int y) //position x,y du perso
{
	SDL_Rect positionFond, positionZozor;
	//int avanceX = 1, avanceY = 1; // Ces variables diront si zozor doit avancer ou reculer.

	positionFond.x = 0;
	positionFond.y = 0;

	positionZozor.x = x;
	positionZozor.y = y;


	while (1) {

		SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // Dessiner le fond
		SDL_BlitSurface(zozor, NULL, ecran, &positionZozor); // Dessiner zozor
		SDL_Flip(ecran); // On affiche réellement l'image.
		input_handle(); // On appelle le gestionnaire d'évènements.
		//SDL_Delay(10);
	}
}


void Fond::input_handle() // FOND A DONNER POUR DEPLACEMENT 
{
	Joueur j(0,0,"zoro");
	SDL_Event event;

	while (SDL_PollEvent(&event)) {

		switch (event.type) {
		case SDL_QUIT:
			SDL_Quit();
			exit(0);
			break;
		case SDL_KEYDOWN:
           switch (event.key.keysym.sym)
            {
                case SDLK_ESCAPE: /* Appui sur la touche Echap, on arrête le programme */
                    SDL_Quit();
                    exit(0);
                    break;
                case SDLK_RSHIFT:
                	j.Deplacement(3,0,f);
                	break;
                case SDLK_LSHIFT:
                	j.Deplacement(-3,0,f);
                	break;
                default:
                	break;

            }
            break;
		}
	}


}