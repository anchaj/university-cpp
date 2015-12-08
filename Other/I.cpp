//Lukasz Maziarka
#include <stdio.h>
#include <stdlib.h>
 
struct kodowanie
{
        char ciag[3];
        int liczba_wystapien;
        char znak_kodowany;
};
//************
void sortowanie_klucz( int tab[], char tab_char[], int left, int right )
{
    int i = left;
    int j = right;
    int x = tab[( left + right ) / 2 ];
    do
    {
        while( tab[ i ] < x )
             i++;
       
        while( tab[ j ] > x )
             j--;
       
        if( i <= j )
        {
                int tmp_int = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp_int;
                char tmp_char = tab_char[i];
                tab_char[i] = tab_char[j];
                tab_char[j] = tmp_char;
            i++;
            j--;
        }
    } while( i <= j );
   
    if( left < j ) sortowanie_klucz( tab, tab_char, left, j );
   
    if( right > i ) sortowanie_klucz( tab, tab_char, i, right );
   
}
//************
void sortowanie_plik( kodowanie tab[], int left, int right )
{
    int i = left;
    int j = right;
    int x = tab[( left + right ) / 2 ].liczba_wystapien;
    do
    {
        while( tab[ i ].liczba_wystapien < x )
             i++;
       
        while( tab[ j ].liczba_wystapien > x )
             j--;
       
        if( i <= j )
        {
                kodowanie tmp_kod = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp_kod;
            i++;
            j--;
        }
    } while( i <= j );
   
    if( left < j ) sortowanie_plik( tab, left, j );
   
    if( right > i ) sortowanie_plik( tab, i, right );
   
}
//************
void sortowanie_koncowe( kodowanie tab[], int left, int right )
{
        int i = left;
    int j = right;
    int x = 100*((int)tab[( left + right ) / 2 ].ciag[0]-48) + 10*((int)tab[( left + right ) / 2 ].ciag[1]-48)
                        + ((int)tab[( left + right ) / 2 ].ciag[2]-48);
    do
    {
        while( 100*((int)tab[ i ].ciag[0]-48) + 10*((int)tab[ i ].ciag[1]-48) + ((int)tab[ i ].ciag[2]-48) < x )
             i++;
       
        while( 100*((int)tab[ j ].ciag[0]-48) + 10*((int)tab[ j ].ciag[1]-48) + ((int)tab[ j ].ciag[2]-48) > x )
             j--;
       
        if( i <= j )
        {
                kodowanie tmp_kod = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp_kod;
            i++;
            j--;
        }
    } while( i <= j );
   
    if( left < j ) sortowanie_koncowe( tab, left, j );
   
    if( right > i ) sortowanie_koncowe( tab, i, right );
   
}
//************
int main()
{
        FILE *fp_klucz, *fp_plik, *fp_zapis;
        char ch_klucz[1024], ch_plik[1024], ch_zapis[1024];
        char czwarty;
       
        scanf("%s %s %s %c", ch_klucz, ch_plik, ch_zapis, &czwarty);
       
        fp_klucz = fopen(ch_klucz, "r");
        if (fp_klucz == NULL) {fputs ("File error", stderr); exit (1);}
       
        fp_plik = fopen(ch_plik, "r");
        if (fp_plik == NULL) {fputs ("File error", stderr); exit (1);}
       
        fp_zapis = fopen(ch_zapis, "w");
        if (fp_zapis == NULL) {fputs ("File error", stderr); exit (1);}
       
        int dlugosc_klucz, dl_mniejszych_klucz = 0;
        fseek (fp_klucz , 0 , SEEK_END);
        dlugosc_klucz = ftell ( fp_klucz);
        rewind (fp_klucz);
       
        char *tab_char_klucz = (char*)malloc(dl_mniejszych_klucz);
        int *tab_int_klucz = (int*)malloc(dl_mniejszych_klucz);
        char c;
        bool nowy;
       
        while(c != EOF)
        {
                int i = 0;
                nowy = true;
                c = fgetc(fp_klucz);
                while(i < dl_mniejszych_klucz && nowy == true)
                {
                        if(tab_char_klucz[i] == c)
                        {
                                nowy = false;
                                (tab_int_klucz[i])++;
                        }
                        i++;
                }
                if(nowy == true && !feof(fp_klucz))
                {
                        dl_mniejszych_klucz++;
                        tab_char_klucz = (char*)realloc(tab_char_klucz, dl_mniejszych_klucz * sizeof(char));
                        tab_int_klucz = (int*)realloc(tab_int_klucz, dl_mniejszych_klucz * sizeof(int));
                        tab_char_klucz[dl_mniejszych_klucz-1] = c;
                        tab_int_klucz[dl_mniejszych_klucz-1] = 1;
                }
    }
    fclose(fp_klucz);
   
       
        int dlugosc_plik, dl_mniejszych_plik = 0;
        fseek (fp_plik , 0 , SEEK_END);
        dlugosc_plik = ftell ( fp_plik);
        rewind (fp_plik);
        dlugosc_plik = dlugosc_plik/3;
       
        kodowanie *tab_kod_plik = (kodowanie*)malloc(dl_mniejszych_plik);
       
        int j = 0;
        char d, tab_tmp[3];
        while(d != EOF)
        {
                int i = 0;
                nowy = true;
                d = fgetc(fp_plik);
                tab_tmp[j] = d;
                if(j == 2)
                {      
                        while(i < dl_mniejszych_plik && nowy == true)
                        {
                                if(tab_tmp[0] == tab_kod_plik[i].ciag[0] &&
                                   tab_tmp[1] == tab_kod_plik[i].ciag[1] &&
                                   tab_tmp[2] == tab_kod_plik[i].ciag[2])
                                {
                                        nowy = false;
                                        (tab_kod_plik[i].liczba_wystapien)++;
                                }
                                i++;
                        }
                        if(nowy == true && !feof(fp_plik))
                        {
                                dl_mniejszych_plik++;
                                tab_kod_plik = (kodowanie*)realloc(tab_kod_plik, dl_mniejszych_plik * sizeof(kodowanie));
                                tab_kod_plik[dl_mniejszych_plik-1].ciag[0] = tab_tmp[0];
                                tab_kod_plik[dl_mniejszych_plik-1].ciag[1] = tab_tmp[1];
                                tab_kod_plik[dl_mniejszych_plik-1].ciag[2] = tab_tmp[2];
                                tab_kod_plik[dl_mniejszych_plik-1].liczba_wystapien = 1;
                        }
                        j = 0;
                }
                else
                        j++;
        }
       
       
        sortowanie_klucz(tab_int_klucz, tab_char_klucz, 0, dl_mniejszych_klucz-1);
       
        for(int i=dl_mniejszych_klucz-1; i>=0; i--)
        {
                printf("Znaleziono %8d znakow %c, co stanowi %6.3f%% wszystkich.\n",
                                tab_int_klucz[i], tab_char_klucz[i], 100.0*tab_int_klucz[i]/dlugosc_klucz);
        }
       
        sortowanie_plik(tab_kod_plik, 0, dl_mniejszych_plik-1);
       
        for(int i=dl_mniejszych_plik-1; i>=0; i--)
        {
                printf("Znaleziono %8d ciagow %c%c%c, co stanowi %6.3f%% wszystkich.\n",
                                tab_kod_plik[i].liczba_wystapien, tab_kod_plik[i].ciag[0], tab_kod_plik[i].ciag[1], tab_kod_plik[i].ciag[2],
                                100.0*tab_kod_plik[i].liczba_wystapien/dlugosc_plik);
        }
       
        for(int i=0; i<dl_mniejszych_klucz; i++)
                tab_kod_plik[i].znak_kodowany = tab_char_klucz[i];
 
        rewind (fp_plik);
        char e;
        j = 0;
        bool znalezione;
        while(e != EOF)
        {
                int i = 0;
                znalezione = false;
                e = fgetc(fp_plik);
                tab_tmp[j] = e;
                if(j == 2)
                {
                        while(znalezione == false)
                        {
                                if(tab_tmp[0] == tab_kod_plik[i].ciag[0] &&
                                   tab_tmp[1] == tab_kod_plik[i].ciag[1] &&
                                   tab_tmp[2] == tab_kod_plik[i].ciag[2])
                                {
                                        fputc(tab_kod_plik[i].znak_kodowany, fp_zapis);
                                        znalezione = true;
                                }
                                i++;
                        }
                        j = 0;
                }
                else
                        j++;
        }
        fclose(fp_zapis);
        fclose(fp_plik);
       
        int ile_czwartych;
        j=0;
        znalezione = false;
        while(znalezione == false)
        {
                if(tab_kod_plik[j].znak_kodowany == czwarty)
                {
                        ile_czwartych = tab_kod_plik[j].liczba_wystapien;
                        znalezione=true;
                }
                j++;
        }
       
        sortowanie_koncowe(tab_kod_plik, 0, dl_mniejszych_plik-1);
       
        for(int i=0; i<dl_mniejszych_plik; i++)
        {
                printf("Symbol %c%c%c koduje %c\n", tab_kod_plik[i].ciag[0], tab_kod_plik[i].ciag[1],
                                                                                  tab_kod_plik[i].ciag[2], tab_kod_plik[i].znak_kodowany);
        }
       
        fp_zapis = fopen(ch_zapis, "r");
        if (fp_zapis == NULL) {fputs ("File error", stderr); exit (1);}
       
        char g;
        int tmp_czw = 0;
        bool napisalo = false;
        while(g != EOF && napisalo == false)
        {
                g = getc(fp_zapis);
                if(g == czwarty) tmp_czw++;
                if(tmp_czw == ile_czwartych-1)
                {
                        char tab_wypisz[50];
                        if(fgets(tab_wypisz, 50, fp_zapis) != NULL)
                                printf("%c%s", czwarty, tab_wypisz);
                }
        }
        fclose(fp_zapis);
       
        free(tab_char_klucz);
        free(tab_int_klucz);
        
        free(tab_kod_plik);
}
