#include <iostream>
#define TAB_MAX 100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int tab[TAB_MAX];
	int i_p_n=0,i_k_n=0,d_n=0;
	int indeks_poczatkowy,indeks_koncowy,dlugosc;
	for(int i=0;i<TAB_MAX-1;i++)
	{
		indeks_poczatkowy=i;dlugosc=0,indeks_koncowy=i;
		while(tab[indeks_koncowy]==tab[indeks_koncowy+1]){
			indeks_koncowy++;
		}
		if(dlugosc>d_n){
			d_n=dlugosc;
			i_p_n=indeks_poczatkowy;
			i_k_n=indeks_koncowy;
		}
	}
			
	return 0;
}
