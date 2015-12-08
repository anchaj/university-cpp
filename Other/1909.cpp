#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	long long pierwszy_wyraz_w_lini=0,kolejne_wyrazy_w_linii=0,linia=0,suma_sumarum=0;
	cin>>pierwszy_wyraz_w_lini;
	do{
		
		cin>>pierwszy_wyraz_w_lini;
		if (pierwszy_wyraz_w_lini==0){
			cout<<linia<<endl<<suma_sumarum<<endl;break;
		}
		linia=pierwszy_wyraz_w_lini;
		do
		{
			cin>>kolejne_wyrazy_w_linii;
			if(kolejne_wyrazy_w_linii==0){
				cout<<linia<<endl;break;
			}
			linia+=kolejne_wyrazy_w_linii;
			
		} while(kolejne_wyrazy_w_linii!=0);
	} while(pierwszy_wyraz_w_lini!=0);
	return 0;
}
