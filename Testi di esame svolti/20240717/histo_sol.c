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

#define LETTERS 26

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

    Pre:        f deve essere già aperto in lettura*/
int *hist(FILE *f);

int main(int argc, char *argv[]){

    FILE *infp;

    /* vettore che contiene l'istogramma */
    int *istogramma;

    if(argc != 2){
        printf("Errore negli argomenti\nSintassi: text <nome file>\n\n");
        return 0;
    }

    if((infp=fopen(argv[1],"r")) == NULL){
        printf("File %s non trovato!\n\n",argv[1]);
        return 0;
    }

    /*
    Calcola l'istogramma e lo restituisce al main
    */
    istogramma = hist(infp);

    /*
    Stampa dei risultati
    */
    for(int i = 0 ; i < LETTERS; i++)
        if(istogramma[i] != 0)
            printf("%c: %d\n",'a'+ i,istogramma[i]);

    return 0;
}

int *hist(FILE *f){

    char buf;
    int *h = calloc(LETTERS, sizeof(int));

    do {
        buf = fgetc(f);

        if(isalpha(buf)){
            buf = tolower(buf);

            h[buf - 'a']++;
        }

    } while(!feof(f));

    return h;
}