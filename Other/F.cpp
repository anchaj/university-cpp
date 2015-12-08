//Mateusz Jachna
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
int N,M; 
void szuk(int **tab,int *d,int x,int y,int s)
{
	*(*(tab+x)+y)=0;	
	if(*(*(tab+x)+y-1)==s&&y-1>=0)szuk(tab,d,x,y-1,s);
	if(*(*(tab+x)+y+1)==s&&y+1<*(d+x))szuk(tab,d,x,y+1,s);
}
int main() {
	scanf("%i",&N);
	//cin >>N;
	int **tab,*t_dl;
	tab=(int**)malloc(sizeof(int*)*N); 
	t_dl=(int*)malloc(sizeof(int)*N);
	for(int i=0;i<N;i++){
		scanf("%i",&M);
		//cin>>M;
		*(t_dl+i)=M;
		*(tab+i)=(int*)malloc(sizeof(int) * M);
		for(int j=0;j<M;j++) scanf("%i",&*(*(tab+i)+j));
		//cin>>*(*(tab+i)+j);
	}
	char z;
	do{
		scanf("%c",&z);
		//cin>>z;
		if(z=='Z'){
			int n,m,kr;
			bool p;
			scanf("%i %i",&n,&m);
			//cin>>n>>m;
			if(*(t_dl+n)==*(t_dl+m))std::swap(*(tab+n),*(tab+m));
			else {
				if(*(t_dl+n)>*(t_dl+m)){
					kr = *(t_dl+m);
					*(tab+m)=(int*)realloc(*(tab+m),sizeof(int*) * *(t_dl+n));
					*(t_dl+m)=*(t_dl+n);
					p=1;
				}
				else {
					kr=*(t_dl+n);
					*(tab+n)=(int*)realloc(*(tab+n),sizeof(int*) * *(t_dl+m));
					*(t_dl+n)=*(t_dl+m);
					p=0;
				}
				std::swap(*(tab+n),*(tab+m));
				if(p)
				{
					*(tab+n)=(int*)realloc(*(tab+n),sizeof(int*)*kr);
					*(t_dl+n)=kr;
				}
				else{
					*(tab+m)=(int*)realloc(*(tab+m),sizeof(int*)*kr);
					*(t_dl+m)=kr;
				}
			}
		}
		if(z=='U'){
			int n;
			scanf("%i",&n);
			//cin>>n;	
			free(*(tab+n));
			for(int i=n;i<N-1;i++)
			{ 
				*(tab+i)=*(tab+i+1);	
				*(t_dl+i)=*(t_dl+i+1);
			}
			N--;	
			t_dl=(int*)realloc(t_dl,sizeof(int*)*N);
			tab=(int**)realloc(tab,sizeof(int*)*N);
		}
		if(z=='W'){
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<*(t_dl+i);j++)
				{
					printf("%i ",*(*(tab+i)+j));	
					//cout<<*(*(tab+i)+j)<<" ";
				}
				puts("");
				//cout<< endl;
			}
			puts("");
			//cout<<endl;
		}
		if(z=='C')
		{
			int n;
			scanf("%i",&n);
			//cin>>n;
			N++;
			tab=(int**)realloc(tab,sizeof(int*)*N);
			t_dl=(int*)realloc(t_dl,sizeof(int)*N);
			*(t_dl+(N-1))=*(t_dl+n);
			*(tab+(N-1))=(int*)malloc(sizeof(int)*(*(t_dl+n)));
			
			for(int i=0;i<*(t_dl+(N-1));i++){
				*(*(tab+(N-1))+i)=*(*(tab+n)+i);
			}
		}
		if(z=='P')
		{
			int n;
			scanf("%i",&n);
			//cin>>n;
			int d=*(t_dl+n);
			*(tab+n)=(int*)realloc(*(tab+n),sizeof(int*)*2*d);
			for(int i=0;i<d;i++){
				*(*(tab+n)+i+d)=*(*(tab+n)+i);
			}	
			*(t_dl+n)*=2;
		}
		if(z=='S'){
			int n,m;
			scanf("%i %i",&n,&m);
			//cin>>n>>m;
			int s=*(*(tab+n)+m);
			for (int i=n;i>=0;i--){
				if (*(*(tab+i)+m)==s)szuk(tab,t_dl,i,m,s);
				else break;
			}
			for (int i=n+1;i<N;i++){
				if (*(*(tab+i)+m)==s)szuk(tab,t_dl,i,m,s);
				else break;
			}
			for (int i=0;i<N;i++) // przeszukuje cala tablice
			{
				int ile=0;
				for (int j=0;j<*(t_dl+i);j++)
				{
					if (*(*(tab + i) + j)==0)
						ile++;
					else if(ile!=0) break;
				}
				if (!ile) continue;
				if (ile < *(t_dl+i)){
					// ile = ilosc zer
					int indeks_zera = 0;
					for (int j=0;j<*(t_dl+i);j++){
						if (*(*(tab + i) + j)==0){
							indeks_zera = j;
							break;
						}
					}
					for (int j=indeks_zera;j<*(t_dl+i);j++){
						*(*(tab + i)+j) = *(*(tab + i)+j+ile);
					}
					*(t_dl+i)-=ile;
					*(tab+i) =(int*) realloc(*(tab+i),sizeof(int*) * (*(t_dl+i)));
				}
			}
			for (int i=0;i<N;i++){
				if (*(*(tab+i))==0){
					free(*(tab+i));
					for(int k=i;k< N-1;k++)
					{ 
						*(tab+k)=*(tab+k+1);	
						*(t_dl+k)=*(t_dl+k+1);
					}
					N--;
					t_dl=(int*)realloc(t_dl,sizeof (int*) *N);
					tab=(int **)realloc(tab,sizeof(int*)*N);
					i--;
				}
			}
		}
	} while(z!='K');
	return 0;
}
