#pragma once 
#include <iostream>
#include <string>




class Elem{
protected:
	int _posX;
	int _posY;
public:
	Elem(int x, int y):_posX(x),_posY(y){}; 
	int getX(){return _posX;}
	int getY(){return _posY;}
	void setX(int x){_posX = x; 
						std::cout << " hello hello "<< std::endl;};
	void setY(int y){_posY=y;};
	//int recupLg(Fond f){return f._longueurEcran;};
};