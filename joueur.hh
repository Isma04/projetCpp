#pragma once
#include "personnage.hh"
//#include "fond.hh"

class Fond;
class Joueur: public Personnage{
protected:
	int score;
public:
	Joueur(int x, int y, std::string name):Personnage(x,y,name){};
	void Deplacement(int valeur_deplacementX, int valeur_deplacementY, int longueur, int hauteur);
};
