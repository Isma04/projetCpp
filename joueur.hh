#pragma once
#include "personnage.hh"
//#include "fond.hh"

//class Fond;
class Joueur: public Personnage{
protected:
	int score;
	int _impulsion;  //pour quil fasse un saut et retombe
	int _vitesse;
	float _poids;
public:
	Joueur(int x, int y, std::string name, int v, int impulse, float p):Personnage(x,y,name), _impulsion(impulse), _vitesse(v), _poids(p){};
	void Deplacement(int valeur_deplacementX, int valeur_deplacementY, int longueur, int hauteur);
	void saut();
	void chute(const int &SOL);
	int getImp(){return _impulsion;}
	void setImp(int x){_impulsion = x;}
	void setV(int x){_vitesse = x;}
	void setP(int x){_poids = x;}
	int getV(){return _vitesse;}

};
