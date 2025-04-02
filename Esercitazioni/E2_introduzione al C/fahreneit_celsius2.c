#include <stdio.h>

/*
    Calcola la temperatura in gradi Celsius a partire da quella in gradi Fahreneit
    contenuta in f

    Args: 
        f: temperatura in gradi Fahreneit di tipo double
    
    Return:
        temperatura in gradi Celsius corrispondente di tipo double
    
    Pre: f deve essere definito
*/
double fahr2cels(double f){
    return (f - 32) * 5 / 9;
}

int main(void){
    double fahr, cels; /* Le due variabili di temperatura */

    /* Leggiamo la temperatura Fahreneit */
    printf("Inserisci la temperatura in gradi Fahreneit: ");
    scanf("%lf", &fahr);

    cels = fahr2cels(fahr); /* il risultato è double */

    /* Stampa formattata */
    printf("La temperatura in gradi Celsius è: %5.2lf\n",cels);

    return 0;
}