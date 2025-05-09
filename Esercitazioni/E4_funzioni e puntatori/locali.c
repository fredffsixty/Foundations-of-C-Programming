#include <stdio.h>

double funzione(double x){
    // restituiamo 2 * x + 7

    printf("Indirizzo del parametro: %lX\n",&x);
    x *= 2;

    return x + 7;
}

int main(){

    double variabile;

    printf("Inserisci variabile: ");
    scanf("%lf",&variabile);

    printf("Indirizzo della variabile inserita: %lX\n", &variabile);

    printf("La funzione vale: %lf\nLa vriabile vale: %lf\n", funzione(variabile), variabile);

    return 0;
}