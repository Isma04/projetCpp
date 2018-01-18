#include <iostream>
#include <string>
#include "niveau.hh"
#include <map>



using namespace std;

int _Nb=4; // Le nombre de Niveaux que l'on veut 


map<int,int> Niveau::Init()
{
   map<int, int> Niveaux; //Une table qui associe le nom d'un animal à son poids
 int max=0;

 for( int i=1; i< _Nb; i++)
 {
  max=max+30;
  Niveaux[i]=max;
 }
return Niveaux;
}


/* J'aurai voulu tout mettre dans une fonction ici mais j'ai pas réussi 

int Niveau::Definir_Niveau(map<int,int> M)
{

map<int, int>::iterator it1=M.begin();
int V=it1->second;
cout << " hooolaaaa" << it1->second << endl;
it1++;

*/
