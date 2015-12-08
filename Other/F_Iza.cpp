// Krupa Izabela
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char** argv)
{
	int **tab;
	int *dlugosc_wierszy;
	int n, m;
	cin >> n; // n - ilosc wierszy, m -dlugosc kolejnego wiersza
	
	tab=(int**)malloc(sizeof(int*)*n); 
	dlugosc_wierszy=(int*)malloc(sizeof(int*)*n);
	
	for(int i=0; i<n; i++)
	{
		cin >> m;
		*(dlugosc_wierszy+i)=m;
		*(tab+i)=(int*)malloc(sizeof(int)*m); // zaalokowana pamiêc dla wiersza	
		
		for(int j=0; j<m; j++)
		{
			cin >>*(*(tab+i)+j); // chodzenie po tablicy
			//cout<<"i :" <<i <<" j :"<<j<<" "<<*(*(tab+i)+j)<<endl;
		}
	}
	
	char t; // tu wczytujê ró¿ne operacje
	
	do
	{
		cin >> t;
		if(t=='W')
		{
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<*(dlugosc_wierszy+i); j++)
				{
					cout << *(*(tab+i)+j) << " ";
				} cout << endl;
			} cout << endl;
		}
		
		if(t=='C')
		{	
			int c;
			cin >> c; // c-dodanie na koñcu tablicy nowego wiersza bêd¹cego kopi¹ wiersza o numerze c;
			int dl_c = *(dlugosc_wierszy+c);
			n++; // zwiêkszenie wierszy;
			tab=(int**)realloc(tab, sizeof(int*)*n); //zwiêkszamy ilosc wierszy
			dlugosc_wierszy=(int*)realloc(dlugosc_wierszy, sizeof(int)*n);  
			*(dlugosc_wierszy+n-1) = dl_c; 
			*(tab+n-1) = (int*)malloc(sizeof(int)*dl_c);
			
			for(int i=0;i<dl_c;i++)
			{
				*(*(tab+n-1)+i) = *(*(tab+c)+i);
			}
		}
		
		if(t=='P')
		{
			int p;
			cin >> p;
			*(tab+p)=(int*)realloc(*(tab+p),sizeof(int*)**(dlugosc_wierszy+p)*2);
			for(int i=0; i<*(dlugosc_wierszy+p); i++)
			{
				*(*(tab+p)+i+*(dlugosc_wierszy+p)) = *(*(tab+p)+i);
			}
			*(dlugosc_wierszy+p)*=2;
			
		}
		
		if(t=='U')
		{
			int u;
			cin >> u;
			free(*(tab+u));
			for(int i=u; i<n-1; i++)
			{
				*(tab+i)=*(tab+i+1);
				*(dlugosc_wierszy+i)=*(dlugosc_wierszy+i+1);
			}
			n--; //bo usunê³am jeden wiersz;
			dlugosc_wierszy=(int*)realloc(dlugosc_wierszy, sizeof(int*)*n);
			tab=(int**)realloc(tab, sizeof(int*)*n);
		}
		
		if(t=='Z')
		{
			int w=0; 
			int s,r;
			cin >> s >> r;
			if(*(dlugosc_wierszy+s) > *(dlugosc_wierszy+r))
			{
				w=1; //wiersz+s jest dluzszy
			}
			if(w==1)
			{
				
				*(tab+r)=(int*)realloc(*(tab+r),sizeof(int*)**(dlugosc_wierszy+s));
				swap(*(tab+s), *(tab+r));
				*(tab+s)=(int*)realloc(*(tab+s),sizeof(int*)**(dlugosc_wierszy+r));
			}
			else
			{
				*(tab+s)=(int*)realloc(*(tab+s),sizeof(int*)**(dlugosc_wierszy+r));
				swap(*(tab+s), *(tab+r));
				*(tab+r)=(int*)realloc(*(tab+r),sizeof(int*)**(dlugosc_wierszy+s));
			}
			swap(*(dlugosc_wierszy+s), *(dlugosc_wierszy+r));
		}
		if(t=='S')
		{
			int a, b;
			cin >> a >> b;
			int szukana=*(*(tab+a)+b);
			
			for(int i=a;i>=0;i--) //gora
			{
				if(*(*(tab+i)+b)==szukana)
				{
					for(int j=b;j>=0;j--)
					{
						if(*(*(tab+i)+j)==szukana)
						{
							*(*(tab+i)+j)=0;
						}
						else break;
					}
					for(int j=b+1;j<*(dlugosc_wierszy+i);j++)
					{
						if(*(*(tab+i)+j)==szukana)
						{
							*(*(tab+i)+j)=0;
						}
						else break;
					}
				}
				else break;
			}
			for(int i=a+1;i<n;i++) //dol
			{
				if(*(*(tab+i)+b)==szukana)
				{
					for(int j=b;j>=0;j--)
					{
						if(*(*(tab+i)+j)==szukana)
						{
							*(*(tab+i)+j)=0;
						}
						else break;
					}
					for(int j=b+1;j<*(dlugosc_wierszy+i);j++)
					{
						if(*(*(tab+i)+j)==szukana)
						{
							*(*(tab+i)+j)=0;
						}
						else break;
					}
				}
				else break;
			}
			
			for (int i=0;i<n;i++) // kod dla kolejnych lini
			{
				int ile_zer=0;
				for(int j=0;j<*(dlugosc_wierszy+i);j++)
				{
					if(*(*(tab+i)+j) == 0 )	ile_zer++; // ilosc zer w danej lini
				}
				if(ile_zer==*(dlugosc_wierszy+i) ) 
				{
					free(*(tab+i));
					for(int j=i;j< n-1;j++)
					{ 
						*(tab+j)=*(tab+j+1);	
						*(dlugosc_wierszy+j)=*(dlugosc_wierszy+j+1);
					}
					n--; // zmmniejszam n bo usuwam jeden wiersz
					dlugosc_wierszy=(int*)realloc(dlugosc_wierszy,sizeof (int*) *n);
					tab=(int **)realloc(tab,sizeof(int*)*n);
					i--; // zmniejszam tu indeks aby jeszcze raz sprawdzic czy nastepny 
						 // wiersz nie jest pusty 
				}
				if (ile_zer<*(dlugosc_wierszy+i))
				{
					int pierwsze_zero=0;
					for(int j=0;j<*(dlugosc_wierszy+i);j++)
					{
						if(*(*(tab+i)+j)!=0) pierwsze_zero++; // przed pierwszym zerem w tab
						else break;
					}
					for(int j=pierwsze_zero; j<*(dlugosc_wierszy+i);j++)
					{
						*(*(tab+i)+j) = *(*(tab+i)+ile_zer+j);
					}

					*(tab+i)=(int*)realloc(*(tab+i),sizeof(int*)**(dlugosc_wierszy+i)-ile_zer);
					*(dlugosc_wierszy+i)-=ile_zer;
				}
			}
			
		}
	}while(t != 'K');
	
	return 0;
}
