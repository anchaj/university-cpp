//Mateusz Jachna
#include <iostream>
#include <cstdio>
using namespace std;

struct Element{
	int wartosc;
	Element* naDole;
};
struct Stos{
	Element * szczyt;
	void stworzStos(){
		szczyt = 0;
	}
	void usunStos(){
		while(szczyt != 0)
			zdejmij();
	}
	void wloz(int x){
		Element * nowy = new Element;
		nowy->wartosc = x;
		nowy->naDole = szczyt;
		szczyt = nowy;
	}

	int zdejmij(){
		if(szczyt != 0){
			int x = szczyt->wartosc;
			Element * koniec = szczyt;
			szczyt = koniec->naDole;
			koniec->naDole = 0;
			delete koniec;
			return x;
		}
	}
};
void zrob_stos(Stos &dowolny)
{
	int tmp=0;
	dowolny.stworzStos();
	dowolny.wloz(-1);
	do {
		cin>>tmp;
		dowolny.wloz(tmp);
	} while(tmp!=0);
}
void wypisz_stos(Stos &dowolny)
{
	int i=0;
    while(dowolny.szczyt->wartosc!=-1){
    	int tmp=dowolny.zdejmij();
    	i++;
    	if(tmp!=0) cout<<tmp<<" ";
	}
	if(!i) cout<<i;
	cout<<endl;
	dowolny.usunStos();
}
void suma(Element *wsk1,Element *wsk2,Stos &doc)
{
	if(wsk1->wartosc==0 )wsk1=wsk1->naDole;
	if(wsk2->wartosc==0)wsk2=wsk2->naDole;
	while(wsk1->wartosc!=-1){
		bool wloz=true;
		Element *wskDoc = doc.szczyt;
		while(wskDoc->wartosc!=-1){
			if(wskDoc->wartosc == wsk1->wartosc) {
				wloz=false;
				break;
			}
			wskDoc=wskDoc->naDole;
		}
		if(wloz) doc.wloz(wsk1->wartosc);
		wsk1=wsk1->naDole;
	}
	while(wsk2->wartosc!=-1){
		bool wloz=true;
		Element *wskDoc = doc.szczyt;
		while(wskDoc->wartosc!=-1){
			if(wskDoc->wartosc == wsk2->wartosc) {
				wloz=false;
				break;
			}
			wskDoc=wskDoc->naDole;
		}
		if(wloz and wsk2->wartosc != -1) doc.wloz(wsk2->wartosc);
		wsk2=wsk2->naDole;
	}
}
void roznica(Element *wsk1,Element *wsk2, Stos &doc)
{
	Element *tmp2=wsk2,*tmp1=wsk1;
	while(tmp1->wartosc!=-1){
		bool wloz=true;
		tmp2=wsk2;
		while(tmp2->wartosc!=-1){
			if(tmp1->wartosc == tmp2->wartosc)
			{
				wloz=false;
				break;
			}
			tmp2=tmp2->naDole;
		}
		if(wloz and tmp1->wartosc != -1) doc.wloz(tmp1->wartosc);
		tmp1=tmp1->naDole;
	}
}
void iloczyn (Element *wsk1, Element *wsk2, Stos &doc)
{
	if(wsk1->wartosc==0)wsk1=wsk1->naDole;
	if(wsk2->wartosc==0)wsk2=wsk2->naDole;
	while(wsk1->wartosc!=-1){
		bool war1=false,war2=true;
		Element *wsk_doc = doc.szczyt,*tmp_wsk2 = wsk2;
		while(wsk_doc->wartosc!=-1){
			if(wsk1->wartosc == wsk_doc->wartosc)
			{
				war2=false;
				break;
			}
			wsk_doc=wsk_doc->naDole;
		}
		if(war2==false)
		{
			wsk1=wsk1->naDole;
			continue;
		}
		while(tmp_wsk2->wartosc!=-1){
			if(wsk1->wartosc == tmp_wsk2->wartosc)
			{
				war1=true;
				break;
			}
			tmp_wsk2=tmp_wsk2->naDole;
		}
		if (war1 and war2 and wsk1->wartosc!=-1){
			doc.wloz(wsk1->wartosc);
		}
		wsk1=wsk1->naDole;
	}

}
int main(){
	int ilosc_testow;
	cin>>ilosc_testow;
	for(int i=0;i<ilosc_testow;i++){
		Stos s1,s2,s3;
		zrob_stos(s1);
		zrob_stos(s2);
		zrob_stos(s3);
		int w1,w2,w3;
		char k1,k2;
		do
		{
			cin>>w1>>k1>>w2>>k2>>w3;
			Stos tmp;
			Element *wsk1,*wsk2,*wsk3;
			tmp.stworzStos();
			tmp.wloz(-1);
			if(w1==1) wsk1=s1.szczyt;
			if(w1==2) wsk1=s2.szczyt;
			if(w1==3) wsk1=s3.szczyt;
			if(w2==1) wsk2=s1.szczyt;
			if(w2==2) wsk2=s2.szczyt;
			if(w2==3) wsk2=s3.szczyt;
			switch(k1){
			case 'U':
				{
					suma(wsk1,wsk2,tmp);
					break;
				}
			case 'C':
				{
					roznica(wsk1,wsk2,tmp);
					break;
				}
			case 'I':
				{
					iloczyn(wsk1,wsk2,tmp);
					break;
				}
			case 'S':
				{
					Stos Suma,Iloczyn;
					Iloczyn.stworzStos();
					Iloczyn.wloz(-1);
					iloczyn(wsk1,wsk2,Iloczyn);
					Suma.stworzStos();
					Suma.wloz(-1);
					suma(wsk1,wsk2,Suma);
					Element *wsk_suma=Suma.szczyt,*wsk_iloczyn=Iloczyn.szczyt;
					roznica(wsk_suma,wsk_iloczyn,tmp);
					Suma.usunStos();
					Iloczyn.usunStos();
					break;
				}
			}
			Stos wynik;
			wynik.stworzStos();
			wynik.wloz(-1);
			wsk2=tmp.szczyt;
			if(w3==1) wsk3=s1.szczyt;
			if(w3==2) wsk3=s2.szczyt;
			if(w3==3) wsk3=s3.szczyt;
			switch(k2){
			case 'U':
				{
					suma(wsk2,wsk3,wynik);
					break;
				}
			case 'C':
				{
					roznica(wsk2,wsk3,wynik);
					break;
				}
			case 'I':
				{
					iloczyn(wsk2,wsk3,wynik);
					break;
				}
			case 'S':
				{
					Stos Suma,Iloczyn;
					Iloczyn.stworzStos();
					Iloczyn.wloz(-1);
					iloczyn(wsk2,wsk3,Iloczyn);
					Suma.stworzStos();
					Suma.wloz(-1);
					suma(wsk2,wsk3,Suma);
					Element *wsk_suma=Suma.szczyt,*wsk_iloczyn=Iloczyn.szczyt;
					roznica(wsk_suma,wsk_iloczyn,wynik);
					Suma.usunStos();
					Iloczyn.usunStos();
					break;
				}
			}
			tmp.usunStos();
			wsk1=wynik.szczyt;
			while(wsk1->wartosc!=-1)
			{
				wsk2=wynik.szczyt;
				while(wsk2->wartosc!=-1)
				{
					if(wsk2->wartosc>wsk1->wartosc and wsk1->wartosc!=0 and wsk2->wartosc!=0)
					{
						swap(wsk2->wartosc,wsk1->wartosc);
					}
					wsk2=wsk2->naDole;
				}
				wsk1=wsk1->naDole;
			}
			if(w1!=0)wypisz_stos(wynik);
			wynik.usunStos();
		}while (w1!=0);
	}
	return 0;
}
