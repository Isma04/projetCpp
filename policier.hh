#pragma once 
#include <iostream>
#include <string>
#include <list>
#include "personnage.hh"
#include <SDL/SDL.h>

using namespace std;


class Policier: public Personnage{
protected:
	int _lg; //on stocke les dimensions du policier pour pouvoir savoir ou il y en a à partir du point x,y en haut a gauche
	int _largeur;
	int _NbCopMax;
public:
	list<SDL_Rect*> _Cop;
	Policier(int x, int y, const std::string &file, int nb):Personnage(x,y,file, "cop"),_NbCopMax(nb){};
	int getNb(){return _NbCopMax;}
	void Charge(int);
	
};
