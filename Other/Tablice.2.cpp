#include <iostream>
#include <cmath>

int main(int argc, char** argv) {
	int t[8][8],t_temp[8][8];
	for (int n=0;n<8;n++){
		for (int m=0;m<8;m++){
			t[n][m]= pow(n+1,m);
			t_temp[m][n]=t[n][m]; //transpozycjonowana tablica pomocnicza
		}	
	}
	
	for (int n=0;n<8;n++){
		for(int m=0;m<8;m++){
			t[n][m]=t_temp[n][m];
		}
	}	
	return 0;
}
