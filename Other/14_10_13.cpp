#include <iostream>

using namespace std;

	
    

int main() {
	int liczba,n,m=0;
	cin>>liczba;
	
	//deklaracja dynamicznych tablic
	int *Tab = new int[n];
	for (int i=0;i<n;i++){
		Tab[i]=false;
	}
	
	for (int i=2;i<=n;++i) 
    {
        if(Tab[i]!=1)		
        {
        	for (int j=2*i;j<=n;j+=i) {Tab[j]=true;m++;} //wykreslanie liczb pierwszych
    	}
    }    Tab[0]=true;
	Tab[1]=true;
	Tab[2]=true;
	
	int *Tab2=new int[m];
	for(int k=0,l=0;k<n;k++)
	{
		if(Tab[k]==1) {Tab2[l]=Tab[k];l++;}
	}
	
	
	for(int i=0;i<n;i++){
		cout<<Tab[n]<<endl;
	}
	
	return 0;
}
