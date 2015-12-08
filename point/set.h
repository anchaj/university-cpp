#ifndef Set_h
#define Set_h
#include <iostream>
class Set
{
public:

  char *tab;
  int dlugosc;
  mutable bool litery[26];
  void zlicz() const;
  void wypisz();

  Set();                              /// Zbior pusty liter
  Set(int);
  Set(const char napis[]);            /// konstruktor konwertujacy
  Set& operator*=(const Set&);        /// przeciecie mnogosciowe
  Set& operator+=(const Set&);        /// suma mnogosciowa
  Set& operator-=(const Set&);        /// roznica mnogosciowa
  Set& operator=(char);               /// operator przypisania
  Set& operator=(const char napis[]); /// operator przypisania
  bool operator[](char) const;        /// sprawdza, czy litera wystepuje w zbiorze

  /// globalne operacje mnogosciowe
  friend Set operator*(const Set& A, const Set& B);
  friend Set operator+(const Set& A, const Set& B);
  friend Set operator-(const Set& A, const Set& B);
};

#endif // Set_h
