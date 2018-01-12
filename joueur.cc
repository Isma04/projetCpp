#include "joueur.hh"
#include <string>
#include <iostream>
using namespace std;

void Joueur::Deplacement(int valeur_deplacementX, int valeur_deplacementY, int longueur, int hauteur, int &sautencours){
 
    if (valeur_deplacementX != 0 && _posX + valeur_deplacementX <= longueur && _posX + valeur_deplacementX >= 0){ //avancee
        _posX += valeur_deplacementX;
    }

    if (_posY - _vitesse <= 290 && (_vitesse != 0 || (_vitesse == 0 && sautencours == 1))) {  //pas au sol et vitesse non nul
    
        if (_posY - _vitesse >= 0) _posY -= _vitesse; //la position selon Y est modifiée si le perso reste dans l écran (donc y>0)
        else _vitesse *= -1; //s'il touche le plafond, la vitesse devient negative et il redescend directement 
        _vitesse -= _poids;
        if (_vitesse == 0) sautencours = 1;
        
    } 

    else {} //si on est au sol et que la vitesse de deplacement est nul on ne se deplace pas selon y 

      
}

void Joueur::saut(){
    setV(getImp());
}

