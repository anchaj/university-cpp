#include <iostream>
#include <string>

using namespace std;
int main(int argc, char** argv) {
	string a,b="tekst";
	cin>>a;
	if(a==b)
	{
		cout<<"podano poprawny kod\n";
	}
	else cout<< "BLAD";
	return 0;
}
