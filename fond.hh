#pragma once 
#include <SDL/SDL.h>
#include <string>
#include "joueur.hh"
#include "piece.hh"
#include <vector>

class Fond{

public:
	int _longueurEcran;
	int _hauteurEcran;
	Fond(int lg, int h):_longueurEcran(lg), _hauteurEcran(h){};
	void PrintSDL(SDL_Surface* font,SDL_Surface* dest,int x,int y,const char* text,...);
	//Initialise la fenetre du jeu et charge les images
	void init();
	//Fais le deplacement et collage 
	void anime(int x, int y, const int SOL, vector<string> &tableau);
	//Gere les evenements
	void input_handle(int &a, int &b,int &v, Joueur j, int &sautencours, Mur M, Policier C);
	// Libere les SDL_Surface
	void FreeS(SDL_Surface* &cop, SDL_Surface* &wall, SDL_Surface* &petitepiece, SDL_Surface* &zozor, SDL_Surface* &ecriture, SDL_Surface* &imageDeFond);
	//Changer la place de la piece en parcourant la liste dans p
	void ReInitPiece(SDL_Rect* &Piece_courante, Piece &p, SDL_Rect &positionPiece);
	// change la direction de deplacement du policier s'il est arrivé à traverser toute la longueur
	void MouvementPolicier(int &droite, SDL_Rect &positionCop);
	//Initialise la positiondu SDL_Rect r à x,y
	void InitRect(SDL_Rect &r, int x, int y);
};
