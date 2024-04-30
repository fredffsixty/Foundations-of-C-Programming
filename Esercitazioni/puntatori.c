#include <stdio.h>

int main(void){

    char s[6] = {'m','a','m','m','a','\0'};

    /* Richiedo la dimensione in byte di ogni singolo elemento del vettore */
    printf("Dimensione del tipo char: %d byte\n", sizeof(char));
    
    /* Stampo il contenuto del vettore*/
    printf("Contenuto della stringa: %s\n",s);
    
    /* 
        Stampo il vettore richiedendo la conversione come unsigned long in esadecimale:
        Se è vero che s contiene l'indirizzo al suo primo elemento potrò fare questa stampa 
        e ottenere un indirizzo valido
    */
    printf("Indirizzo della stringa: %lX\n",s);

    /*
        Stampo l'indirizzo del primo elemento del vettore. Se è vero che s 
        contiene l'indirizzo al suo primo elemento i due valori saranno uguali
    */
    printf("Indirizzo del primo elemento: %lX\n", &s[0]);

    /* Stampo il primo elemento*/
    printf("Primo elemento della stringa: %c\n", s[0]);

    /*
        Stampo l'indirizzo del quarto elemento del vettore. Se è vero che
        gli elementi sono memorizzati in sequenza per consentire l'indicizzazione
        allora la differenza tra l'indirizzo del quarto elemento e quello
        del primo elemento sarà esattamente di ## tre volte la dimensione del tipo char ##
    */
    printf("Indirizzo del quarto elemento: %lX\n", &s[3]);

    return 0;
}