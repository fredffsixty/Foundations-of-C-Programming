#include <stdio.h>
#include <stdlib.h> /* per la funzione atoi:  conversione stringa-numero */

/*
    get_int: acquisice un intero inserito dall'utente e ne 
    verifica il formato e l'appartenenza ad un intervallo dato

    Args: n_min e n_max (int) gli estremi dell'intervallo
    
    Returns: n_val (int) il valore inserito dall'utente e controllato
    
    Pre: n_min <= n_max
    Post: n_min <= n_val <= n_max
*/
int get_int(int n_min, int n_max);

/*
    check_int: verifica che la stringa in ingresso corrisponda al formato: "+###"
    oppure "-####" e restituisce il valore intero corrispondente

    Args: str (char* ) la stringa da convertire

    Returns: num (int) il numero convertito
*/
int check_int(char *str);

/* 
    Il programma sarà invocato con un comando: intervallo <numero minimo> <numero massimo>
*/
int main(int argc, char* argv[]){

    /* l'intero da stampare e i due estremi dell'intervallo */
    int n_val, n_min, n_max;

    n_min = check_int(argv[1]);
    n_max = check_int(argv[2]);

    n_val = get_int(n_min, n_max);

    printf("Il numero %d selezionato e' corretto\n", n_val);

    return 0;
}


int check_int(char *str){

    int num = atoi(str);

    /* Verifica che la conversione sia corretta o meno */
    if(num == 0 && str != "0")
        return EOF;        /* risultato in caso di errore */
    else
        return num;             /* risultato corretto */
}

int get_int(int n_min, int n_max){

    int in_val, status;     /* in_val: numero inserito dall'utente 
                             status: valore di ritorno di scanf */
    char skip_ch;           /* carattere dell'input da saltare  */ 
    int error;              /* flag di errore */

    /* Acquisisco i dati di input finché in_val non rientra nell'intervallo richiesto */ 
    do {
        /* Nessu errore fin'ora */
        error = 0;

        /* Richiedo un numero all'utente */
        printf("Inserisci un intero nell'intervallo da %d ", n_min); 
        printf("fino a %d incluso > ", n_max);
        status = scanf("%d", &in_val);

        /* Valido il numero */
        if (status != 1) { /* la scanf non ha acquisito un numero */
            error = 1;

            scanf("%c", &skip_ch);
            printf("Carattere non valido >>%c>>. ", skip_ch); 
            printf("Salto il resto della linea.\n");

        } 
        else if (in_val < n_min || in_val > n_max) { 
            error = 1;
            printf("Number %d is not in range.\n", in_val); 
        }

        /* Salto il resto della linea */
        do{
            scanf("%c", &skip_ch);
        }while (skip_ch != '\n');

    } while (error);
    
    return (in_val);
}