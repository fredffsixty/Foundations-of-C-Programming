#include <stdio.h>

int main(void){

    char* v[3] = {"mamma", "jack", "paperino"};

    char** la_mia_stringa = {"pippo", "pluto", "paperino", "topolino"};

    char vv[4][5] = {"sole", "jackh", "lunat", "pipppo"};

    for(int i=0;i<3;i++)
        printf("Elemento %d: %s\n", i+1, v[i]);
    
    printf("L'indirizzo del vettore v e': %lX\n", v);
    
    for(int i=0;i<4;i++)
        printf("Elemento %d: %s\n", i+1, vv[i]);
    
    printf("L'indirizzo del vettore vv e': %lX\n", vv);
    
    return 0;
}