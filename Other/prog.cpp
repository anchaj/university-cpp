//Mateusz Jachna
bool static isAlpha(char c){
	if(((int)c>64&&(int)c<91)||((int)c>96&&(int)c<123)) return 1;
return 0;
}
bool static isPalindrome(char *s){
	int ostatni=0;
	bool w=0;
	while(s[ostatni]!=0)ostatni++;
	const int koniec_tab = --ostatni;
	int pierwszy=0;
	while(pierwszy<=koniec_tab&&ostatni>=0)
	{
		bool alfa=1;
		if(!isAlpha(s[pierwszy]))
		{
			pierwszy++;
			alfa=0;
		}
		if(!isAlpha(s[ostatni])){
			ostatni--;
			alfa=0;
		}
		if(alfa==1){
			if(s[ostatni]!=s[pierwszy]){
				return 0;
			}
			ostatni--;pierwszy++;
			w=1;
		}
	}
	return w;
}
bool static isTautogram(char *s){
	char pierwsze_slowo;
	int ostatni=0,ile=0,i;
	while(s[ostatni]!=0)ostatni++;
	bool w=0;
	for(i=0;i<ostatni;i++){
		if(isAlpha(s[i])||((int)s[i]>47&&(int)s[i]<58)){
			pierwsze_slowo=s[i];
			ile++;
			break;
			}
	}
	for(int j=i;j<ostatni;j++){
		if((int)s[j]==32){
			while(j<ostatni){
				if(s[j+1]==pierwsze_slowo){
					w=1;
					ile++;
					break;
				}
				else if(s[j+1]!=pierwsze_slowo&&(isAlpha(s[j+1])||((int)s[i]>47&&(int)s[i]<58))) {
					return 0;
				}
				j++;
			}
		}	
	}
	return w;
}
bool static isLipogram(char *s, char c){
	int ostatni=0;
	bool w=0;
	while(s[ostatni]!=0)
	{
		if(isAlpha(s[ostatni])){
			w=1;
		}
		if(s[ostatni]==c){
			return 0;
		}
		ostatni++;
	}
	return w;
}
bool static isAnagram(char *s, char *base)
{
int tab1 [123]={0};
int tab2 [123]={0};
int a=0;
bool linia_pusta=0;
	while(s[a]!=0)
		{
			tab1[(int)s[a]]++;
		}
			a=0;

	while(base[a]!=0)
	 		{
	 			tab2[base[a]]++;
	 		}
	 		
	for(int i= 65; i<91; i++)
	{
	if(tab1[i]!=tab2[i])
	return false;
	if(tab1[i]!=0) 
	linia_pusta=1;
	}
	for(int i=97; i<123; i++)
	{
		if(tab1[i]!=tab2[i])
		return false;
		if(tab1[i]!=0) 
		linia_pusta=1;
	}
return linia_pusta;

}
bool static isPangram(char *s, bool wartosc){
	int ostatni=0;
	int tab[26]={0};
	bool w=0;
	while(s[ostatni]!=0)
	{
		if((int)s[ostatni]>64&&(int)s[ostatni]<91){
			tab[(int)s[ostatni]-65]++;
			w=1;
		}
		if((int)s[ostatni]>96&&(int)s[ostatni]<123){
			tab[(int)s[ostatni]-97]++;
			w=1;
		}
		ostatni++;
	}
	if(wartosc){
		for(int i=0;i<26;i++){
			if(tab[i]!=1) return 0;
		}
	}
	else{
		for(int i=0;i<26;i++){
			if(!tab[i]>0) return 0;
		}
	}
	return w;
}
