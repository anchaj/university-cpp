#include <iostream>
#include <cstdlib>

using namespace std;
class Data{

   int dzien,miesiac,rok;
public:
   string tmp="               ";
   Data(int D,int M, int R)
   {
      dzien=D;
      miesiac=M;
      rok=R;
   }
   int set_data(int D,int M,int R)
   {
      if (M<=0 or M>12) return 0;
      if((M%2==1 and M<=7) or (M%2==0 and M>7))
      {
         /// dni 1-31(styczen,marzec,maj,lipiec,sierpien,pazdziernik,grudzien)
         if(D>31 or D<=0) return 0;
         dzien = D;
         miesiac = M;
         rok = R;
      }
      else if((M%2==0 and M<=7) or (M%2==1 and M>7 ))
      {
         /// dni 1-30(luty, kwiecien, czerwiec,wrzesien,listopad)

         if(M==2)
         {///dla lutego
            if((R%4 == 0) and (R&100 != 0) or R%400 == 0)
            {/// rok przestepny -- luty 29 dni
               if(D>29 or D<=0) return 0;
               dzien = D;
               miesiac = M;
               rok = R;
            }
            else
            {
               if(D>28 or D<=0) return 0;
               dzien = D;
               miesiac = M;
               rok = R;
            }
         }
         else{
            if(D>30 or D<=0) return 0;
               dzien = D;
               miesiac = M;
               rok = R;
         }
      }
   }
   int get_dzien()
   {
      return dzien;
   }
   int get_miesiac()
   {
      return miesiac;
   }
   int get_rok()
   {
      return rok;
   }
   string toString()
   {
      if(dzien>10)
      {
         tmp[0] = (char) (dzien/10) + 48;
         tmp[1] = (char) (dzien%10) + 48;
      }
      else tmp[1]=(char) dzien + 48;

      if(miesiac>10)
      {
         tmp[3] = (char) (miesiac/10) + 48;
         tmp[4] = (char) (miesiac%10) + 48;
      }
      else tmp[4]=(char) miesiac + 48;

      return tmp;
   }
};

int main()
{
   Data pierwsza(12,1,2001);
   //cout<<pierwsza.dzien<<" "<<pierwsza.miesiac<<" "<<pierwsza.rok<<endl;
   cout<<pierwsza.toString();

}
