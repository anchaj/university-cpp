#include <iostream>
#include "Polynomial.h"
using namespace std;
int main(){
int k;
Polynomial q, p, r=0.0;
cin >> k >> q >> p;
for(int i=0; i<k; ++i){
r+= q;
r*= p;
r-= q;
p++; --q;
}
cout << r;
return 0;
}
