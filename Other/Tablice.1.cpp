#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>


using namespace std;
void WYPISZ(int tab[])
{
	for (int w=0;w<10;w++){
			cout<<w<< " "<<tab[w]<<endl;	
		}
	cout << endl;
}
void SWAP(int &a,int &b){
	a=a^b;
	b=a^b;
	a=a^b;
}
int main(int argc, char** argv) {
	int tab[10];
	double srednia=0;
	srand(time(NULL));
	for (int i=0;i<10;i++){
		
		tab[i]=rand();
		srednia+=tab[i];
		
	}	
	WYPISZ(tab);
	
	cout << "srednia arytm "<< srednia/10<<endl;
	cout << "srednia geometr "<< pow(srednia,0.1)<<endl;
	cout << "mediana to "<< (tab[4]+tab[5])/2<<"\n\n\n";
	//odwracanie tablicy
	for(int j=0;j<5;j++){
		SWAP(tab[j],tab[9-j]);
	}
	WYPISZ(tab);
	
	//przesuniecie w prawo o 1 element;
	for (int k=9;k>0;k--){
			SWAP(tab[k-1],tab[k]);
	}
	WYPISZ(tab);
	
	//sortowanie tablicy
	for (int l=0;l<9;l++){
		for (int m=0;m<9;m++){
			if (tab[m]>tab[m+1]) SWAP(tab[m],tab[m+1]);
		}
	}
	WYPISZ(tab);
	return 0;
}
