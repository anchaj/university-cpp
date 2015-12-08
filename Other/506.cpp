#include <iostream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	
	int c;
	string linia;
	cin>>c;
	getline(cin, linia);
	for(int z=0;z<c;z++){
		
		
		
		
		int podstawowy_indeks,konczacy_indeks,suma_powtorzen;
		

		getline(cin, linia);
		
		
		for(int i=0;i<linia.size();i++){
			int j=i;
			suma_powtorzen=0; podstawowy_indeks=i;
			while(linia[j]==linia[j+1]){
				suma_powtorzen++;
				j++;

			}
			
			if(linia[j]!=linia[j+1] || j+1==linia.size())konczacy_indeks=j;

			if(suma_powtorzen>1){
				cout<<linia[podstawowy_indeks]<<suma_powtorzen+1;
			}
			else if(suma_powtorzen==0){
				cout<<linia[podstawowy_indeks];
			}
			else if(suma_powtorzen==1){
				cout<<linia[podstawowy_indeks]<<linia[podstawowy_indeks];
			}
			
			i+=suma_powtorzen;

		}
		cout<<endl;
		
	}
	return 0;
}
