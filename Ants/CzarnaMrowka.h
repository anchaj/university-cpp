//Mateusz Jachna
#ifndef CZARNAMROWKA
#define CZARNAMROWKA

#include <iostream>
#include "Mrowka.h"

using namespace std;

class CzarnaMrowka: public Mrowka{
	public:
		int uciekaj(){
		   return Mrowka::walcz();
		}
		int jedz(char * pokarm)
		{
		   cout<<"Jem w zasiegu mrowiska!\n";
		   return Mrowka::jedz(pokarm);
		}
};
#endif
