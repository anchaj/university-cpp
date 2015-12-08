#include <iostream>


using namespace std;
int main() {

	int tab[10];
	char znak;
	int ostatni=0,puste=0;
	while(cin>>znak)
	{
		
		if(znak=='+'){
			int a;
			cin>>a;
			
			if(puste<10)
			{
				tab[puste]=a;
				puste++;
				cout<<":)"<<endl;
			}
			else {
				cout<<":("<<endl;puste=10;
			}
			ostatni=puste-1;
			
		}
		if(znak=='-'){
			if(ostatni>=0){cout<<(int)tab[ostatni]<<endl;ostatni--;}
			else {cout<<":("<<endl;}
			puste=ostatni+1;
		}
	} 
	return 0;
}
