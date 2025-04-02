#include <stdio.h>

int main(void){
    double fahr, cels; /* Le due variabili di temperatura */

    /* Leggiamo la temperatura Fahreneit */
    printf("Inserisci la temperatura in gradi Fahreneit: ");
    scanf("%lf", &fahr);

    cels = (fahr - 32) * 5 / 9; /* il risultato è double */

    /* Stampa formattata */
    printf("La temperatura in gradi Celsius è: %5.2lf\n",cels);

    return 0;
}