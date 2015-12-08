#include <iostream>
#include <cmath>
using namespace std;
void wczytaj(int *tablica, int n)					  
{		
		int a;
     for (int i = 0; i <n; i++)
				cin>>tablica[i];
}
void zamien (int &a, int &b)
{
     int tmp=a;
     a=b;
     b=tmp;
}
void wydruk(int *tablica, int n)					  
{		
     for (int i = 0; i <n; i++)
				cout<<tablica[i]<<" ";
}
void odwracanie(int *tablica, int n)
{
		for (int i = n-1; i >=0; i--)
				cout<<tablica[i]<<" ";
}
void sortowanie(int *tablica,int p)
{
	int tmp;
	for (int j=0;j<p-1;j++)
		for (int i=0;i<p-1-j;i++)
			if (tablica[i]>tablica[i+1])
				swap(tablica[i],tablica[i+1]);
}
int main ()
{
	int m;
	cin>>m;
	int *tablica = new int[m];
	wczytaj(tablica,m);
	wydruk(tablica,m);
	cout << endl;
	odwracanie(tablica,m);
	cout << endl;
	zamien (tablica[0],tablica[m-1]);
	wydruk(tablica,m);
	cout << endl;
	sortowanie (tablica,m);
	wydruk(tablica,m);
	
}
