#pragma once 
#include "fond.hh"
class Elem{
protected:
	int _posX;
	int _posY;
public:
	Elem(int x, int y):_posX(x),_posY(y){}; 
	//int recupLg(Fond f){return f._longueurEcran;};
};