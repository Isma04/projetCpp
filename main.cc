#include <stdio.h>
#include <SDL/SDL.h>
#include "joueur.hh"
#include <string>
#include "fond.hh"
#include <iostream>

using namespace std; 
int main(void)
{
	Fond f(690,390);
	f.init();
	f.anime(0,290, 290);


	return 0;
}



// Y'vaais cette option dans le makefile mais ca faisait beuguer mon truc du coup je l'ai enlevé 
//LIBFLAGS= -ltinyxml2 

