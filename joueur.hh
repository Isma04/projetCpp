#pragma once
#include "personnage.hh"
#include "mur.hh"
#include "policier.hh"
//#include "fond.hh"

//class Fond;
class Joueur: public Personnage{
protected:
	int _score;
	int _impulsion;  //pour quil fasse un saut et retombe
	int _vitesse;
	float _poids;
public:
	//constructeur
	Joueur(int x, int y, const std::string &file, std::string name, int v, int impulse, float p):Personnage(x,y,file, name), _score(0), _impulsion(impulse), _vitesse(v), _poids(p){};      	
	//getteurs
	int getImp(){return _impulsion;}
	int getV(){return _vitesse;}
	int getScore(){return _score;}
	//setteurs
	void setV(int x){_vitesse = x;}

	//fonctions
	void operator[](int s); //setteur score
	void Deplacement(int valeur_deplacementX, int valeur_deplacementY, int longueur, int hauteur, int &sautencours, Mur M, Policier C); //pour savoir si on est en train de sauter, 1 si oui 0 sinon cad si on est au sol
	void saut();
	int toucheMur(Mur M);
};
