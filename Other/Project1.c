#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	double eps,a=1,s=1;
	int x,n=1;
	printf("Podaj liczby eps,x\n");
	scanf("%lf %i",&eps,&x);	
	do {
		a = a*x/n;
		s = s+a;
		n++;
	} while(a>=eps);
	printf("e^%i = %lf\n",x,s);
	printf("przyblizona wartosc obliczono po %i ineracjach",n);
	return 0;
}
