#include "joueur.hh"
#include <string>
#include <iostream>
using namespace std;

void Joueur::Deplacement(int valeur_deplacementX, int valeur_deplacementY, int longueur, int hauteur, int &sautencours){
    cout<<"salut deplacement1"<<endl;
    if (valeur_deplacementX != 0 && _posX + valeur_deplacementX <= longueur && _posX + valeur_deplacementX >= 0){ //avancee
        cout<<"deplacement droite"<<endl;
        _posX += valeur_deplacementX;

        cout<<_posX<<endl;
        cout << _vitesse << " ,vitesse" << endl;
        cout << "y " << _posY << endl;
    }

    if (_posY - _vitesse <= 190 && _posY - _vitesse >= 0 && (_vitesse != 0 || (_vitesse == 0 && sautencours == 1))) {  //pas au sol et vitesse non nul
        cout << "saluuuut  " << _posY << endl;
        _posY -= _vitesse;
        _vitesse -= _poids;
        if (_vitesse == 0) sautencours = 1;
        cout << "vitesse modif" << _vitesse << endl;
    } 
    else {} //si on est au sol et que la vitesse de deplacement est nul on ne se deplace pas selon y 

      
}

void Joueur::saut(){
    setV(getImp());
}

