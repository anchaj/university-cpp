//M J
#include <iostream>
#include <cmath>
int w=0,z,r,n;void a(int N,int r){int c=sqrt(r),*t=&w;if(N>1)for(int i=-c;i<=c;i++)a(N-1,r-i*i);else *t+=c+c+1;}main(){char z;std::cin>>z>>n>>r;if(z=='c')std::cout<<pow(r+r+1,n);else{a(n,r*r);std::cout<<w;}}	


