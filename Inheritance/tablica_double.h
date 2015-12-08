#ifndef __TABLICA_DOUBLE_H__
#define __TABLICA_DOUBLE_H__

class TablicaDouble{
public:
     int getSize()const;
     int getTab(int) const;
  TablicaDouble();                                // tworzy pusta tablice
  explicit TablicaDouble(unsigned );              // tworzy tablice o podanym rozmiarze
  TablicaDouble(const TablicaDouble&);            // konstruktor kopiujacy
  ~TablicaDouble();                               // destruktor zwolnieniajacy zasoby

  TablicaDouble& operator=(const TablicaDouble&); // poprawne przypisanie

  double& operator[](unsigned index);             // indeksowanie
  double operator[](unsigned index) const;        // indeksowanie stalej tablicy

  void resize(unsigned);                          // zmiana rozmiaru tablicy z zachowaniem jej zawarosci
private:
      double *tab;
      int size;
};

#endif
