#include <iostream>
#include "source.cpp"
#include <windows.h>
using namespace std;
int main()
{
  Konkurs konkurs;

  Piekarz a, b, c, d, e, f, g, h, i, j, k;

cout<<sizeof(short)<<endl;
 konkurs.dolacz(&a, NULL);
  konkurs.dolacz(&b, &a);
  konkurs.dolacz(&c, &a);
  konkurs.dolacz(&d, &c);
  konkurs.dolacz(&e, &b);
  konkurs.dolacz(&f, &b);
  konkurs.dolacz(&g, &b);
  konkurs.dolacz(&h, &b);
  konkurs.dolacz(&i, &e);
  konkurs.dolacz(&j, &e);
  konkurs.dolacz(&k, &e);

  konkurs.wyklucz(&c);

  std::cout << "\n";
  konkurs.wypisz(&a);
  //konkurs.wypisz();

}
