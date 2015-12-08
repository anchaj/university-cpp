//Mateusz Jachna
#include <iostream>
using namespace std;
int nr=0,*iX_y,m,n,k;
long long *wart;
void sort2(int i,int j,long long *T,int p)
{
	if(i<p-j)
	{
		if(T[i]>T[i+1])swap(T[i],T[i+1]);
		sort2(i+1,j,T,p);
	}
}
void sort1(int j,long long *T,int p)
{
	if (j<p)
	{
		sort2(0,j,T,p);
		if(j+1<p)sort1(j+1,T,p);
	}
	
}
long long H(int i,int k,int *L,int x)
{
    if(i==k)
      return L[i];
    else
      return H(i+1,k,L,x)*x+L[i];
}
void wyp(int e)
{
	if(e<m){
		cout<<wart[e]<<" ";
		wyp(e+1);
		if(e+1==m)cout<<endl;
		}
}
void wcz(int e)
{
	if(e<m){
		cin>>iX_y[e];
		wcz(e+1);
	}
}
void wcz_z(int *L,int i,int k)
{
	if (i<=k) {
		cin>>L[i];
		wcz_z(L,i+1,k);
	}
}
void dla_X(int *L,int nr_X,int k)
{
	wart[nr_X]=H(0,k,L,iX_y[nr_X]);
	if(nr_X+1<m)dla_X(L, nr_X+1,k);
}
void z()
{
	cin>>k;
	int *L= new int[k+1];
	wcz_z(L,0,k);
	dla_X(L,0,k);
	wyp(0);
	nr++;
	if(nr<n)z();
}
main(){
	cin>>n>>m;
	iX_y=new int[m];
	wart=new long long[m];
	wcz(0);
	z();
}
