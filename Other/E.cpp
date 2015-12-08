#include <iostream> 
#include "prog.cpp" 
#define MAX_SIZE 255 
 
int main() 
{ 
 char s[MAX_SIZE + 1]; 
 std::cin.getline(s, MAX_SIZE); 
 char auxiliary[2]; 
 std::cin.getline(auxiliary, 2); 
 char c = auxiliary[0]; 
 char base[MAX_SIZE + 1]; 
 std::cin.getline(base, MAX_SIZE); 
 
 std::cout << std::boolalpha 
 << isPalindrome(s) << std::endl 
 << isTautogram(s) << std::endl 
 << isLipogram(s, c) << std::endl 
 << isAnagram(s, base) << std::endl 
 << isPangram(s, true) << std::endl 
 << isPangram(s, false) << std::endl; 
 return 0; 
} 
