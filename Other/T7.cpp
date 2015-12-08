// M J
#include <iostream>
#include <cstdio>
#define L unsigned long long
using namespace std;string w="",t;char f(int a){if(!a)w+=t[0];if(a==1)w+=t[1];if(a==2)w+=t[2];if(a==3)w+=t[3];if(a==4)w+=t[4];if(a==5)w+=t[5];if(a==6)w+=t[6];if(a==7)w+=t[7];if(a==8)w+=t[8];if(a==9)w+=t[9];}L d(L x){f(x%10);if(x>10)d(x/10);}main(){L i,b,c;cin>>i;while(i--){cin>>b>>c>>t;b=b%c;d(b);for(int j=w.size()-1;j>=0;j--)cout<<w[j];cout<<endl;w="";}}
