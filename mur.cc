#include "mur.hh"
#include <time.h>
#include <fstream>



void Mur::Charge(int niveau)// je met en param l'id de mon niveau
{

string nom = "mur_niveau_" + to_string(niveau);
ifstream fichier(nom, ios::in);  // on ouvre le fichier en lecture
if(fichier)  // si l'ouverture a réussi

   {       
   	SDL_Rect* posMur;

    int nb_mur, posX, posY;
    fichier >> nb_mur;
    for(int i=0;i< nb_mur; i++)
    {
    	posMur= new SDL_Rect;
    	fichier >> posX >> posY;
    	posMur->x = posX;
    	posMur->y=posY;
    	_Mur.push_back(posMur);
    }


    fichier.close();  // on ferme le fichier
    

    }

       
}



