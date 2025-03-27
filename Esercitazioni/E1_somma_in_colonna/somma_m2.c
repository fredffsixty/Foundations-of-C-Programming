#include <stdio.h>
#include <math.h>

/*
    Somma in colonna versione 3.0

    il programma gestisce un numero di cifre variabili e accumula il risultato
    sommando ogni cifra in colonna moltiplicata per l'opportuna potenza di 10.

    In questa versione si utilizza la funzione pow() per calcolare la potenza di 10 
    e si richiedono le cifre degli addendi da quella più significativa a 
    quella meno significativa.
*/
int main(){

    int m;                          // numero delle cifre
    int totale = 0;                 // accumula la somma totale
    int a, b;                       // cifre **correnti** dei due addendi
    int c;                          // cifra della nella colonna corrente
    int potenza10;                  // potenza di 10 a cui dovrò elevare la cifra del risultato
    
    // Richiediamo il numero delle cifre
    printf("Inserisci il numero di cifre degli addendi > ");
    scanf("%d",&m);

    // Calcolo il valore iniziale della potenza di 10 per la cifra più significativa
    potenza10 = (int)pow(10, m-1);

    // Iteriamo sulle singole cifre
    for(int i = m - 1; i >= 0; i--){
        /*
            Se si evita l'inizializzazione di riga 27 potremmo ad ogni iterazione
            calcolare potenza10 = (int)pow(10, i);

            In questo caso si deve eliminare anche l'aggiornamento di potenza10
            che si trova in riga 49
        */
        
        // Richiediamo le cifre correnti
        printf("Inserisci le cifre di posto %d dei due addendi a e b: ",i + 1);
        scanf("%d%d",&a,&b);

        // calcolo la somma in colonna inclusiva del riporto
        c = a + b;

        // aggiorno il totale
        totale = totale + c * potenza10;

        // aggiorno ila potenza di 10
        potenza10 /= 10;

    }

    printf("Il risultato è: %d\n", totale);

    return 0;

}