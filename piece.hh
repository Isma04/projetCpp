#pragma once 
#include <iostream>
#include <string>
#include <list>
#include "objet.hh"
#include <SDL/SDL.h>

using namespace std;

class Piece: public Objet{
protected:
	int _valeur;
public:
	list<SDL_Rect*> _Pieces;
	Piece(int x, int y, const std::string &file, int valeur): Objet(x,y, file),_valeur(valeur){};
	void Charge(int);
};
