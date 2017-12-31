#include <stdio.h>
#include <SDL/SDL.h>
#include "joueur.hh"
#include <string>
#include "fond.hh"
#include <iostream>

using namespace std; 
int main(void)
{
	int HAUTEUR_PERSO;
	int LG_PERSO;
	int SOL;

	Fond f(690,390);
	f.init(LG_PERSO, HAUTEUR_PERSO, SOL);
	f.anime(0,SOL, SOL);

	return 0;
}



// Y'vaais cette option dans le makefile mais ca faisait beuguer mon truc du coup je l'ai enlevé 
//LIBFLAGS= -ltinyxml2 

