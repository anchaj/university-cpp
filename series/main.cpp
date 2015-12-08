#include <stdio.h>
#include <math.h>

using namespace std;
double sil(int n) {
   double wynik = 1;
   if(n==0 || n==1) return 1;
   for(int i=2;i<=n;i++) {
      wynik *= i;
   }
   return wynik;
}
int main()
{
    const double PI = 3.14159265358979323846;
    double x,eps = 0.00000002;
    printf("Program liczy wartosci funkcji tryg w radianach x*pi\nPodaj x: ");
    scanf("%lf",&x);
    x *= PI;
    const double X = x;

    /// sin x
    int n=1;
    double wynik=X, pwynik=0;
    while(wynik!=pwynik){
      pwynik = wynik;
      if(n%2==0){
            wynik += (pow(x, (2*n + 1)) / sil(2*n + 1) );
            if(wynik-pwynik<eps) break;
      }
      else {
         wynik -= (pow(x, (2*n + 1)) / sil(2*n + 1));
          if(pwynik-wynik<eps) break;
      }
      n++;
    }
    printf("sin x = %lf\n",wynik);


    /// cos x
    wynik=1, pwynik=0, n=1;
    while(wynik!=pwynik){
      pwynik = wynik;
      if(n%2==0){
            wynik += (pow(x, (2*n)) / sil(2*n) );
            if(wynik-pwynik<eps) break;
      }
      else {
         wynik -= (pow(x, (2*n)) / sil(2*n));
         if(pwynik-wynik<eps) break;
      }
      n++;
    }
    printf("cos x = %lf\n",wynik);


    /// sinh x
    wynik=X, pwynik=0, n=1;
    while(wynik!=pwynik){
      pwynik = wynik;
      wynik += (pow(x, (2*n + 1)) / sil(2*n + 1) );
      if(wynik-pwynik<eps) break;
      n++;
    }
    printf("sinh x = %lf\n",wynik);

    /// arctg x
    if(x>-1 && x<1) {
       wynik=X, pwynik=0, n=1;
       while(wynik!=pwynik){
         pwynik = wynik;
         if(n%2==0){
               wynik += (pow(x, (2*n + 1)) / (2*n + 1) );
               if(wynik-pwynik<eps) break;
         }
         else {
            wynik -= (pow(x, (2*n + 1)) / (2*n + 1));
             if(pwynik-wynik<eps) break;
         }
         n++;
       }
       printf("arctg x = %lf\n",wynik);
    }
    /// ln(x+1) x
    if(x>-1 && x<=1) {
       wynik=X, pwynik=0, n=1;
       while(wynik!=pwynik){
         pwynik = wynik;
         if(n%2==1){
               wynik += (pow(x, n) / n);
               if(wynik-pwynik<eps) break;
         }
         else {
            wynik -= (pow(x, n) / n);
             if(pwynik-wynik<eps) break;
         }
         n++;
       }
       printf("ln(x+1) = %lf\n",wynik);
    }
    return 0;
}
