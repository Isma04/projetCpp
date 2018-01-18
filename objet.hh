#pragma once 
#include <iostream>
#include <string>
#include "Elem.hh"

class Objet: public Elem{

public:
	Objet(int x, int y, const std::string &file):Elem(x,y, file){};
	virtual void Charge(int) = 0;
	
};

