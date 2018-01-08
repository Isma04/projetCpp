#include "mur.hh"
#include <time.h>


void Mur::RandomPos(){
	int max=350;
	int min=15;
	for(int i=0;i<13;i++)
	{
		srand(time(NULL));
		int x = (rand() % (max - min + 1)) + min;
    	int y =  (rand() % (max - min + 1)) + min;
		vector <int> newColumn;
		matr.push_back(newColumn);
		matr.at(x).push_back(y); 
	//matr.at(x).at(y) = 2;
	}	
}


