#include "fond.hh"
#include "mur.hh"
//#include <string>
#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <iterator>
#include "piece.hh"
using namespace std;
SDL_Surface *ecran, *imageDeFond, *zozor, *petitepiece, *ecriture, *wall;
int HAUTEUR_PERSO;
int LG_PERSO;
// int SOL;

//Pour afficher le score
void PrintSDL(SDL_Surface* font,SDL_Surface* dest,int x,int y,const char* text,...)
{ // l'image doit faire 16 * 14 caractères.
    char buf[500];
    int i,len;
    SDL_Rect Rsrc,Rdst;
    va_list args;
    va_start(args,text);
    vsprintf(buf,text,args);
    va_end(args);
    Rsrc.w = font->w/16;
    Rsrc.h = font->h/14;
    len = (int)strlen(buf);
    for(i=0;i<len;i++)
    {
        Rsrc.x = Rsrc.w*((unsigned char)(buf[i])%16);
        Rsrc.y = Rsrc.h*((unsigned char)(buf[i])/16-2);  // on saute les 31 premiers codes ASCII
        Rdst.x = x;
        Rdst.y = y;
        SDL_BlitSurface(font,&Rsrc,dest,&Rdst);
        x+=Rsrc.w;
    }
}


void Fond::init(int &HAUTEUR_PERSO, int &LG_PERSO, int &SOL){
	
	SDL_Init(SDL_INIT_VIDEO);
	ecran = SDL_SetVideoMode(_longueurEcran, _hauteurEcran, 32, SDL_HWSURFACE);
	imageDeFond = SDL_LoadBMP("image/bahamas.bmp");
	ecriture=SDL_LoadBMP("image/font.bmp"); //score
	zozor = SDL_LoadBMP("image/goku1.bmp");
	petitepiece = SDL_LoadBMP("image/pieceMini.bmp");
	wall = SDL_LoadBMP("image/mur.bmp");
	SDL_SetColorKey(zozor, SDL_SRCCOLORKEY, SDL_MapRGB(zozor->format, 0, 0, 0));
	SDL_SetColorKey(petitepiece, SDL_SRCCOLORKEY, SDL_MapRGB(petitepiece->format, 255, 255, 255));
	SDL_SetColorKey(wall, SDL_SRCCOLORKEY, SDL_MapRGB(wall->format, 255, 255, 255));
	tailleBMP("image/goku1.bmp", HAUTEUR_PERSO, LG_PERSO);
	SOL = 390 - HAUTEUR_PERSO;

}



void Fond::anime(int x, int y, const int SOL ) //position x,y du perso
{
	SDL_Rect positionFond, positionZozor, positionPiece, positionMur;
	int v = 0;
	Joueur j(x,y,"zoro", v, 18, 1); // augmentation de la valeur l'impulsion pour que ca fasse un gros saut 
   Piece p(0,0,10);
	Mur M(0,0,12);
	int a = x;
	int b = y;
	int saut = 0; //on est au sol
	positionFond.x = 0;
	positionFond.y = 0;
	
	M.RandomPos();

	positionZozor.x = x;
	positionZozor.y = y;

	// int max = 350;
	// int min = 15;

	// srand(time(NULL));
	// int r1 = (rand() % (max - min + 1)) + min;
 //    int r2=  (rand() % (max - min + 1)) + min;

	// positionPiece.x = r1;
	// positionPiece.y = r2;
    p.RandomPos();
    positionPiece.x = p.getX();
    positionPiece.y = p.getY(); 

	SDL_EnableKeyRepeat(10,5);

	while (1) {

		SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // Dessiner le fond
		SDL_BlitSurface(zozor, NULL, ecran, &positionZozor); // Dessiner zozor
		SDL_BlitSurface(petitepiece, NULL, ecran, &positionPiece);
		SDL_BlitSurface(wall, NULL, ecran, &positionMur);

		

		int S=j.getScore();
		PrintSDL(ecriture,ecran,500,20,"Score : %d ", S);

		SDL_Flip(ecran); // On affiche réellement l'image.
		input_handle(a, b, v, j, SOL, saut); // On appelle le gestionnaire d'évènements.

		SDL_Delay(15); //attend 10ms pour rafraichir la page 
	

		j.setX(a);
		j.setY(b);
		j.setV(v);
		positionZozor.x = a;
		positionZozor.y = b;
		
		if (j.check_collision(positionZozor, positionPiece) == true)
		{
			j.setScore(S+10);
			// r1 = (rand() % (max - min + 1)) + min;
   //  	    r2=  (rand() % (max - min + 1)) + min;
			// positionPiece.x = r1;
			// positionPiece.y = r2;

            p.RandomPos();
            positionPiece.x = p.getX();
            positionPiece.y = p.getY(); 
            // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! A AJOUTER POUR QUE LA PIECE N APPARAISSE PAS DIRECT SUR LE PERSO 
            // while (check_collision(positionZozor, positionPiece) == true){

            // p.RandomPos();
            // positionPiece.x = p.getX();
            // positionPiece.y = p.getY(); 
            // }
		}
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
                    exit(0);                
                    break;
                case SDLK_RIGHT:

                	j.Deplacement(3,0,_longueurEcran,_hauteurEcran, sautencours);
                	a = j.getX();
                	b = j.getY();
                	v = j.getV();
                	

                   	break;
                case SDLK_LEFT:
                	j.Deplacement(-3,0,_longueurEcran,_hauteurEcran, sautencours);
                	a = j.getX();
                	b = j.getY();
                	v = j.getV();
                	
                	break;
                case SDLK_UP:
                	
                	j.saut();
                	v = j.getV();
                	sautencours = 1; //on commence un saut
                	                	
                	break;
  
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

// bool Fond::check_collision( SDL_Rect &A, SDL_Rect &B )
// {
//     //Les cotes des rectangles
//     int leftA, leftB;
//     int rightA, rightB;
//     int topA, topB;
//     int bottomA, bottomB;
 
//     //Calcul les cotes du rectangle A
//     leftA = A.x;
//     rightA = A.x + A.w;
//     topA = A.y;
//     bottomA = A.y + A.h;
 
//     //Calcul les cotes du rectangle B
//     leftB = B.x;
//     rightB = B.x + B.w;
//     topB = B.y;
//     bottomB = B.y + B.h;
//         //Tests de collision
//     if( bottomA <= topB )
//     {
//         return false;
//     }
 
//     if( topA >= bottomB )
//     {
//         return false;
//     }
 
//     if( rightA <= leftB )
//     {
//         return false;
//     }
 
//     if( leftA >= rightB )
//     {
//         return false;
//     }
 
//     //Si conditions collision detectee
//     return true;
// }


