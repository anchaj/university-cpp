//Mateusz Jachna
#ifndef Polynomial_h
#define Polynomial_h
#include <iostream>
class Polynomial{
public:
   mutable int DE;
   mutable float *TAB;
   Polynomial();
   Polynomial(int,bool=true);
   Polynomial(double);
   Polynomial(int,float*);
   Polynomial(int,double*);
   Polynomial(const Polynomial&);
   Polynomial(int,float*,char,int,float*);
   ~Polynomial();
   void clear_elements(int=0);
   int degree() const;
   float Horner(int,int=0) const;
   void reduction() const;
   float&     operator[] (int);
   float      operator[] (int) const;
   float      operator() (int) const;
   Polynomial  operator= (double);
   Polynomial& operator= (Polynomial);

   friend Polynomial operator+(const Polynomial&,const Polynomial&);
   friend Polynomial operator-(const Polynomial&,const Polynomial&);
   friend Polynomial operator*(const Polynomial&,const Polynomial&);

   friend Polynomial operator-(double,Polynomial&); // to jest uzywane przez prog 2.2
   friend Polynomial operator*(Polynomial&,double);

   friend Polynomial operator+=(Polynomial&,const Polynomial&);
   friend Polynomial operator-=(Polynomial&,const Polynomial&);
   friend Polynomial operator*=(Polynomial&,Polynomial&);

   friend const Polynomial& operator++(Polynomial&);
   friend const Polynomial operator++(Polynomial&,int);
   friend const Polynomial& operator--(Polynomial&);
   friend const Polynomial operator--(Polynomial&,int);

   friend bool operator==(const Polynomial&,const Polynomial&);
   friend bool operator!=(const Polynomial&,const Polynomial&);

   friend std::ostream& operator<<(std::ostream&,Polynomial const&);
   friend std::istream& operator>>(std::istream&,Polynomial&);
};
#endif // Polynomial_h
