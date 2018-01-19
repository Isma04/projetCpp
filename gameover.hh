#pragma once 
#include <iostream>
#include <string>
#include "Elem.hh"
#include <SDL/SDL.h>

using namespace std;


class GameOver : public Elem{
protected:
	int _lg; //on stocke les dimensions du GameOver pour pouvoir savoir ou il y en a à partir du point x,y en haut a gauche
	int _largeur;
public:
	GameOver(int x, int y, const std::string &file):Elem(x,y, file){};
};
