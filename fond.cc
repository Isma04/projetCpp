#include "fond.hh"
#include "mur.hh"
#include "niveau.hh"
#include "piece.hh"
#include "time.hh"
#include "gameover.hh"
#include <iostream>
#include <fstream>
// #include <vector>
#include <string>
#include <iterator>

using namespace std;
SDL_Surface *ecran, *imageDeFond, *zozor, *petitepiece, *ecriture, *wall, *message, *cop, *gameover, *imageDeDebut;
SDL_Color textColor = { 255, 255, 255 };


//Pour afficher le score
void Fond::PrintSDL(SDL_Surface* font,SDL_Surface* dest,int x,int y,const char* text,...){ 
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
        InitRect(Rsrc, Rsrc.w*((unsigned char)(buf[i])%16), Rsrc.h*((unsigned char)(buf[i])/16-2));
        InitRect(Rdst, x, y);
        SDL_BlitSurface(font,&Rsrc,dest,&Rdst);
        x+=Rsrc.w;
    }
}

void Fond::init(){
	
	SDL_Init(SDL_INIT_VIDEO);
	ecran = SDL_SetVideoMode(_longueurEcran, _hauteurEcran, 32, SDL_HWSURFACE);
	imageDeFond = SDL_LoadBMP("image/bahamas.bmp");
	ecriture=SDL_LoadBMP("image/font.bmp"); //score
    SDL_SetColorKey(ecriture, SDL_SRCCOLORKEY, SDL_MapRGB(ecriture->format, 0, 0, 0)); 
	zozor = SDL_LoadBMP("image/goku1.bmp");
	petitepiece = SDL_LoadBMP("image/pieceMini.bmp");
	wall = SDL_LoadBMP("image/wall.bmp");
    cop = SDL_LoadBMP("image/cop1.bmp");
    gameover = SDL_LoadBMP("image/press1.bmp");
    imageDeDebut = SDL_LoadBMP("image/ppg.bmp");
	SDL_SetColorKey(zozor, SDL_SRCCOLORKEY, SDL_MapRGB(zozor->format, 0, 0, 0));
	SDL_SetColorKey(petitepiece, SDL_SRCCOLORKEY, SDL_MapRGB(petitepiece->format, 255, 255, 255));
	SDL_SetColorKey(wall, SDL_SRCCOLORKEY, SDL_MapRGB(wall->format, 255, 255, 255));
    SDL_SetColorKey(cop, SDL_SRCCOLORKEY, SDL_MapRGB(cop->format, 255, 255, 255));
}



