//M J
#include <cstdio>
void s(float &z){z=z>=90?5:z>=80?4.5:z>=70?4:z>=60?3.5:z>=50?3:2;}main(){float a,b,c,d,i;scanf("%f",&i);while(i--){scanf("%f%f%f%f",&a,&b,&c,&d);d=((b+c)*3+d*4)/10;s(d);s(b);s(c);if(d>2)if(b<3)b=3;if(c<3)c=3;printf("%i %i %i %i\n",a,b,c,d);}}
