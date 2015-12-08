#include <iostream>
#include <stdio.h>
using namespace std;
int main ()
{
int a;
double b;
char ciag[4];

scanf("%s",ciag);
scanf("%i",&a);
scanf("%ld", &b);

  printf ("liczba ca³kowita to %d, \n",a);  
  printf ("slowo to %s \n", ciag );
  printf ("natomiast liczba zmiennoprzecinkowa to %lf",b);
  
  return 0;
}
