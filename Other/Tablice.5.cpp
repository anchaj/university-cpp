#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
inline void WYPISZ(int tab[],int N)
{
	for (int w=0;w<N;w++){
			cout<<w<< " "<<tab[w]<<endl;	
		}
	cout << endl;
}
inline void SWAP(int &a,int &b){
	a=a^b;
	b=a^b;
	a=a^b;
}
int main(int argc, char** argv) {
	
	srand(time(NULL));
	int N=rand()%100;
	int *tab= new int[N];
	for (int z=0;z<N;z++){
		tab[z]=rand();
	}
	for (int l=0;l<N-1;l++){
		for (int m=0;m<N-1;m++){
			if (tab[m]>tab[m+1]) SWAP(tab[m],tab[m+1]);
		}
	}
	WYPISZ(tab,N);
	return 0;
}
