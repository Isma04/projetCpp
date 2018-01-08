#include "mur.hh"
#include <time.h>


void Mur::RandomPos(){
	int max=350;
	int min=15;
	SDL_Rect* posMur;
	srand(time(NULL));
	for(int i=0;i<_NbMurMax;i++)
	{
		
		int x = (rand() % (max - min + 1)) + min;
     	int y =  (rand() % (max - min + 1)) + min;
		
		posMur->x = x;
		posMur->y = y;
		cout << x << endl;
		cout << y << endl;
		_Mur.push_front(posMur);

		//matr.at(x).push_back(y); 
	//matr.at(x).at(y) = 2;
	}	
}


