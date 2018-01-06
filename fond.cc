#include "fond.hh"
//#include <string>
#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <iterator>

using namespace std;
SDL_Surface *ecran, *imageDeFond, *zozor;
int HAUTEUR_PERSO;
int LG_PERSO;
// int SOL;

void Fond::init(int &HAUTEUR_PERSO, int &LG_PERSO, int &SOL){
	
	SDL_Init(SDL_INIT_VIDEO);
	ecran = SDL_SetVideoMode(_longueurEcran, _hauteurEcran, 32, SDL_HWSURFACE);
	imageDeFond = SDL_LoadBMP("image/bahamas.bmp");
	zozor = SDL_LoadBMP("image/goku1.bmp");
	SDL_SetColorKey(zozor, SDL_SRCCOLORKEY, SDL_MapRGB(zozor->format, 0, 0, 0));
	tailleBMP("image/goku1.bmp", HAUTEUR_PERSO, LG_PERSO);
	SOL = 390 - HAUTEUR_PERSO;
	cout << HAUTEUR_PERSO << endl;
	cout << LG_PERSO << endl;
	cout << SOL << endl;
}

// void Fond::anime(int x, int y, const int SOL ) //position x,y du perso
// {
// 	SDL_Rect positionFond, positionZozor;
// 	Joueur j(x,y,"zoro", 5, 15, 0.5); // augmentation de la valeur l'impulsion pour que ca fasse un gros saut 
// 	int a = x;
// 	int b = y;
// 	positionFond.x = 0;
// 	positionFond.y = 0;

// 	positionZozor.x = x;
// 	positionZozor.y = y;

// 	cout << SOL << "anime" << endl; 
// 	SDL_EnableKeyRepeat(10,5);
// 	while (1) {

// 		SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // Dessiner le fond
// 		SDL_BlitSurface(zozor, NULL, ecran, &positionZozor); // Dessiner zozor
// 		SDL_Flip(ecran); // On affiche réellement l'image.
// 		input_handle(a, b, j, SOL); // On appelle le gestionnaire d'évènements.

// 		SDL_Delay(10); //attend 10ms pour rafraichir la page 
	

		
// 	    if (positionZozor.y < 70)
// 		{
// 			while(1){
// 			j.setImp(0);
// 			positionZozor.y = j.getY();
// 			j.setY(SOL); 
// 			}
// 		}
// 		else{
// 		positionZozor.x = j.getX();
// 		positionZozor.y = j.getY();
// 		j.setY(b);
// 		}
	

// 		j.setX(a);
// 		j.setImp(10);
// 		j.setV(2.5);
// 		j.setP(5);
		
// 	}

// }

void Fond::anime(int x, int y, const int SOL ) //position x,y du perso
{
	SDL_Rect positionFond, positionZozor;
	int v = 0;
	Joueur j(x,y,"zoro", v, 12, 1); // augmentation de la valeur l'impulsion pour que ca fasse un gros saut 
	int a = x;
	int b = y;
	int saut = 0; //on est au sol
	positionFond.x = 0;
	positionFond.y = 0;

	positionZozor.x = x;
	positionZozor.y = y;

	cout << SOL << "anime" << endl; 
	SDL_EnableKeyRepeat(10,5);
	while (1) {

		SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // Dessiner le fond
		SDL_BlitSurface(zozor, NULL, ecran, &positionZozor); // Dessiner zozor
		SDL_Flip(ecran); // On affiche réellement l'image.
		input_handle(a, b, v, j, SOL, saut); // On appelle le gestionnaire d'évènements.

		SDL_Delay(10); //attend 10ms pour rafraichir la page 
	

		
	 //    if (positionZozor.y < 70)
		// {
		// 	j.setImp(0);
		// 	positionZozor.y = j.getY();
		// 	j.setY(SOL); 
			

		// }
		// else{
		// 	positionZozor.x = j.getX();
		// 	positionZozor.y = j.getY();
		// 	j.setY(b);
		// }
	

		j.setX(a);
		j.setY(b);
		j.setV(v);
		positionZozor.x = a;
		positionZozor.y = b;
		// j.setImp(10);
		// j.setV(2.5);
		// j.setP(5);
		
	}

}



void Fond::input_handle(int &a, int &b, int &v, Joueur j, const int SOL, int &sautencours) 
{
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
                case SDLK_ESCAPE:  //Appui sur la touche Echap, on arrête le programme 
                    SDL_Quit();
                    cout<<"exit bye bye"<<endl;
                    exit(0);                
                    break;
                case SDLK_RIGHT:

                	cout<<"exit bye suz"<<endl;
                	j.Deplacement(1,0,_longueurEcran,_hauteurEcran, sautencours);
                	a = j.getX();
                	b = j.getY();
                	v = j.getV();
                	

                   	break;
                case SDLK_LEFT:
                	j.Deplacement(-1,0,_longueurEcran,_hauteurEcran, sautencours);
                	a = j.getX();
                	b = j.getY();
                	v = j.getV();
                	
                	break;
                case SDLK_UP:
                	j.saut();
                	v = j.getV();
                	sautencours = 1; //on commence un saut
                	                	
                	break;
  
      //           case SDLK_DOWN:
      //           cout << SOL << endl;
						// j.chute(SOL);
      //            	b = j.getY();
						// a = j.getX();
      //            	break;
                default:
                	break;

            }
            break;
        default:
        	break;    
		}
		      
	}


}

void Fond::tailleBMP(const std::string &file, int &h, int &lg){

	static constexpr size_t HEADER_SIZE = 54;

    std::ifstream bmp(file, std::ios::binary);

    std::array<char, HEADER_SIZE> header;
    bmp.read(header.data(), header.size());

    lg = *reinterpret_cast<uint32_t *>(&header[18]);
    h = *reinterpret_cast<uint32_t *>(&header[22]);

	
}

