#include "mur.hh"
#include <time.h>


void Mur::RandomPos(){
	int max=350;
	int min=15;
	SDL_Rect* posMur;
	srand(time(NULL));
	
	int x = (rand() % (100 - 0 + 1)) + 0;
  	int y =  (rand() % (190 - 0 + 1)) + 0;
    int ecartX = 100;
	for(int i=0;i<_NbMurMax-1;i++)
	{
		
		// int x = (rand() % (max - min + 1)) + min;
  //    	int y =  (rand() % (max - min + 1)) + min;
		
		posMur = new SDL_Rect; //pour ne pas ecraser les donnees pointees pas le pointeur
		posMur->x = x;
		posMur->y = y;
		cout << x << endl;
		cout << y << endl;
		_Mur.push_back(posMur);
		x = x + ecartX;
		y =  (rand() % (max - min + 1)) + min;

	 
	
	}	
}


