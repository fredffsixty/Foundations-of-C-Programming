#include <stdio.h>

/*
    Test del comportamento delle stringhe
*/

int main(){

    char str[5]="";
    printf("> ");
    scanf("%9s",str);   // non inserisco l'operatore &
    
    printf("%s\n",str);

    return 0;
}