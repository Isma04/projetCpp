#include "joueur.hh"
#include <string>
#include <iostream>
using namespace std;
/*
void Joueur::Deplacement(int valeur_deplacementX, int valeur_deplacementY, Fond f){

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

*/

void Joueur::Deplacement(int valeur_deplacementX, int valeur_deplacementY, int longueur, int hauteur){
	cout<<"salut deplacement1"<<endl;
    if (_posX + valeur_deplacementX <= longueur){ //avancee
    	cout<<"deplacement droite"<<endl;
    	_posX = _posX + valeur_deplacementX;
    	cout<<_posX<<endl;
    }
    else if (_posY + valeur_deplacementY <= hauteur) //saut
    	_posY += valeur_deplacementY;
    else if (_posX - valeur_deplacementX >= 0) _posX += valeur_deplacementX;
    else if (_posY - valeur_deplacementY >= 0) _posY += valeur_deplacementY;
    else {
    	_posY = _posY;
    	_posX = _posX;
    }


}