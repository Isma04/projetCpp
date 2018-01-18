#include <iostream>
#include <string>
#include "piece.hh"


void Piece::Charge(int niveau){
string nom = "piece_niveau_" + to_string(niveau);
ifstream fichier(nom, ios::in);  // on ouvre le fichier en lecture
if(fichier)  // si l'ouverture a réussi

   {       
   	SDL_Rect* posPiece;

    int nb_piece, posX, posY;
    fichier >> nb_piece;
    for(int i=0;i< nb_piece; i++)
    {
    	posPiece= new SDL_Rect;
    	fichier >> posX >> posY;
    	posPiece->x = posX;
    	posPiece->y=posY;
    	_Pieces.push_back(posPiece);
    }


    fichier.close();  // on ferme le fichier

    }



}
