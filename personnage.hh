#include "Elem.hh"
#include <string>

class Personnage: public Elem{
protected:
	std::string _name;
	FILE* perso; //aspect perso ???
public:
	Personnage(int x, int y, std::string name):(_posX(x),_posY(y),_name(name)){};
	virtual void Deplacement(int x, int y);
};