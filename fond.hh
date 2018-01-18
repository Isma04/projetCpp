#pragma once 
#include <SDL/SDL.h>
#include <string>
#include "joueur.hh"


class Fond{

public:
	int _longueurEcran;
	int _hauteurEcran;
	Fond(int lg, int h):_longueurEcran(lg), _hauteurEcran(h){};
	//int getLg(){return _longueurEcran;};
	//int getH(){return _hauteurEcran;};
	//void setLg(int lg){_longueurEcran = lg;};
	//void setH(int h){_hauteurEcran = h;};
	void init();//int &h, int &lg, int &sol);
	void anime(int x, int y, const int SOL);
	void input_handle(int &a, int &b,int &v, Joueur j, int &sautencours, Mur M);

	//bool check_collision( SDL_Rect &A, SDL_Rect &B ); //renvoie true si A et B sont en collision, false sinon

};
