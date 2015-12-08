//Mateusz Jachna
#include <iostream>
using namespace std;
main(){
char w;int i,j,c,m,n;int T[100][100];
	do
	{
		cin>>w;	
		if(w=='C'){
			for(i=0;i<100;i++)for(j=0;j<100;j++)T[i][j]=-1;
			cin>>m>>n;
			for(i=0;i<m;i++)for(j=0;j<n;j++)cin>>T[i][j];
		}
		if(w=='A'){cin>>i>>j>>c;T[i][j]=c;}
		if(w=='B'){
			cin>>i;j=0;
			while(T[i][j]!=-1)
				{
				cin>>T[i][j];j++;
				}
		}
		if(w=='D'){cin>>i>>j;cout<<T[i][j]<<endl;}
		if(w=='E'){cin>>i>>j>>m;cout<<T[i][j]*m<<endl;}
		if(w=='F'){
				m=0,j=0;cin>>i;
				while(T[i][j]!=-1)
				{
					cin>>n;
					m+= T[i][j]*n;
					j++;
				}
				cout<<m<<endl;
		}
		if(w=='G'){
				cin>>j;
				najm=T[0][j];
				m=0;
				for(i=0;i<100;i++){
					if(n>T[i][j]&&T[i][j]!=-1){
						najm=T[i][j];
						m=i;
					}
				}
				cout<<m<<endl;
		}
		
		
		else{cin>>i>>j;
				for(c=0;c<100;c++){
					swap(T[i][c],T[j][c]);	
				}
			}
	} while(w!='K');
	bool e=0;
	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
			if(T[i][j]!=-1){cout<<T[i][j]<<" ";e=1;}
		}
		if(e){cout<<endl;e=0;}
	}
}
