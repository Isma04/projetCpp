#pragma once 
#include <iostream>
#include <string>
#include <array>
#include <SDL/SDL.h>
#include <fstream>
using namespace std;

class Elem{
protected:
	int _posX;
	int _posY;
	int _h; //hauteur de l'element
	int _lg; //longueur de l'element
public:
	Elem(int x, int y, const std::string &file):_posX(x), _posY(y){
		static constexpr size_t HEADER_SIZE = 54;

    	std::ifstream bmp(file, std::ios::binary);

    	std::array<char, HEADER_SIZE> header;
    	bmp.read(header.data(), header.size());

    	_lg = *reinterpret_cast<uint32_t *>(&header[18]);
    	_h = *reinterpret_cast<uint32_t *>(&header[22]);
	}; 
	int getX(){return _posX;}
	int getY(){return _posY;}
	int getH(){return _h;}
	int getLg(){return _lg;}
	void operator()(int x, int y); //setteur
	bool check_collision( SDL_Rect &A, SDL_Rect &B ); //pour savoir si deux elem se touchent 
};