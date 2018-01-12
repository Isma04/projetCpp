#pragma once
#include "personnage.hh"
#include "mur.hh"
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
	void setImp(int x){_impulsion = x;}
	void setV(int x){_vitesse = x;}
	void setP(int x){_poids = x;}
	void setScore(int x){_score = x;}
	//fonctions
	void Deplacement(int valeur_deplacementX, int valeur_deplacementY, int longueur, int hauteur, int &sautencours); //pour savoir si on est en train de sauter, 1 si oui 0 sinon cad si on est au sol
	void saut();
	bool touche(Mur M);
	// bool touche(Elem elt);
	

};
