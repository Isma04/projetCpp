#pragma once 
#include <iostream>
#include <string>
#include <vector>
#include "objet.hh"
using namespace std;

class Mur: public Objet{
protected:
	vector <vector<int>> matr;
	int _lg; //on stocke les dimensions du mur pour pouvoir savoir ou il y en a à partir du point x,y en haut a gauche
	int _largeur;
public:
	Mur(int x, int y):Objet(x,y){};
	void RandomPos();
	
};
