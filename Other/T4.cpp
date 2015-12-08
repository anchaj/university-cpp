// M J
#include <cstdio>
main(){int a,b,c,d,n,w;scanf("%i",&a);while(a--){scanf("%i%i%i",&b,&c,&d);n=b;w=b;if(w<c)w=c;if(n>c)n=c;if(w<d)w=d;if(n>d)n=d;printf("%i %i\n",n,w);}}
