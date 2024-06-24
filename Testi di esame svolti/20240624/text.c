/*
    Il programma verrà invocato come text <nome_file.txt> e stamperà in uscita
    le statistiche del testo:

        - n. di parole totali
        - n. parole da 1 carattere
        - n. parole da 2 caratteri
        - n. parole da 3 caratteri
        ...
    
    La stampa avverrà solo per le lunghezze per cui esistono parole.

    Esempio, se il file contiene il testo: 
    "la donzelletta vien dalla campagna e reca in man"

    L'uscita sarà:
    N. parole totali: 9
    n. parole di lunghezza 1: 1
    n. parole di lunghezza 2: 2
    n. parole di lunghezza 3: 1
    n. parole di lunghezza 4: 2
    n. parole di lunghezza 5: 1
    n. parole di lunghezza 8: 1
    n. parole di lunghezza 11: 1
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Numero massimo di parole nel testo, a scelta del candidato */
#define MAX_WORD_LENGTH 26

/*
    text_stats: calcola il numero totale delle parole in un file di testo e anche 
                il numero delle parole per ogni data lunghezza.

    Args:       int *stats il vettore delle statistiche passato per indirizzo che conterrà in prima posizione il 
                            totale delle parole e poi, per ogni indice, il numero di parole che hanno lunghezza
                            pari l valore dell'indice.
                FILE *f il file di testo da analizzare

    Returns:    void

    Pre:        f deve essere già aperto in lettura
                il vettore passato come **parametro attuale** deve essere già allocato
*/
void text_stats(int *stats, FILE *f);

int main(int argc, char *argv[]){

    FILE *infp;

    /* vettore che contiene le statistiche */
    int *statistiche;


    if(argc != 2){
        printf("Errore negli argomenti\nSintassi: text <nome file>\n\n");
        return 0;
    }

    if((infp=fopen(argv[1],"r")) == NULL){
        printf("File %s non trovato!\n\n",argv[1]);
        return 0;
    }

    /* Allochiamo opportunamente il vettore per contenere tutte le informazioni 
    sulla base del valore di MAX_WORD_LENGTH */

    statistiche = (int *)calloc(MAX_WORD_LENGTH+1,sizeof(int));

    text_stats(statistiche, infp);

    /*
    Stampa dei risultati
    */
    printf("N. parole totali: %d\n",statistiche[0]);

    for(int i = 1 ; i <= MAX_WORD_LENGTH; i++)
        if(statistiche[i] != 0)
            printf("N. parole di lunghezza %d: %d\n",i,statistiche[i]);

    return 0;
}

void text_stats(int *stats, FILE *f){

    char buf[MAX_WORD_LENGTH+1]="";
    
    do {
        fscanf(f,"%s",buf);

        if(strlen(buf) != 0){
            stats[0]++;

            stats[(int)strlen(buf)]++;

            strcpy(buf,"");
        }

    } while(!feof(f));

    return;
}