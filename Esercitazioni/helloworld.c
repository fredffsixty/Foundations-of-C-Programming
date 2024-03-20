#include <stdio.h>

int main(void){
    /* 
        Il programma richiede all'utente come si chiama
        acquisice la stringa e poi stampa un messaggio che contiene
        la stringa acquisita
    */
    
    char nome[30]="Precipitevolissimevolmente\n";

    printf("Come ti chiami? ");

    scanf("%s",nome);

    printf("Ciao %s!\n",nome);

    printf("Indirizzo dela stringa: %#lX\n",(unsigned long)nome);
    return 0;
}