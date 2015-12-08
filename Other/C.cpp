//Mateusz Jachna
#include <iostream>
#include <windows.h>
using namespace std;
void setcol(unsigned int abc){
     HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(handle, abc);
     }
int main(){
	int e=1,L,D,I,S1,S2,ZC,ZT,s;
	
	while(e--){
		//cout<<"L : oznacza dlugosc linii\n"; cin>>L;
		cout<<"D : oznacza wysokosc pojedynczej figury\n"; cin>>D;
		cout<<"I : oznacza sumaryczna ilosc figur\n"; cin>>I;
		cout<<"S1: oznacza skok (nachylenie) figur wchodzacych w sklad choinki\n"; cin>>S1;
		cout<<"S2: oznacza o ile kolejne choinki sa szersze od poprzednich\n"; cin>>S2;
		cout<<"ZC: oznacza kod ASCII znaku reprezentujacego wnetrze naszej choinki (32-126)\n"; cin>>ZC;
		cout<<"ZT: oznacza kod ASCII znaku reprezentujacego tlo naszego obrazka (32-126)\n"; cin>>ZT;
		//cout<<"KC: oznacza kolor wnetrza choinki\n";
		//cout<<"KT: oznacza kolor tla choinki\n";
		string kolor;
		cout<<"Mozesz tez podac kolor tla i wypelnienia choinki\n(domyslnie tlo-biale, wypelnienie zielone)\n"
			<<"Wpisz TAK lub NIE :* ";
		cin>>kolor; 
		for(int i=0;i<3;i++) kolor[i]=toupper(kolor[i]);
		int tlo=15,choinka=10;
		if(kolor == "TAK")
		{
			string kolory;
			cout<<"Jezeli chcesz zobaczyc jak wygladaja poszczegolne kolory wpisz: \"kolory\" ";
			cin>>kolory;
			for(int i=0;i<kolory.length();i++) {kolory[i]=toupper(kolory[i]);}
			if(kolory == "KOLORY"){
				for(int i=0;i<256;i++){
					setcol(i);
					cout<<"Numer :"<<i<<" KOCHAM CIE MALA :*\n";
				}
			setcol(7);
			cout<<"Podaj numer koloru tla     : "; cin>>tlo;
			cout<<"Podaj numer koloru choinki : "; cin>>choinka;
			}
		}
		L = I*S2 + D*S1;
		if(L%2)s=L/2;
		else s=L/2-1;
		for(int k=0;k<I;k++){
			for(int j=0;j<D;j++){
				char *c=new char[L];
				for(int l=0;l<L;l++){
					c[l]=(char)ZT;
				}
				int x=1+(S1*j)+(S2*k)/2;
				for(int t=s,p=s,z=0;z<x;t--,p++,z++){
					if(t>=0){
						c[t]=(char)ZC;
						}
					if(p<=L){
						c[p]=(char)ZC;
					}
					if(p<L&&x-1==z&&(S2*k)%2)c[p+1]=(char)ZC;
				}			
				for(int l=0;l<L;l++){
					if(c[l]==ZC) setcol(choinka);
					else setcol(tlo);
					cout<<c[l];
				}
				cout<<endl;
			}
		}
	}
	system("PAUSE");
}
