#include <stdio.h>

int main(void){

    int v[6] = {18,30,24,27,14,23};

    /* Richiedo la dimensione in byte di ogni singolo elemento del vettore */
    printf("Dimensione del tipo int: %d byte\n", sizeof(int));
    
    /* Stampo il contenuto del vettore*/
    printf("Contenuto del vettore:\n");

    for(int i = 0;i<6;i++)
        printf("%d ",v[i]);
    printf("\n");
    
    /* 
        Stampo il vettore richiedendo la conversione come unsigned long in esadecimale:
        Se è vero che v contiene l'indirizzo al suo primo elemento potrò fare questa stampa 
        e ottenere un indirizzo valido
    */
    printf("Indirizzo del vettore: %lX\n",v);

    /*
        Stampo l'indirizzo del primo elemento del vettore. Se è vero che v 
        contiene l'indirizzo al suo primo elemento i due valori saranno uguali
    */
    printf("Indirizzo del primo elemento: %lX\n", &v[0]);

    /* Stampo il primo elemento*/
    printf("Primo elemento del vettore: %d\n", v[0]);

    /*
        Stampo l'indirizzo del quarto elemento del vettore. Se è vero che
        gli elementi sono memorizzati in sequenza per consentire l'indicizzazione
        allora la differenza tra l'indirizzo del quarto elemento e quello
        del primo elemento sarà esattamente di ## tre volte la dimensione del tipo int ##
    */
    printf("Indirizzo del quarto elemento: %lX\n", &v[3]);

    return 0;
}