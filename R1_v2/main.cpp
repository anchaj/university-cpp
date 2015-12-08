#include "Polynomial.h"
#include <iostream>
#include <iomanip>
using namespace std;
void wypisz( const Polynomial & w){
for(int i=0; i<=w.degree(); ++i)
cout << w[i] << " ";
cout << endl;
}
int main(){
double a[] = { 1, 2, 3, 4, 5};
Polynomial s, // Konstruktor domyslny - tworzy wielomian zerowy
p(3), // Tworzy Polynomial "stopnia" 3 i zeruje jego wspolczynniki
t(2.5), // Tworzy Polynomial stopnia 0 równy 2.5
w(2,false), // Tworzy Polynomial stopnia 2, zeruje wspolczynniki w zaleznosci od flagi (false=NIE, true=TAK)
q(4,a); // Tworzy Polynomial stopnia 4 i kopiuje wspolczynniki z tablicy a
// odpowiednio {a_4, a_3, ... a_0} (a_i wspolczynnik przy potedze i)
Polynomial r = q; // Tworzy kopie wielomianu q
int i;
cin >> i;
cin >> w[0] >> w[1] >> w[2] >> p[i] >> r[4];
cout << setiosflags(ios_base::fixed) << setprecision(1);
wypisz(s); wypisz(p); wypisz(t); wypisz(w); wypisz(q); wypisz(r);
s = w; s = s; s[2] = 3;
wypisz(s);
s = 3;
wypisz(s);
return 0;
}
