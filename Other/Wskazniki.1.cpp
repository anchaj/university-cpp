#include <iostream>

using namespace std;
int main(int argc, char** argv) {
	int A[]={2,6,5,1,3};
	int *p;
	p=A;
	
	cout<<*p<<endl;
	cout<<*p+2<<endl;
	cout<<*(p+2)<<endl;	
	cout<<&p<<endl;
	cout<<&p+1<<endl;
	cout<<p<<endl;
	cout<<A<<endl;
	cout<<&A[0]<<endl;
	cout<<&A[0]+3<<endl;
	cout<<A+3<<endl;
	cout<<p+(*(p+4)-3)<<endl;
	
	return 0;
}
