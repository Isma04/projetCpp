
#include <iostream>
#include <string>
#include "piece.hh"

void Piece::RandomPos(){
	int max = 350;
	int min = 15;

	srand(time(NULL));
	int r1 = (rand() % (max - min + 1)) + min;
    int r2 =  (rand() % (max - min + 1)) + min;
//verifier ici si check collision == false avant de modifier position piece
    setX(r1);
    setY(r2);
}