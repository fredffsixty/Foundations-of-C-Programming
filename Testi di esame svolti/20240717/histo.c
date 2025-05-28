/*
    Il programma verrà invocato come histo <nome_file.txt> e stamperà in uscita
    l'istogramma delle lettere presenti nel testo contando indifferentemente
    le occorrenza delle lettere maiuscole e minuscole.

    Esempio, se il file contiene il testo: 
    "La donzelletta vien dalla campagna e reca in man"

    L'uscita sarà:

    a: 9
    c: 2
    d: 2
    e: 5
    g: 1
    i: 2
    l: 5
    m: 2
    n: 5
    o: 1
    p: 1
    r: 1
    t: 2
    v: 1
    z: 1
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define LETTERS /* Q1: determinare il numero corretto di lettere per l'alfabeto inglese*/

/*
    hist:       calcola l'istogramma, analizzando iterativamente ogni 
                carattere del testo e, se si tratta di una lettera, verifica 
                se è maiuscola e la trasforma nella corrispondente minuscola
                infine aggiorna la posizione corrispondente nel vettore dell'istogramma
                secondo il seguente schema:

                'a' --> 0, 'b' --> 1, 'c' --> 2, ...

    Args:       FILE *f il file di testo da analizzare

    Returns:    il vettore dell'istogramma che è di tipo int* e ha lunghezza 
                predefinita pari al numero delle lettere dell'alfabeto definito
                nella costante LETTERS

    Pre:        f deve essere già aperto in lettura
*/
int *hist(FILE *f);

int main(int argc, char *argv[]){

    FILE *infp;

    /* vettore che contiene l'istogramma */
    int *istogramma;

    /*
        Q1: gestire gli argomenti da linra di comando verificando che siano 
            del numero corretto e che il file esista inviando all'utente un apposito
            messaggio di errore per ognuma delle due eventualità
    */

    /*
    Calcola l'istogramma e lo restituisce al main
    */
    istogramma = hist(infp);

    /*
    Stampa dei risultati
    */
   /*
        Q2: stampa dei soli valori diversi da 0 secondo il formato riportato
            nelcommento in testa al codice
   */

    return 0;
}

int *hist(FILE *f){

    /*
        Q3: implementare il codice della funzione secondo quanto richiesto
    */
}