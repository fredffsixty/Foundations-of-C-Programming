#include <stdio.h>

int main(void){
    /* Test del comportamento delle stringhe con scanf */

    char str[8]="";
    char str1[8]="";

    printf("> ");
    scanf("%7s%7s",str,str1);
    printf("%s\n%s\n",str,str1);

    return 0;
}