//Mateusz Jachna
#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	int a,b,c;
	cin>>a>>b;
	for(int i=0;i<b;i++){
		cin>>c;
		if(a%c==0){
			cout<<"TAK";
			return 0;
		}
		
	}
	cout<<"NIE";
	return 0;
}
