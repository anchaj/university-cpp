#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	int a=0,b=1,n;
	cin>>n;
	if (!a) cout << a;
	else {
		 for(int i=0; i < n-1; i++) {
        	swap(a, b);
        	b = b+a;
    		}
    		cout<<b;
    	}

return 0;
}
