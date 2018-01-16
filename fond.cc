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


void Fond::init(){//int &HAUTEUR_PERSO, int &LG_PERSO, int &SOL){
	
	SDL_Init(SDL_INIT_VIDEO);
	ecran = SDL_SetVideoMode(_longueurEcran, _hauteurEcran, 32, SDL_HWSURFACE);
	imageDeFond = SDL_LoadBMP("image/bahamas.bmp");
	ecriture=SDL_LoadBMP("image/font.bmp"); //score
	zozor = SDL_LoadBMP("image/goku1.bmp");
	petitepiece = SDL_LoadBMP("image/pieceMini.bmp");
	wall = SDL_LoadBMP("image/wall.bmp");
	SDL_SetColorKey(zozor, SDL_SRCCOLORKEY, SDL_MapRGB(zozor->format, 0, 0, 0));
	SDL_SetColorKey(petitepiece, SDL_SRCCOLORKEY, SDL_MapRGB(petitepiece->format, 255, 255, 255));
	SDL_SetColorKey(wall, SDL_SRCCOLORKEY, SDL_MapRGB(wall->format, 255, 255, 255));
	// tailleBMP("image/goku1.bmp", HAUTEUR_PERSO, LG_PERSO);
	// SOL = 390 - HAUTEUR_PERSO;
	// cout << "hauteir " <<HAUTEUR_PERSO << endl;
}



void Fond::anime(int x, int y, const int SOL ) //position x,y du perso
{
	//cout << "hauteir " <<HAUTEUR_PERSO << endl;
	SDL_Rect positionFond, positionZozor, positionPiece;
	int v = 0;

	Joueur j(x,y,"image/goku1.bmp","zoro", v, 15, 1); // augmentation de la valeur l'impulsion pour que ca fasse un gros saut 
	Piece p(0,0,"image/pieceMini.bmp",10);	
	Mur M(50,50,"image/wall.bmp",12);

	int a = x;
	int b = y;
	int saut = 0; //on est au sol
	positionFond.x = 0;
	positionFond.y = 0;

	M.RandomPos();

	positionZozor.x = x;
	positionZozor.y = y;

    p.RandomPos();

    positionPiece.x = p.getX();
    positionPiece.y = p.getY(); 

	SDL_EnableKeyRepeat(10,5);

	while (1) {

		SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // Dessiner le fond
		SDL_BlitSurface(zozor, NULL, ecran, &positionZozor); // Dessiner zozor
		SDL_BlitSurface(petitepiece, NULL, ecran, &positionPiece);

		for (list<SDL_Rect*>::iterator it = M._Mur.begin(); it != M._Mur.end(); it++){
			SDL_BlitSurface(wall, NULL, ecran, *it);
		}
		
		int S=j.getScore();
		PrintSDL(ecriture,ecran,500,20,"Score : %d ", S);

		SDL_Flip(ecran); // On affiche réellement l'image.
		input_handle(a, b, v, j, saut, M); // On appelle le gestionnaire d'évènements.

		SDL_Delay(10); //attend 10ms pour rafraichir la page 
	

		j.setX(a);
		j.setY(b);
		j.setV(v);
		positionZozor.x = a;
		positionZozor.y = b;
		
		if (j.check_collision(positionZozor, positionPiece) == true)
		{
			j.setScore(S+10);
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



void Fond::input_handle(int &a, int &b, int &v, Joueur j, int &sautencours, Mur M) 
{
	SDL_Event event;	
	
	//while (SDL_PollEvent(&event)) {
		SDL_PollEvent(&event);
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

                	j.Deplacement(3,0,_longueurEcran,_hauteurEcran, sautencours, M);
                	a = j.getX();
                	b = j.getY();
                	v = j.getV();
                	

                   	break;
                case SDLK_LEFT:
                	j.Deplacement(-3,0,_longueurEcran,_hauteurEcran, sautencours, M);
                	a = j.getX();
                	b = j.getY();
                	v = j.getV();
                	
                	break;
                case SDLK_UP:
                	if (sautencours!=1){
                	j.saut();
                	v = j.getV();
                    if (sautencours == 0) sautencours = 1;
                    else if (sautencours==2) sautencours = 3;} //on commence un saut
                	                	
                	break;
  
                default:
                	j.Deplacement(0,0,_longueurEcran,_hauteurEcran, sautencours, M);
                	a = j.getX();
                	b = j.getY();
                	v = j.getV();
                	break;
            }
            break;
        default:
        j.Deplacement(0,0,_longueurEcran,_hauteurEcran, sautencours, M);
                	a = j.getX();
                	b = j.getY();
                	v = j.getV();
        	break;    
		}  

	//}


}





