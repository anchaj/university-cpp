#include <iostream>
#include <stdlib.h>
#include "MojVector.h"
using namespace std;
int main()
{

try{
Vector a;
cout<<a;

}
catch (const Vector::InvalidSize &e){
   cout << e.what();
}
catch (const Vector::IncompatibleDimensions & e){
   cout << e.what();
}
return 0;
}
