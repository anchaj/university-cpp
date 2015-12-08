//Mateusz Jachna
#ifndef Polynomial_h
#define Polynomial_h
using std::istream;
using std::ostream;
class Polynomial
{
public:
   int Degree;
   double *Elements;
   Polynomial operator=(Polynomial*);
   Polynomial operator=(double);

   Polynomial();
   Polynomial(int,bool=true);
   Polynomial(double);
   Polynomial(int,double*);
   Polynomial(Polynomial&);
   ~Polynomial();

   void clear_elements();
   int degree() const;
   double Horner(int,int=0) const;
   void reduction();

   double&     operator[] (int);
   double      operator[] (int) const;
   double      operator() (int) const;
   //Polynomial  operator=  (double);

   friend Polynomial operator+(const Polynomial&,const Polynomial&);
   friend Polynomial operator-(const Polynomial&,const Polynomial&);
   friend Polynomial operator*(const Polynomial&,const Polynomial&);

   friend Polynomial operator+(Polynomial&,double);
   friend Polynomial operator-(Polynomial&,double);
   friend Polynomial operator-(double,Polynomial&);
   friend Polynomial operator*(Polynomial&,double);

   friend Polynomial operator+=(Polynomial&,const Polynomial&);
   friend Polynomial operator-=(Polynomial&,const Polynomial&);
   friend Polynomial operator*=(Polynomial&,const Polynomial&);

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
