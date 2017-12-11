#include "personnage.hh"

class Joueur: public Personnage{
protected:
	int score;
public:
	Joueur(int x, int y, std::string name):Personnage(x,y,name){};
	void Deplacement(int valeur_deplacementX, int valeur_deplacementY, Fond f);
};