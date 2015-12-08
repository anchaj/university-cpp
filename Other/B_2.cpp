//
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	char znak;
	int n,r,wynik=0;
	cin>>znak>>n>>r;
	if(znak=='c'){
		cout<< pow(r+r+1,n);
	}
	else
	{
		if (n==1) 
		{
			for(int i=-r;i<=r;i++)
			if(i*i<=r*r)wynik++;
		}
		if (n==2)
		{
			for(int i=-r;i<=r;i++)
			for(int j=-r;j<=r;j++)
			if(i*i+j*j<=r*r)wynik++;
		}
		if(n==3){
			for(int i=-r;i<=r;i++)
			for(int j=-r;j<=r;j++)
			for(int k=-r;k<=r;k++)
			if(i*i+j*j+k*k<=r*r)wynik++;
		}
		if(n==4){
			for(int i=-r;i<=r;i++)
			for(int j=-r;j<=r;j++)
			for(int k=-r;k<=r;k++)
			for(int l=-r;l<=r;l++)
			if(i*i+j*j+k*k+l*l<=r*r)wynik++;
		}
		if(n==5)
		{
			for(int i=-r;i<=r;i++)
			for(int j=-r;j<=r;j++)
			for(int k=-r;k<=r;k++)
			for(int l=-r;l<=r;l++)
			for(int m=-r;m<=r;m++)
			if(i*i+j*j+k*k+l*l+m*m<=r*r)wynik++;
		}
		if (n==6)
		{
			for(int i=-r;i<=r;i++)
			for(int j=-r;j<=r;j++)
			for(int k=-r;k<=r;k++)
			for(int l=-r;l<=r;l++)
			for(int m=-r;m<=r;m++)
			for(int n=-r;n<=r; n++)
			if(i*i+j*j+k*k+l*l+m*m+n*n<=r*r)wynik++;
		}
		if (n==7)
		{
			for(int i=-r;i<=r;i++)
			for(int j=-r;j<=r;j++)
			for(int k=-r;k<=r;k++)
			for(int l=-r;l<=r;l++)
			for(int m=-r;m<=r;m++)
			for(int n=-r;n<=r; n++)
			for(int o=-r;o<=r; o++)
			if(i*i+j*j+k*k+l*l+m*m+n*n+o*o<=r*r)wynik++;
		}
		if (n==8)
		{
			for(int i=-r;i<=r;i++)
			for(int j=-r;j<=r;j++)
			for(int k=-r;k<=r;k++)
			for(int l=-r;l<=r;l++)
			for(int m=-r;m<=r;m++)
			for(int n=-r;n<=r; n++)
			for(int o=-r;o<=r; o++)
			for(int p=-r;p<=r; p++)
			if(i*i+j*j+k*k+l*l+m*m+n*n+o*o+p*p<=r*r)wynik++;
		}
		if (n==9)
		{
			for(int i=-r;i<=r;i++)
			for(int j=-r;j<=r;j++)
			for(int k=-r;k<=r;k++)
			for(int l=-r;l<=r;l++)
			for(int m=-r;m<=r;m++)
			for(int n=-r;n<=r; n++)
			for(int o=-r;o<=r; o++)
			for(int p=-r;p<=r; p++)
			for(int s=-r;s<=r; s++)
			if(i*i+j*j+k*k+l*l+m*m+n*n+o*o+p*p+s*s<=r*r)wynik++;
		}
		if (n==10)
		{
			for(int i=-r;i<=r;i++)
			for(int j=-r;j<=r;j++)
			for(int k=-r;k<=r;k++)
			for(int l=-r;l<=r;l++)
			for(int m=-r;m<=r;m++)
			for(int n=-r;n<=r; n++)
			for(int o=-r;o<=r; o++)
			for(int p=-r;p<=r; p++)
			for(int s=-r;s<=r; s++)
			for(int t=-r;t<=r; t++)
			if(i*i+j*j+k*k+l*l+m*m+n*n+o*o+p*p+s*s+t*t<=r*r)wynik++;
		}
		cout<<wynik<<endl;
	}	
	return 0;
}
