
#ifndef MROWKA
#define MROWKA

#include<iostream>

using namespace std;

class Mrowka{
    private:
        int pewnosc;

        static int wynikWalki;

	public:
        virtual ~Mrowka(){}

        int licz(char * arg, int ile)
        {
           return 0;
        }


        Mrowka()
        : pewnosc(0)
        {}

        /**
        Wykonuje ruch - jako wynik zwraca pewien kod zwišzany z ruchem (jeli ruch kończy się niepowodzeniem zwracane jest 0)
        */
		int idz(char * cel){return 0;}

		/**
		Zjada przekazany w argumencie pokarm, zwraca komunikat, co jedzš
		*/
		int jedz(char * pokarm){return 0;}

        /**
           Zwraca 1 jesli ucieczka się powiodła i 0 jeli się nie powiodła.
        */
        int uciekaj(){return 0;}

        /**
        W przypadku wygranej zwraca wartoć dodatniš, a w przypadku przegranej ujemnš, 0 to kod błędu
        */
        int walcz(){return 0;}

		/**
		Dodaje jeden do pewnoci - zwraca wynikowš pewnoć.
		*/
		int dodajPewnosci(){return 0;}

		/**
		Odejmuje jeden od pewnoci - zwraca wynikowš pewnoć.
		*/
		int odejmijPewnosci(){return 0;}

        /**
		Dodaje jeden do pewnoci - zwraca wynikowš pewnoć.
		*/
		int pobierzPewnosc(){return 0;}

        /**
        Realizuje odpoczynek - zwraca kod zwišzany z odpoczynkiem.
        */
        int odpocznij(){return 0;}

        /**
        Metoda odpowiadajšca za latanie (tylko dla skrzydlatych mrówek)
        */
        int lec(char* cel){return 0;}
};

#endif
