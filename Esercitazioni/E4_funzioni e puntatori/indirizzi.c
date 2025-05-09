#include <stdio.h>

double funzione(double* x){
    // restituiamo 2 * x + 7

    *x *= 2;

    printf("Indirizzo del parametro puntatore: %lX\n",x);

    return *x + 7;
}

int main(){

    double variabile, y;

    printf("Inserisci variabile: ");
    scanf("%lf",&variabile);

    printf("Indirizzo della variabile inserita: %lX\n", &variabile);

    y = funzione(&variabile);

    printf("La funzione vale: %lf\nLa variabile vale: %lf\n", y, variabile);

    return 0;
}