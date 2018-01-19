#include "policier.hh"
#include <time.h>


void Policier::Charge(int L){
	int max=350;
	int min=15;
	SDL_Rect* posCop;
	srand(time(NULL));
	
	int x = (rand() % (100 - 0 + 1)) + 0;
  	int y =  (rand() % (190 - 0 + 1)) + 0;
   int ecartX = 100;
	for(int i=0;i<_NbCopMax-1;i++)
	{
		posCop = new SDL_Rect; //pour ne pas ecraser les donnees pointees pas le pointeur
		posCop->x = x;
		posCop->y = y;
		_Cop.push_back(posCop);
		x = x + ecartX;
		y =  (rand() % (max - min + 1)) + min;	
	}	
}

