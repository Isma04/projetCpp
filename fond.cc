#include "fond.hh"
#include <string>
#include <iostream>
using namespace std;
SDL_Surface *ecran, *imageDeFond, *zozor;

void Fond::init(){
	
	SDL_Init(SDL_INIT_VIDEO);
	ecran = SDL_SetVideoMode(_longueurEcran, _hauteurEcran, 32, SDL_HWSURFACE);
	imageDeFond = SDL_LoadBMP("bahamas.bmp");
	zozor = SDL_LoadBMP("goku1.bmp");
	SDL_SetColorKey(zozor, SDL_SRCCOLORKEY, SDL_MapRGB(zozor->format, 0, 0, 0));
}

void Fond::anime(int x, int y) //position x,y du perso
{
	SDL_Rect positionFond, positionZozor;
	//int avanceX = 1, avanceY = 1; // Ces variables diront si zozor doit avancer ou reculer.
	Joueur j(x,y,"zoro");
	int a = x;
	int b = y;
	positionFond.x = 0;
	positionFond.y = 0;

	positionZozor.x = x;
	positionZozor.y = y;

	SDL_EnableKeyRepeat(10,5);
	while (1) {

		SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // Dessiner le fond
		SDL_BlitSurface(zozor, NULL, ecran, &positionZozor); // Dessiner zozor
		SDL_Flip(ecran); // On affiche réellement l'image.
		input_handle(a, b, j); // On appelle le gestionnaire d'évènements.
		
		SDL_Delay(10); //attend 10ms pour rafraichir la page 
		j.setX(a);
		j.setY(b);

		//j.setY(a); // ca le deplace EN DIAGONALE LA POSITION Y CHANGE !!!!!! 

		positionZozor.x = j.getX();
		positionZozor.y = j.getY();
		cout<<positionZozor.x<<endl;
		cout<<positionZozor.y<<endl;
		//cout<< " hello voila le b" << endl;
		//cout<<b<<endl;
	}
	//cout<<positionZozor.x<<endl;

}


// void Fond::input_handle() // FOND A DONNER POUR DEPLACEMENT 
// {
// 	Joueur j(0,0,"zoro");
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
//                 	j.Deplacement(3,0,f);
//                 	break;
//                 case SDLK_LSHIFT:
//                 	j.Deplacement(-3,0,f);
//                 	break;
//                 default:
//                 	break;

//             }
//             break;
// 		}
// 	}


//}


void Fond::input_handle(int &a, int &b, Joueur j) // FOND A DONNER POUR DEPLACEMENT 
{
	//Joueur j(0,0,"zoro");
	SDL_Event event;
	//int a=j.getX();
	//int b=j.getY();
	//int c = 0;
	//int c
	
	while (SDL_PollEvent(&event)) {

		switch (event.type) {
		case SDL_QUIT:
			SDL_Quit();
			exit(0);
			break;
		case SDL_KEYDOWN:
           switch (event.key.keysym.sym)
            {
                case SDLK_ESCAPE:  //Appui sur la touche Echap, on arrête le programme 
                    SDL_Quit();
                    cout<<"exit bye bye"<<endl;
                    exit(0);                
                    break;
                case SDLK_RIGHT:

                	cout<<"exit bye suz"<<endl;
                	j.Deplacement(3,0,_longueurEcran,_hauteurEcran);
                	a = j.getX();
                	//c[0]=a;

                   	break;
                case SDLK_LEFT:
                	j.Deplacement(-3,0,_longueurEcran,_hauteurEcran);
                	a = j.getX();
                	//c[1]=b;
                	break;
                case SDLK_UP:
                	j.Deplacement(0,3,_longueurEcran,_hauteurEcran);
                	b = j.getY();
                	break;
                case SDLK_DOWN:
                	j.Deplacement(0,-3,_longueurEcran,_hauteurEcran);
                	b = j.getY();
                	break;
                default:
                	break;

            }
            break;
        default:
        	break;    
		}
		      
	}
	//return a;

}

