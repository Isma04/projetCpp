#include <stdio.h>
#include <SDL/SDL.h>
#include "joueur.hh"


int main(void)
{
	Fond f(690,390);
	f.init();
	f.anime(0,0);

	return 0;
}