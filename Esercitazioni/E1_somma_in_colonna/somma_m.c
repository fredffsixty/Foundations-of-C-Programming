#include <stdio.h>

/*
    Somma in colonna versione 2.0

    il programma gestisce un numero di cifre variabili e accumula il risultato
    sommando ogni cifra in colonna moltiplicata per l'opportuna potenza di 10
*/
int main(){

    int m;                          // numero delle cifre
    int totale = 0;                 // accumula la somma totale
    int a, b, riporto = 0;          // cifre **correnti** dei due addendi e riporto
    int c;                          // cifra della nella colonna corrente
    int potenza10 = 1;              // potenza di 10 a cui dovrò elevare la cifra del risultato
    
    // Richiediamo il numero delle cifre
    printf("Inserisci il numero di cifre degli addendi > ");
    scanf("%d",&m);

    // Iteriamo sulle singole cifre
    for(int i = 0; i < m; i++){

        // Richiediamo le cifre correnti
        printf("Inserisci le cifre di a e b per la colonna %d",i);
        scanf("%d%d",&a,&b);

        // calcolo la somma in colonna
        c = a + b + riporto;

        // aggiorno il totale
        totale = totale + (c % 10) * potenza10;

        // aggiorno il riporto e la potenza di 10
        riporto = c / 10;
        potenza10 = potenza10 * 10;

    }

    // Aggiungiamo il riporto nell'ultima cifra se presente
    if(riporto == 1){
        totale = totale + riporto * potenza10;
    }

    printf("Il risultato è: %d\n", totale);

    return 0;

}