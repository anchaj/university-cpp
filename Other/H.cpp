#include <cstdarg>
#include "source.cpp"
#include <cstdio>

bool zostawMalaLitere(char c){
  return (c<'a' or c>'z');
}

int main(){
  char s1[] = "Ala ma kota!";
  char s2[] = "Kot ma Ale?";
  char* s[] = {s1,s2};
  int d = filtruj(s,s+2,zostawMalaLitere);
  printf("%s, %s, %d\n",s[0],s[1],d);
  return 0;
}
