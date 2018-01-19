#pragma once 
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <map>

using namespace std; 

class Niveau{
private:
	int _id; // identifiant du niveau 
public:
	Niveau(int x):_id(x){};
	map<int, int> Init(); // A chaque niveau marque par un identifiant on associe le score max à atteindre 



};
