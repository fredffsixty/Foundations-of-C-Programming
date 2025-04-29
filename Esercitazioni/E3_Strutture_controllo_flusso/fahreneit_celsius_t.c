#include <stdio.h>
#include <ctype.h>

/*
    Converte la temperatura in gradi Celsius a partire da quella in gradi Fahreneit
    e viceversa

    Args: 
        temp: temperatura in ingresso di tipo double
        verso: verso di conversione di tipo char che può essere solo 'F','f','C','c'
    
    Return:
        temperatura convertito di tipo double
    
    Pre: t deve essere definito
*/
double conv(double temp, char verso){
    // Conserva il risultato
    double converted;

    // Convertiamo il verso in minuscolo per evitare 4 controlli
    verso = tolower(verso);

    // Eseguiamo la conversione con l'operatore ternario ?:
    converted = verso == 'c' ? (temp - 32) * 5 / 9 : temp * 9 / 5 + 32;

    return converted;
}

int main(void){
    double temp;    /* La variabile di temperatura */
    char to;        /* Il verso di conversione */

    /* Leggiamo la temperatura e il verso */
    printf("Inserisci la temperatura: ");
    scanf("%lf", &temp);
    getchar();          // leggiamo e scartiamo il '\n' inserito con la scanf

    /* Inseriamo il verso di conversione controllando il valore esatto */
    do{
        
        printf("Inserisci il verso di conversione (F,f,C,c): ");
        scanf("%c",&to);
        getchar();          // leggiamo e scartiamo il '\n' inserito con la scanf
        
    }while(to != 'F' && to !='f' && to!='C' && to!='c');

    temp = conv(temp, to); /* il risultato è double */

    /* Stampa formattata */
    printf("La temperatura in gradi %s è: %5.2lf\n",to == 'f' ? "Fahreneit" : "Celsius", temp);

    return 0;
}