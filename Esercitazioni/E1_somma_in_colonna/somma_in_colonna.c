#include <stdio.h>

/*
    somma_in_colonna: implementazione di un algoritmo di somma 
    in colonna di numeri di tre cifre.

    Il programma richiederà all'utente le singole cifre dei due addendi, eseguirà la
    procedura di somma in colonna con riporto: c_i = a_i + b_i + r_i-1

    In uscita verrà stampata la sequenza delle cifre del risultato con eventuale riporto
    nell'ultima colonna.
*/
int main(){

    // cifre del primo operando
    int a0, a1, a2;

    // cifre del secondo numero
    int b0;
    int b1;
    int b2;
    // potrei anche scrivere int b0, b1, b2;

    // dichiariamo il riporto
    int riporto = 0;

    // dichiariamo le cifre della somma
    int c0, c1, c2;

    // Richiediamo le cifre del primo addendo
    printf("Inserisci le cifre del primo addendo (tre interi da 0 a 9 separati da spazio) > ");
    scanf("%d %d %d", &a2, &a1, &a0);

    // Richiediamo le cifre del secondo addendo
    printf("Inserisci le cifre del secondo addendo (tre interi da 0 a 9 separati da spazio) > ");
    scanf("%d %d %d", &b2, &b1, &b0);

    // Eseguiamo la somma delle cifre della prima colonna
    c0 = a0 + b0; // è come se ci fosse anche + riporto
    if(c0 >= 10){
        c0 = c0 % 10; // si poteva fare anche c0 = c0 - 10;
        riporto = 1;
    } else {
        riporto = 0;
    }

    // Eseguiamo la somma delle cifre della seconda colonna
    c1 = a1 + b1 + riporto;
    if(c1 >= 10){
        c1 = c1 % 10; // si poteva fare anche c0 = c0 - 10;
        riporto = 1;
    } else {
        riporto = 0;
    }

    // Eseguiamo la somma delle cifre della terza colonna
    c2 = a2 + b2 + riporto;
    if(c2 >= 10){
        c2 = c2 % 10; // si poteva fare anche c0 = c0 - 10;
        riporto = 1;
    } else {
        riporto = 0;
    }

    // Stampa del risultato
    if(riporto == 1){
        printf("Il risultato è: %d%d%d%d\n",riporto, c2, c1, c0);
    } else {
        printf("Il risultato è: %d%d%d\n", c2, c1, c0);
    }

    return 0;
}