void Fond::anime(int x, int y, const int SOL, vector<string> &tableau) //position x,y du perso
{
    Timer myTimer;
    myTimer.start();
    Niveau N(1);  // Je crée mon niveau
    // J'initialise ma map qui contient pour chaque niveau le score demandé 
    map<int,int> MesNiveaux=N.Init();
    // J'initialise un iterator qui va parcourir ma map 
    map<int, int>::iterator it2=MesNiveaux.begin();
    // Je crée 2 variables Id_niveau et Score 
    int Id_niveau=it2->first;
    int Score_max=it2->second;

	SDL_Rect positionFond, positionZozor, positionPiece, positionMur, positionCop, posgameover, positionDebut;
	int v = 0;

	Joueur j(x,y,"image/goku1.bmp","zoro", v, 15, 1); 
	Piece p(0,0,"image/pieceMini.bmp",10);	
	Mur M(50,50,"image/wall.bmp",12);
    Policier C(634,50,"image/cop1.bmp",1);
    GameOver G(0,0,"image/press1.bmp");

	int a = x;
	int b = y;
	int saut = 0; //au sol
    InitRect(positionFond, 0, 0);

	M.Charge(1);
    InitRect(positionZozor, x, y);

    p.Charge(1);


    SDL_Rect* Piece_courante;
    ReInitPiece(Piece_courante, p, positionPiece);
    InitRect(positionCop, C.getX(),299);

	SDL_EnableKeyRepeat(10,5);

    int droite = 1;
    InitRect(positionDebut, 60, 30);
    SDL_BlitSurface(imageDeDebut, NULL, ecran, &positionDebut);
    SDL_Flip(ecran);
    SDL_Delay(10000);

	while (1) {        

        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // Dessiner le fond
		SDL_BlitSurface(zozor, NULL, ecran, &positionZozor); // Dessiner zozor
		SDL_BlitSurface(petitepiece, NULL, ecran, &positionPiece);
        SDL_BlitSurface(cop, NULL, ecran, &positionCop);

        MouvementPolicier(droite, positionCop);

		for (list<SDL_Rect*>::iterator it = M._Mur.begin(); it != M._Mur.end(); it++){
			SDL_BlitSurface(wall, NULL, ecran, *it);
		}
		
		int S=j.getScore();
        PrintSDL(ecriture,ecran,10,20,"Niveau:%d\n Score:%d/%d, Timer: %d sec", Id_niveau, S, Score_max, (myTimer.get_ticks()/(1000)));

		SDL_Flip(ecran); // On affiche réellement l'image.
		input_handle(a, b, v, j, saut, M, C); // On appelle le gestionnaire d'évènements.

		SDL_Delay(10); //attend 10ms pour rafraichir la page 
	
        j(a,b);
		j.setV(v);
        InitRect(positionZozor, a, b);

// Si le perso attrape une piece
		
		if (j.check_collision(positionZozor, positionPiece) == true){
            j[S+10];
            ReInitPiece(Piece_courante, p, positionPiece);
		}

// Passage à un nouveau niveau
        if (j.check_collision(positionZozor, positionCop) == true){
            j[-S];
            InitRect(posgameover, 5, 6);   
            break;
        }     


        if (j.getScore() >= Score_max && myTimer.get_ticks() < 60*1000)
        {
        imageDeFond=SDL_LoadBMP("palos.bmp"); // car le niveau 
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // Dessiner le fond
        myTimer.stop();
        myTimer.start();
        M._Mur.clear();
        p._Pieces.pop_front();
        it2++; // ON avance dans la map pour le score et l'identifiant du niveau 
        Id_niveau=it2->first;
        Score_max=it2->second;
        j[0]; //score a 0
        imageDeFond=SDL_LoadBMP(tableau[Id_niveau-1].c_str()); 
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // Dessiner le fond
        M.Charge(Id_niveau);
        p.Charge(Id_niveau);
		SDL_BlitSurface(wall, NULL, ecran, &positionMur);}

        if (j.getScore() < Score_max && myTimer.get_ticks() > 60*1000) break;
    }
    SDL_BlitSurface(gameover, NULL, ecran, &posgameover);
    SDL_Flip(ecran);
    FreeS(cop, wall, petitepiece, zozor, ecriture, imageDeFond);
}


void Fond::input_handle(int &a, int &b, int &v, Joueur j, int &sautencours, Mur M, Policier C){
	SDL_Event event;	

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
                	j.Deplacement(3,0,_longueurEcran,_hauteurEcran, sautencours, M, C);
                	a = j.getX();
                	b = j.getY();
                	v = j.getV();           	
                   	break;
                case SDLK_LEFT:
                	j.Deplacement(-3,0,_longueurEcran,_hauteurEcran, sautencours, M, C);
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
                	j.Deplacement(0,0,_longueurEcran,_hauteurEcran, sautencours, M, C);
                	a = j.getX();
                	b = j.getY();
                	v = j.getV();
                	break;
            }
            break;
            default:
                    j.Deplacement(0,0,_longueurEcran,_hauteurEcran, sautencours, M, C);
                	a = j.getX();
                	b = j.getY();
                	v = j.getV();
        	break;    
		}  
}

void Fond::FreeS(SDL_Surface* &cop, SDL_Surface* &wall, SDL_Surface* &petitepiece, SDL_Surface* &zozor, SDL_Surface* &ecriture, SDL_Surface* &imageDeFond){
    SDL_FreeSurface(cop);
    SDL_FreeSurface(wall);
    SDL_FreeSurface(petitepiece);
    SDL_FreeSurface(zozor);
    SDL_FreeSurface(ecriture);
    SDL_FreeSurface(imageDeFond);
}


void Fond::ReInitPiece(SDL_Rect* &Piece_courante, Piece &p, SDL_Rect &positionPiece){

    Piece_courante = p._Pieces.front();
    p._Pieces.pop_front();
    positionPiece.x =  Piece_courante->x;
    positionPiece.y = Piece_courante->y; 
}

void Fond::MouvementPolicier(int &droite, SDL_Rect &positionCop){
    if(droite){
        positionCop.x--; //vers la droite
        droite = (positionCop.x == 0) ? 0 : 1;
    }

    if(!droite){
        positionCop.x++; //vers la gauche
        droite = (positionCop.x == 634) ? 1 : 0;
    }
}

void Fond::InitRect(SDL_Rect &r, int x, int y){
    r.x = x;
    r.y = y;
}