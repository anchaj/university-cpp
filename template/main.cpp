#include <iostream>
using namespace std;
/*
2. Zaimplementowaæ szablon klasy której:
a) jeden obiekt zawiera w sobie trzy ró¿ne obiekty dowolnego typu
b) zawiera nazwê dowolnej d³ugoœci
c) ma operatory <<, >>, =
d) posiada funkcjê sortuj¹ca sort()*/

class B{
};
class C{
};
class D{
};
template <class T>
class A{
public:
   string name;
   B b;
   C c;
   D d;
   A(string Name) :name(Name)
   {
   }
   A(const A &a) {
      this.name = a.name;
   }

   template <class X>
   void operator=(A <X> &a) { /// tu dzieki szablonowi mozesz przypisac
      this->name = a.name;    /// klasy z roznymi parametrami np A <int> i A <double>
   }
   /* tutaj normalna funkcja wtedy bd mozna przypisywac tylko obiekty takich samych klas
      do siebie np A <int> z A <int>
   void operator=(A &a) {
      this->name = a.name;
   }*/

   template <class TEMP>
   friend ostream& operator<<(ostream &wypisz, A <TEMP> &a);

   template <class TEMP>
   friend istream& operator<<(istream &wczytaj, A <TEMP> &a);

};
template <class T>
ostream& operator<<(ostream &wypisz, A <T> &a){
   wypisz<<a.name;
   return wypisz;
}

template <class T>
istream& operator>>(istream &wczytaj, A <T> &a){
   wczytaj>>a.name;
   return wczytaj;
}

int main() {
   A <double> a("a");
   A <int> aa("aa");

   a = aa;
   cin>>a;
   cout<<a<<" "<<aa;
   return 0;
}
