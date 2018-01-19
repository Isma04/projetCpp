#include "Elem.hh"

void Elem::operator()(int x, int y){
	_posX = x;
	_posY = y;
}

bool Elem::check_collision( SDL_Rect &A, SDL_Rect &B){
    //Les cotes des rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;
 
    //Calcul les cotes du rectangle A
    leftA = A.x;
    rightA = A.x + A.w;
    topA = A.y;
    bottomA = A.y + A.h;
 
    //Calcul les cotes du rectangle B
    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;
        //Tests de collision
    if( bottomA <= topB )
    {
        return false;
    }
 
    if( topA >= bottomB )
    {
        return false;
    }
 
    if( rightA <= leftB )
    {
        return false;
    }
 
    if( leftA >= rightB )
    {
        return false;
    }
 
    //Si conditions collision detectee
    return true;
}

// void Fond::tailleBMP(const std::string &file, int &h, int &lg){

// 	static constexpr size_t HEADER_SIZE = 54;

//     std::ifstream bmp(file, std::ios::binary);

//     std::array<char, HEADER_SIZE> header;
//     bmp.read(header.data(), header.size());

//     lg = *reinterpret_cast<uint32_t *>(&header[18]);
//     h = *reinterpret_cast<uint32_t *>(&header[22]);

	
// }