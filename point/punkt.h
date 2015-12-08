#ifndef Punkt_h
#define Punkt_h
#include <iostream>

class Punkt{
public:
  int x,y;
  Punkt();
  Punkt(double, double);

  friend Punkt operator+(const Punkt&,const Punkt&);
  friend Punkt operator-(const Punkt&,const Punkt&);
  friend bool operator==(const Punkt&,const Punkt&);
  friend bool operator!=(const Punkt&,const Punkt&);


  friend bool operator<(const Punkt&,const Punkt&);
  friend bool operator>(const Punkt&,const Punkt&);
  friend bool operator<=(const Punkt&,const Punkt&);
  friend bool operator>=(const Punkt&,const Punkt&);
  friend std::ostream& operator<<(std::ostream&,Punkt const&);


};
#endif // Polynomial_h

