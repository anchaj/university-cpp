//M J
#include <iostream>
#include <cmath>
using namespace std;

int P(int p){
long a=sqrt(p),j=2;

while(j<=p)if(!(p%j++))return 0;return 1;}




int main(){int t,a;cin>>t;while(t--){cin>>a;if(a==1){cout<<"NIE\n";}else if(P(a)==1)cout<<"TAK\n";else cout<<"NIE\n";}}

