#pragma once 
#include <iostream>
#include <string>
#include "objet.hh"

class Piece: public Objet{
protected:
	int _valeur;
public:
	Piece(int x, int y, int valeur): Objet(x,y),_valeur(valeur){};
	void RandomPos();
};