#include <stdio.h>
#include <SDL/SDL.h>
#include "joueur.hh"
#include <string>
#include "fond.hh"
#include <iostream>
#include <vector>

using namespace std; 




void pause(void){
	SDL_Event ev;
	SDL_WaitEvent(&ev);
}

int votreChoix(void)
{
	int rep;
	SDL_Event ev;
	SDL_PollEvent(&ev);
	if(ev.type == SDL_KEYDOWN){
		
		rep = (ev.key.keysym.sym == SDLK_ESCAPE) ? 1 : 0;	// 'rep = 1' si on appuie sur la touche Echap
																			// 'rep = 0' sinon
	}
	return rep;
}



int main(void)
{
	int quit = 0;
	// On cree un vector qui stocke tous les fonds 	
	vector<string> tableau;
    tableau.push_back("image/bahamas.bmp");
    tableau.push_back("image/euro.bmp");
    tableau.push_back("image/palaos.bmp");	
	do{
		Fond f(690,390);
		f.init();

		f.anime(0,290, 290, tableau);
		pause();					// la fenêtre du jeu affiche 'gameover'
									// et demande au joueur s'il veut recommencer ou quitter le jeu
		quit = votreChoix();
	} while(!quit);			// si on appuie sur la touche Echap : on quitte
									// on recommence sinon

	SDL_Quit();

	return 0;

}



// Y'vaais cette option dans le makefile mais ca faisait beuguer mon truc du coup je l'ai enlevé 
//LIBFLAGS= -ltinyxml2 

