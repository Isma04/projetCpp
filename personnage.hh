#pragma once 
#include "Elem.hh"
#include <string>

class Personnage: public Elem{
protected:
	std::string _name;
	FILE* perso; //aspect perso ???
public:
	Personnage(int x, int y, std::string name): Elem(x,y),_name(name){};
	virtual void Deplacement(int x, int y);
};