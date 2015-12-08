#include <iostream>

using namespace std;
template<class T>
class lista;

template<class T>
class element {
   public:
		T wartosc;
		element<T> * wskobj;

	friend class lista<T>;


	element() {

		wskobj=NULL;
		wartosc=0;
	}

	element(T elementlisty) {

		wartosc=elementlisty;
		wskobj=NULL;

	}

	element(element & wzor){
      wartosc = wzor.wartosc;
      if(wskobj == NULL) wskobj = new element();
		wskobj=wzor.wskobj;
	}

	~element() {
		delete wskobj;
	}
};


template<class T>
class lista{
   public:

		friend class element<T>;

      template <T> friend istream & operator>>(istream & wynik, lista<T> &);
      template <T> friend ostream & operator<<(ostream & wynik, lista<T> &);

		element<T> * pierwszy;
		element<T> * ostatni;

		lista() {
         pierwszy=ostatni=NULL;
      }
      ~lista(){
         pierwszy= NULL;
         ostatni= NULL;
      }
      void sortuj(){
         element<T> *i = pierwszy;
         while (i!=NULL) {
            element<T> *j = pierwszy;
            while(j->wskobj!=NULL){
               if(j->wartosc<i->wartosc) {
                  swap(j->wartosc,i->wartosc);
               }
               j = j->wskobj;
               }
            i = i->wskobj;
         }
      }
      lista & operator+(lista<T> & nowy) {

		static lista<T> suma;
		suma.~lista();

		element<T> * zmienna1;
		element<T> * zmienna2;

		zmienna1=pierwszy;
		suma.pierwszy=pierwszy; //suma.pierwszy to wskaznik na poczatek nowej listy. Rowniez jest obiektem do ktorego zapisujemy sume obu list

		if(!suma.pierwszy) { //jest pusty

			suma.ostatni=0;
		}
		while(zmienna1!=0) { //zapelniamy sume na rzecz ktorego uruchomimy operator

			if(zmienna1==pierwszy) {

				suma.pierwszy = new element<T>;
				suma.ostatni=suma.pierwszy;
				suma.pierwszy->wartosc=zmienna1->wartosc;
				zmienna1=pierwszy->wskobj;
			}
			else {

				zmienna2 = new element<T>;
				suma.ostatni->wskobj=zmienna2;
				suma.ostatni=zmienna2;
				zmienna2->wartosc=zmienna1->wartosc;
				zmienna1=zmienna1->wskobj;
			}
		}

	zmienna1=nowy.pierwszy; //dodajemy do listy elementy z obiektu nowy
		while(zmienna1!=0) {

			zmienna2 = new element<T>;
			suma.ostatni->wskobj=zmienna2;
			suma.ostatni=zmienna2;
			zmienna2->wartosc=zmienna1->wartosc;
			zmienna1=zmienna1->wskobj;

		}

	return suma;

	}
};
template <class T>
istream & operator>>(istream & wynik, lista<T> & nowy) {
         int liczba;
         cout<< "Podaj ilosc elementow listy ";
         wynik >> liczba;
         cout<< "Podaj kolejne wsp: ";
         for (int i=0;i<liczba;++i){
               if(!nowy.pierwszy) {
                  nowy.pierwszy = new element<T>;
                  nowy.ostatni = nowy.pierwszy;

                  wynik >> nowy.pierwszy->wartosc;
               }
               else {
                  element <T> * tmp = new element<T>;
                  nowy.ostatni->wskobj = tmp;
                  nowy.ostatni = tmp;
                  wynik >> nowy.ostatni->wartosc;
               }
         }
         return wynik;
}
template <class T>
ostream & operator<<(ostream & wynik, lista<T> & nowy) {

	element<T> * zmienna;

	zmienna=nowy.pierwszy;

	while(zmienna!=0) {

		wynik << zmienna->wartosc << endl;
		zmienna=zmienna->wskobj;
	}
	return wynik;
}
int main() {

	lista<int> a, b, c;
	element<int> B;
	cin >> a;
	cout << a <<endl;
	a.sortuj();
	cout<<a;
	return 0;

}
