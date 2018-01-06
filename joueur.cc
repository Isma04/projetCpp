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
/* VOILA LA BONNE FONCTION 
void Joueur::Deplacement(int valeur_deplacementX, int valeur_deplacementY, int longueur, int hauteur){
    cout<<"salut deplacement1"<<endl;
    if (valeur_deplacementX != 0 && _posX + valeur_deplacementX <= longueur && _posX + valeur_deplacementX >= 0){ //avancee
    	cout<<"deplacement droite"<<endl;
        _posX += valeur_deplacementX;

    	cout<<_posX<<endl;
    }
    if (_posY == 390 && _vitesse < 0) { }
    else {

        _posY -= _vitesse;
        _vitesse -= _poids;
    }

    */

void Joueur::Deplacement(int valeur_deplacementX, int valeur_deplacementY, int longueur, int hauteur, int &sautencours){
    cout<<"salut deplacement1"<<endl;
    if (valeur_deplacementX != 0 && _posX + valeur_deplacementX < longueur && _posX + valeur_deplacementX >= 0){ //avancee
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

       
    
    //if (_posY == 390 && _vitesse < 0) { }
    //else {

    //    _posY -= _vitesse;
    //    _vitesse -= _poids;
    //}


    // else if (valeur_deplacementY != 0 && _posY + valeur_deplacementY <= hauteur && _posY + valeur_deplacementY >= 0){ //saut
    //     cout<<"deplacement haut"<<endl;

    //     _posY -= valeur_deplacementY;

    //     cout << _posY << endl;
    // }
    //else if (_posX + valeur_deplacementX >= 0) {
    //    _posX += valeur_deplacementX;
    //}
    //else if (_posY + valeur_deplacementY >= 0) {
    //    _posY += valeur_deplacementY;
        
    //}
    // else {
    	
    // }


}

void Joueur::saut(){
    cout<<"HELLO LE SAUT " << _vitesse <<endl;
   //_vitesse = _impulsion;
    setV(getImp());
   
   cout << "nv vitesse " << _vitesse << endl;
// //	_posY -= _vitesse;
// 	if (_posY < 390 && _vitesse != 0)
// 	{
// 		//_posY -= _vitesse;
// 		_vitesse -= _poids;
// 	_posY -= _vitesse;
// 	cout<<"Boris"<<endl;
//     }
	// else {}
	
    //_vitesse = _impulsion;
    //if (_posY == 390 && _vitesse < 0) { }
    //else {

    //    _posY -= _vitesse;
    //    _vitesse -= _poids;
    //}
}



void Joueur::chute(const int &SOL){
        cout<<"HELLO LA CHUTE "<<endl;
        
        _impulsion=_poids;
        //_vitesse=0;
        _posY=SOL;
}
