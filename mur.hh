#pragma once 
#include <iostream>
#include <string>
#include <list>
#include "objet.hh"
#include <SDL/SDL.h>
using namespace std;

class Mur: public Objet{
protected:
	//vector <vector<int>> matr;

	int _lg; //on stocke les dimensions du mur pour pouvoir savoir ou il y en a à partir du point x,y en haut a gauche
	int _largeur;
	int _NbMurMax;
public:
	list<SDL_Rect*> _Mur;
	Mur(int x, int y, const std::string &file, int nb):Objet(x,y, file), _NbMurMax(nb){};
	int getNb(){return _NbMurMax;}
	void RandomPos();
	
};
