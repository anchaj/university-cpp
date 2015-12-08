#include <vector>
#include <list>
#include <map>
#include <iostream>

using namespace std;

template <class IT,class IT2>
bool mniejsze(IT l,IT2 p) {
   if(l<p) return true;
   return false;
}


template <class IT1,class IT2>
bool wspolnyEl(IT1 p1,IT1 k1, IT2 p2, IT2 k2){
   IT1 tmp1 = p1;
   IT2 tmp2 = p2;
   while(mniejsze(tmp1,k1)){
      tmp2 = p2;
      while(mniejsze(tmp2,k2)){
         if(*tmp2==*tmp1) return true;
         tmp2++;
      }
      tmp1++;
   }
   return false;
}

template <class IT1,class IT2>
bool wspolnyEl2(IT1 p1,IT1 k1, IT2 p2, IT2 k2){
   IT1 tmp1 = p1;
   IT2 tmp2 = p2;

   while(mniejsze(p1,k1) && mniejsze(p2,k2)){
      if(mniejsze(*p1,*p2)){
         p1++;
      }
      else if(mniejsze(*p2,*p1)) {
         p2++;
      }
      else return true;
   }
   return false;
}

template <class IT>
class Iterator {
   int adr;
   Iterator(){
   }

};

template <class T>
class Tablica2D {
   T **tab;
   int X,Y;
   Iterator <T> begin(), end();
public:
   Tablica2D(int a=0,int b=0):X(a),Y(b) {
      if(a!=0 && b!=0) {
         tab = new T*[a];
         for(int i=0;i<a;i++){
            tab[i] = new T[b];
         }
      }
   }
   T& operator()(int x,int y) {
      return tab[x][y];
   }
   void uzupelnij(){
      for(int i=0;i<X;i++)
         for(int j=0;j<Y;j++){
           tab[i][j] = (((1+i)*i - j*j) - (i-3)*(i*j));
         }
   }

   void wypisz() {
      for(int i=0;i<X;i++){
         for(int j=0;j<Y;j++){
            cout<<tab[i][j]<<" ";
         }
         cout<<endl;
      }
      cout<<endl;
   }
};

int main() {

   vector <int> v1 = {1,2,123,213,214,240,1024,2048};
   vector <int> v2 = {10,128,200,213,2048};
   cout<< wspolnyEl2(v1.begin(),v1.end(),v2.begin(),v2.end())<<endl;
   Tablica2D <int> t1(10,4);
   t1.uzupelnij();
   t1.wypisz();

   t1(1,1) = 0;
   t1.wypisz();

   return 0;
}
