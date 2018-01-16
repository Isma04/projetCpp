#include "joueur.hh"
#include <string>
#include <iostream>
using namespace std;

void Joueur::Deplacement(int valeur_deplacementX, int valeur_deplacementY, int longueur, int hauteur, int &sautencours, Mur M){
    int val = toucheMur(M);
    cout << "val " << val << endl;
    cout << "vitesse " << _vitesse << endl;
    cout << "saut en cours " << sautencours << endl;
 	//deplacement en X
    if (valeur_deplacementX != 0 && _posX + valeur_deplacementX <= longueur && _posX + valeur_deplacementX >= 0){ 
        if ((val != 2 && valeur_deplacementX >0) || (val != 3 && valeur_deplacementX < 0) || val == 0 ) _posX += valeur_deplacementX;

    }
    //deplacement en Y
    if (_posY - _vitesse <= 390-_h && (_vitesse != 0 || (_vitesse == 0 && sautencours != 0))) {  //pas au sol et vitesse non nul
    	
    	if(val == 1 && (sautencours != 3 || _vitesse <= 0)) {
    		sautencours = 2;
    	}
    	else if (val==4 && sautencours == 1) {
    		cout << "4   " << _vitesse << endl;
    		_vitesse*=-1;
    		_vitesse -= _poids;
    		_posY -= _vitesse;}

    	else {
       		if (_posY - _vitesse >= 0) _posY -= _vitesse; //la position selon Y est modifiée si le perso reste dans l écran (donc y>0)
       		else _vitesse *= -1; //s'il touche le plafond, la vitesse devient negative et il redescend directement 
       		_vitesse -= _poids;        
        }
    } 
    else {sautencours=0;} //si on est au sol et que la vitesse de deplacement est nul on ne se deplace pas selon y 
}       

/*Initialise la vitesse du joueur à l'impulsion */

void Joueur::saut(){
    setV(getImp());
}

/* Fonction pour savoir si le joueur touche un mur
Entrée : classe mur qui contient les longueurs et largeur d'un mur, et la liste de pointeur sur SDL_Rect qui contient la positioin de chaque mur
Sortie :- retourne 0 si le joueur ne touche pas de mur 
        - retourne 1 si le joueur est sur le mur 
        - retourne 2 si le joueur touche le mur par le côté gauche 
        - retourne 3 si le joueur touche le mur par la droite
        - retourne 4 si le joueur touche le mur par en bas
Test pour chaque mur de la liste
*/
 
int Joueur::toucheMur(Mur M){ 
	int xMur;
	int yMur;
    
	for (list<SDL_Rect*>::iterator it = M._Mur.begin(); it != M._Mur.end(); it++){
		xMur = (**it).x;
        yMur = (**it).y;

        if ((_posY+_h - yMur < 10 && _posY+_h - yMur > -10 ) && _posX > xMur-_lg && _posX < xMur + M.getLg() - 30 ) return 1; //sur le mur 
        else if (-_posX - _lg + xMur < 5 && -_posX - _lg+ xMur > -5 && _posY > yMur - _h +10 && _posY < yMur -10 + M.getH()) return 2;     
     	else if((_posX - xMur - M.getLg() < 5 && _posX - xMur - M.getLg() > -5) && _posY > yMur - _h +10 && _posY < yMur -10 + M.getH()) return 3;
     	else if (_posY - yMur - M.getH() < 10 && _posY - yMur - M.getH() > -10 && _posX > xMur-_lg && _posX < xMur + M.getLg()) return 4;
	} 

	return 0;
}

