//M J
#include <cstdio>
int P(int &p){long j=2;while(j<p)if(!(p%j++))p=0;}main(){int t,a;scanf("%i",&t);while(t--){scanf("%i",&a);if(a==1)puts("NIE");else{P(a);if(a)puts("TAK");}if(!a)puts("NIE");}}

