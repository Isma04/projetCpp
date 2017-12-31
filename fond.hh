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
	void init(int &h, int &lg, int &sol);
	void anime(int x, int y, const int SOL);
	void input_handle(int &a, int &b, Joueur j, const int SOL);
	void tailleBMP(const std::string &file, int &h, int &lg); //pour recup h hauteur et lg longueur du perso

};