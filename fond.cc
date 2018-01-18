#include "fond.hh"
#include "mur.hh"
//#include <string>
#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <string>
#include <iterator>
#include "niveau.hh"
#include "piece.hh"
using namespace std;
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

/*

void inventaire(SDL_Surface *ecran) //fonction qui gère l'inventaire
{
SDL_Surface *inv = NULL; // varaible de la surface inventaire
SDL_Rect positioni; // variable position de l'inventaire

inv = SDL_LoadBMP("inventaire.bmp"); //chargement de l'inventaire
positioni.x=1ima0;
positioni.y=10;
SDL_BlitSurface(inv, NULL, ecran, &positioni); // Collage de la surface inventaire sur l'écran

SDL_Flip(ecran); // mettre à jour l'affichage

} 
*/

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
	// On cree un vector qui stocke tous les fonds 
    vector<string> tableau;
    tableau.push_back("image/euro.bmp");
    tableau.push_back("image/palaos.bmp");	
    Niveau N(1);  // Je crée mon niveau
    // J'initialise ma map qui contient pour chaque niveau le score 	    demandé 
    map<int,int> MesNiveaux=N.Init();
    // J'initialise un iterator qui va parcourir ma map 
    map<int, int>::iterator it2=MesNiveaux.begin();
    // Je crée 2 variables Id_niveau et Score 
    int Id_niveau=it2->first;
    int Score_max=it2->second;



	SDL_Rect positionFond, positionZozor, positionPiece, positionMur;
	int v = 0;

	Joueur j(x,y,"image/goku1.bmp","zoro", v, 15, 1); // augmentation de la valeur l'impulsion pour que ca fasse un gros saut 
	Piece p(0,0,"image/pieceMini.bmp",10);	
	Mur M(50,50,"image/wall.bmp",12);

	int a = x;
	int b = y;
	int saut = 0; //on est au sol
	positionFond.x = 0;
	positionFond.y = 0;

		M.Charge(1);

	positionZozor.x = x;
	positionZozor.y = y;

     p.Charge(1);


    SDL_Rect* Piece_courante;
    Piece_courante = p._Pieces.front();
    p._Pieces.pop_front();
    positionPiece.x =  Piece_courante->x;
    positionPiece.y = Piece_courante->y; 

	SDL_EnableKeyRepeat(10,5);

	while (1) {

		SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // Dessiner le fond
		SDL_BlitSurface(zozor, NULL, ecran, &positionZozor); // Dessiner zozor
		SDL_BlitSurface(petitepiece, NULL, ecran, &positionPiece);
		SDL_BlitSurface(wall, NULL, ecran, &positionMur);

		for (list<SDL_Rect*>::iterator it = M._Mur.begin(); it != M._Mur.end(); it++){
			SDL_BlitSurface(wall, NULL, ecran, *it);
		}
		
		int S=j.getScore();
		PrintSDL(ecriture,ecran,100,20,"Niveau: %d \n Score : %d / %d ", Id_niveau, S, Score_max);

		SDL_Flip(ecran); // On affiche réellement l'image.
		input_handle(a, b, v, j, saut, M); // On appelle le gestionnaire d'évènements.

		SDL_Delay(10); //attend 10ms pour rafraichir la page 
	

		j.setX(a);
		j.setY(b);
		j.setV(v);
		positionZozor.x = a;
		positionZozor.y = b;

// Si le perso attrape une piece
		
		if (j.check_collision(positionZozor, positionPiece) == true)
		{
	j.setScore(S+10);
            Piece_courante = p._Pieces.front();
            p._Pieces.pop_front();
            positionPiece.x =  Piece_courante->x;
            positionPiece.y = Piece_courante->y; 
		}

// Passage à un nouveau niveau

 if (j.getScore() >= Score_max)
        {
		//inventaire(ecran)
        it2++; // ON avance dans la map pour le score et l'identifiant du niveau 
        //it1++; // on avance dans le tableau des fonds 
        Id_niveau=it2->first;
        cout << " identifiant niveau " << endl;
        cout << Id_niveau << endl;
        Score_max=it2->second;
        j.setScore(0);
        imageDeFond=SDL_LoadBMP(tableau[Id_niveau-2].c_str()); // car le niveau 
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // Dessiner le fond
        M.Charge(Id_niveau);
        p.Charge(Id_niveau);
		SDL_BlitSurface(wall, NULL, ecran, &positionMur);






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





