#pragma once 
#include <iostream>
#include <string>
#include "Elem.hh"

class Objet: public Elem{

public:
	Objet(int x, int y):Elem(x,y){};
	virtual void RandomPos() = 0;
	
};
