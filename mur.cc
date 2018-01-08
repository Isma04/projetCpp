#include "mur.hh"
#include <time.h>


void Mur::RandomPos(){
	// int max=350;
	// int min=15;
	for(int i=0;i<_NbMurMax;i++)
	{
		// srand(time(NULL));
		// int x = (rand() % (max - min + 1)) + min;
  //   	int y =  (rand() % (max - min + 1)) + min;
		int x=i;
		int y = i+1;
		_Mur.push_back(make_pair(x,y));
		//matr.at(x).push_back(y); 
	//matr.at(x).at(y) = 2;
	}	
}


