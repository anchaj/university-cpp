//Mateusz Jachna
#include <iostream>
#include <cstdio>


using namespace std;
int w=0,a,b,c,d;
int s(int a,int b,int c,int d){
	if(a==b&&a==c&&a==d)w=4;
	else if((a==b&&a==c)||(a==b&&a==d)||(a==c&&a==d)||(b==c&&b==d))w=3;
	else if(a==b||a==c||a==d||b==c||b==d||c==d){
		w=1;
		if(a==b&&c==d)w=2;
		if(a==c&&b==d)w=2;
		if(a==d&&b==c)w=2;
		}
}
int main(){
	scanf("%i%i%i%i",&a,&b,&c,&d);
	printf("a=%i, b=%i, c=%i, d=%i\n",a,b,c,d);
	s(a,b,c,d);
	switch(w)
	{
		case 0:
			{
				puts("Brak powtorzen");
				if(a>32&&a<127&&b>32&&b<127&&c>32&&c<127&&d>32&&d<127)cout<<(char)a<<endl<<(char)b<<endl<<(char)c<<endl<<(char)d<<endl;
				else puts("Brak");
				break;
			}
		case 1:
			{
				cout<<a;
				if(a==b)cout<<","<<c<<","<<d<<endl;
				else if(a==c)cout<<","<<b<<","<<d<<endl;
				else if(a==d)cout<<","<<b<<","<<c<<endl;
				else if(b==c)cout<<","<<b<<","<<d<<endl;
				else if(b==d)cout<<","<<b<<","<<c<<endl;
				else if(c==d) cout<<","<<b<<","<<c<<endl;
				break;	
			}
		case 2:
			{
				cout<<"Sa dwie pary\n";
				if(a==b)cout<<"a+b="<<a+b<<", "<<"c+d="<<c+d<<endl;				
				if(a==c)cout<<"a+c="<<a+c<<", "<<"b+d="<<b+d<<endl;	
				if(a==d)cout<<"a+d="<<a+d<<", "<<"b+c="<<b+c<<endl;
				break;
			}
		case 3:
			{
				cout<<"Jest trojka\n";
				int n=a;
				if(b<n)n=b;
				if(c<n)n=c;
				if(d<n)n=d;
				cout<<"Mniejsza wynosi:"<<n;
				break;
			}
		case 4:
			{
				cout<<"Jest czworka\n";
			}
	}
}
