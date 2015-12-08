// M J
#include <cstdio>
main(){int a,i,n,w,t;scanf("%i",&a);while(a--){scanf("%i",&i);scanf("%i",&n);w=n;while(--i){scanf("%i",&t);if(t>w)w=t;if(t<n)n=t;}printf("%i %i\n",n,w);}}
