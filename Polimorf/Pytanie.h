#ifndef PYTANIE_H
#define PYTANIE_H

class Pytanie
{
public:
   enum Odpowiedzi
   {
      BAD_MARKED, BAD_UNMARKED, OK_MARKED, OK_UNMARKED
   };
	Pytanie();
	Pytanie(int N, Odpowiedzi *odp);
	int Poprawne();
	int Bledne();
	int Puste();
	Odpowiedzi getOdpowiedz(int i);
	int getN();
private:
		int N;
		Odpowiedzi *odp;
};

#endif
