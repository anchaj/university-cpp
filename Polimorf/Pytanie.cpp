#include "pytanie.h"

Pytanie::Pytanie() : N(0), odp(0) {}
Pytanie:: Pytanie(int N, Odpowiedzi *odp) : N(N), odp(odp) {}

int  Pytanie::Poprawne()
{
	int ilosc=0;
	for(int i=0; i<N;i++)
       if(odp[i]==OK_MARKED)
       ilosc++;
	return ilosc;
}

int  Pytanie::Bledne()
{
	int ilosc=0;
	for(int i=0; i<N;i++)
       if(odp[i]==BAD_MARKED)
       ilosc++;
	return ilosc;

}

int Pytanie::Puste()
{
	int ilosc=0;
	for(int i=0; i<N;i++)
       if(odp[i]==BAD_UNMARKED or odp[i]==OK_UNMARKED)
       ilosc++;
	return ilosc;

}

Pytanie::Odpowiedzi Pytanie::getOdpowiedz(int i)
{
	return odp[i];
}
int Pytanie::getN()
{
   return N;
}
