//Izabela Krupa
#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <stdexcept>

using namespace std;
class Vector{
   int dimension;
   double *tab;
public:
   class IncompatibleDimensions : public logic_error{
   public:
      IncompatibleDimensions(const string wiad = ""):logic_error(wiad){
      }
      const char* what() const throw()
      {
         return "Incompatible dimensions!";
      }
   };
   class InvalidSize : public runtime_error{
      public:
      InvalidSize(const string wiad = ""):runtime_error(wiad){
      }
      const char* what() const throw()
      {
         return "Invectoralid size in Vector!";
      }
   };
   Vector(int wym=1)
   {
      if(wym<0){
           throw InvalidSize();
      }
      dimension = wym;
      this->tab = new double[wym];
      for(int i=0;i<getSize();i++)
      {
         this->tab[i]=0;
      }
   }
   Vector(int wym, double *tab)
   {
      if(wym<0){
           throw InvalidSize();
      }
      dimension = wym;
      this->tab = new double[wym];
      for(int i=0;i<wym;i++)
      {
         this->tab[i]=tab[i];
      }
   }
   Vector(int wym, int *tab)
   {
      if(wym<0){
           throw InvalidSize();
      }
      dimension = wym;
      this->tab = new double[wym];
      for(int i=0;i<wym;i++)
      {
         this->tab[i]=tab[i];
      }
   }
   Vector(const Vector &vector)
   {
      if(vector.dimension<0){
           throw InvalidSize();
      }
      this->tab = new double [vector.getSize()];
      dimension = vector.getSize();
      for(int i=0;i<dimension;i++)
      {
         this->tab[i] = vector.tab[i];
      }
   }
   ~Vector()
   {
      if(dimension!=0)
      {
         delete[] this->tab;
         dimension = 0;
      }
   }
   Vector operator=(const Vector v)
   {
      delete[] tab;
      tab = new double[v.dimension];
      dimension = v.dimension;
      for(int i=0;i<dimension;i++)
      {
         this->tab[i] = v.tab[i];
      }
      return *this;
   }
   friend std::ostream& operator<<(std::ostream&,Vector const&);

   void clear ();
   int getSize() const;
   double& operator[](int index) const;
   friend const Vector operator+(const Vector&, const Vector&);
   friend const Vector operator-(const Vector&, const Vector&);
   friend const Vector operator-(Vector);
   friend const double operator*(const Vector&, const Vector&);
   friend const Vector operator*(const double&, const Vector&);
   friend const Vector operator*(const Vector&, const double&);
};

ostream& operator<<(ostream& out,Vector const &vector){
   out <<"(";
   for(int i=0;i<vector.dimension;i++)
   {
      out<<vector.tab[i];
      if(i+1!=vector.dimension) out<<",";
   }
   out<<")";
   return out;
}
void Vector::clear (){
   for(int i=dimension-1;i>=0;i--)
      this->tab[i]=0;
}
int Vector::getSize() const
{
   return dimension;
}
double& Vector::operator[](int i) const {
   return tab[i];
}
const Vector operator+(const Vector &vector1,const Vector &vector2){
   if(vector1.dimension!=vector2.dimension) throw Vector::IncompatibleDimensions();
   double *tmp = new double[vector1.getSize()];
   for(int i=vector1.dimension-1;i>=0;i--)
      tmp[i] = vector1.tab[i]+vector2.tab[i];
   return Vector(vector1.dimension,tmp);
}
const Vector operator-(const Vector& vector1, const Vector& vector2){
   if(vector1.dimension!=vector2.dimension) throw Vector::IncompatibleDimensions();
   double *tmp = new double[vector1.dimension];
   for(int i=vector1.dimension-1;i>=0;i--)
      tmp[i]=vector1.tab[i]-vector2.tab[i];
   return Vector(vector1.dimension,tmp);
}
const Vector operator-(Vector vector1){
   for(int i=vector1.dimension-1;i>=0;i--)
      vector1.tab[i]= (-1)* vector1.tab[i];
   return vector1;
}
const double operator*(const Vector& vector1, const Vector& vector2){
   if(vector1.dimension!=vector2.dimension) throw Vector::IncompatibleDimensions();
   double tmp=0;
   for(int i=vector1.dimension-1;i>=0;i--)
      tmp += vector1.tab[i]*vector2.tab[i];
   return tmp;
}

const Vector operator*(const Vector& vector1, const double& d){
   double *tmp = new double[vector1.dimension];
   for(int i=vector1.dimension-1;i>=0;i--)
      tmp[i] = vector1.tab[i]*d;
   return Vector(vector1.dimension,tmp);
}

const Vector operator*(const double& d,const Vector& vector1){
   double *tmp = new double[vector1.dimension];
   for(int i=vector1.dimension-1;i>=0;i--)
      tmp[i] = vector1.tab[i]*d;
   return Vector(vector1.dimension,tmp);
}


#endif
