// Mateusz Jachna
#include <iostream>
using namespace std;
bool static przesun(char *s)
{
	char *k=s;
	while (*(k)!=0)
	{
		*k=*(k+1);
		k++;
	}
return true;
}
void static przeksztalc(char *s,char (*f)(char) )
{
	if(s)
	{
		char *wsk = s;
		while(*wsk!=0)
		{
			*wsk = f(*wsk);
			wsk++;
		}
	}	
}
bool static filtruj (char *s,bool (*f)(char) )
{
	char *wsk = s;
	bool wart_f=0;
	if (s && f)
	{
		while(*wsk!=0)
		{
			if(f(*wsk))przesun(wsk);
			else wsk++;
		}	
	}
}
bool static filtruj(char* s, char* k)
{
	
	if (s && k)
	{
		char *wsk_k=k;
		while(*wsk_k!=0)
		{
			char *wsk_s=s;
			while(*wsk_s!=0)
			{
				if (*wsk_s==*wsk_k)
				{
					przesun(wsk_s);
				}
				else ++wsk_s;
			}
			wsk_k++;
		}
	}
}
bool static filtruj(char **poczatek, char **koniec, bool(*f)(char))
{
	if (poczatek && koniec && f){
		char **srodek = koniec-1;
		bool modyfikacja = 0;
		cout<<**srodek<<endl;
		while(**poczatek<**srodek)
		{
			cout<<"dla "<<**poczatek<<" wartosc f to: "<<f(**poczatek)<<endl;
			if(f(**poczatek)) przesun(*poczatek);
			poczatek++;
		}

		return modyfikacja;
	}

}
 
void static szyfruj(char* tablica, char* kod)
{
}
 
void static przetwarzaj(char* tablica, ...)
{
}
