#include <new>
#include <iostream>
using namespace std;
int main()
{
   while(true)
   {
      try{
         int *tab = new int[100];
      }
      catch (std::bad_alloc& ba)
      {
         cout<<"Brak pamieci\n";
         break;
      }
    }
   return 0;
}
