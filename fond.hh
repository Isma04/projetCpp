#include <SDL/SDL.h>
#include "Elem.hh"

class fond{
private:
	int _longueurEcran;
	int _hauteurEcran;
public:
	fond(int lg, int h):_longueurEcran(lg), _hauteurEcran(h){}; //taille de l'ecran
	int getLg(){return _longueurEcran;};
	int getH(){return _hauteurEcran;};
	void setLg(int lg){_longueurEcran = lg;};
	void setH(int h){_hauteurEcran = h;};
	void init();
	void anime(int x, int y);
	void input_handle();

};