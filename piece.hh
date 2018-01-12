#pragma once 
#include <iostream>
#include <string>
#include "objet.hh"

class Piece: public Objet{
protected:
	int _valeur;
public:
	Piece(int x, int y, const std::string &file, int valeur): Objet(x,y, file),_valeur(valeur){};
	void RandomPos();
};