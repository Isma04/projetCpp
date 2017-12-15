#include "joueur.hh"


void Joueur::Deplacement(int valeur_deplacementX, int valeur_deplacementY, fond f){
   	int longueur = f.getLg();
   	int hauteur = f.getH();

    if (_posX + valeur_deplacementX <= longueur) //avancee
    	_posX += valeur_deplacementX;
    else if (_posY + valeur_deplacementY <= hauteur) //saut
    	_posY += valeur_deplacementY;
    else if (_posX - valeur_deplacementX >= 0) _posX += valeur_deplacementX;
    else if (_posY - valeur_deplacementY >= 0) _posY += valeur_deplacementY;
    else {
    	_posY = _posY;
    	_posX = _posX;
    }


}