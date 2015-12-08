#ifndef Przedmiot_h
#define Przedmiot_h
#include <stdlib.h>
#include <string>
class Przedmiot{
public:
   Przedmiot();
   Przedmiot(std::string);
   void setName(std::string name);
   std::string getName();
   void setWeight(int load);
   int getWeight();
   void setWidth(int width);
   int getWidth();

   std::string name;
   int load,width;
};
#endif // Przedmiot_h
