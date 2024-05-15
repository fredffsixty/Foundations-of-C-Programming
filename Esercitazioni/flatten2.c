#include <stdio.h>
#include <stdlib.h>

/*
    colonna: restituisce il vettore colonna di mat alla posizione col

    Args:       mat (double **) la metrice da analizzare
                col (int) la colonna selezionata
                rows (int) numero di righe della matrice
                cols (int) numero di colonne della matrice

    Output:     il vettore colonna, di tipo double *, estratto da mat ovvero NULL se
                non riesce ad allocare correttamente il vettore colonna

    Pre:        la matrice mat deve essere già allocata
*/
double *colonna(double **mat, int col, int rows, int cols);

/*
    Il programma richiederà le dimensioni della matrice, l'inserimento dei suoi valori 
    attraverso il terminale e stamperà il vettore serializzato.
    
    Versione dinamica con aritmetica dei puntatori

*/
int main(int argc, char* argv[]){

    double **mat;           /* la matrice è un semplice puntatore di puntatore a double
                               e non è stata allocata la sua memoria */
    double *vec;            /* il vettore è dichiarato come puntatore,
                                e la memoria necessaria sarà allocata
                                dinamicamente
                            */
    double **r, *c;         /* puntatori alla riga generica della matrice e all'elemento 
                               generico dentro una riga
                            */
    
    int rows, cols,         /* Variabili che contengono le dimensioni della matrice */
        vecsize;            /* dimensione del vettore serializzato: rows*cols */

    int col;                /* Colonna selezionata dall'utente */
    
    /* Richiediamo le dimensioni della matrice da terminale */
    printf("Inserisci le dimensioni della matrice nel formato <righe> <colonne>: ");
    scanf("%d %d", &rows, &cols);

    /* Inizializziamo vecsize */
    vecsize = rows*cols;

    /* 
        Eseguiamo l'allocazione dinamica della memoria della matrice
       che è un vettore di vettori
    */
    mat = (double **)calloc(rows,sizeof(double *));
    if(mat == NULL){
        printf("Allocazione fallita!\n");
        exit(-1);
    }
    /* Eseguiamo l'allocazione della memoria per le singole righe */
    for(int i = 0;i < rows;i++){
        mat[i]=(double *)calloc(cols,sizeof(double));
        if(mat[i] == NULL){
             printf("Allocazione fallita!\n");
             exit(-1);
        }
    }
    
    /* Richiediamo all'utente gli elementi della matrice */
    for(int i = 0; i < rows; i++){
        r = mat + i;
        for(int j = 0; j < cols; j++){
            printf("Elemento (%d, %d): ",i,j);
            c = *r + j;
            scanf("%lf",c);
        }
    }

    /* Allochiamo la memoria per il vettore vec: rows*cols*sizeof(double) byte */
    vec = (double *)calloc(vecsize,sizeof(double));

    /* Avremmo potuto anche scrivere: vec = (double *)malloc(rows*cols*sizeof(double)); */

    /* Controlliamo che l'allocazione sia andata a buon fine */
    if(vec == NULL){
        printf("Allocazione di memoria fallita!\n");
        exit(-1);
    }

    /* 
        Serializziamo la matrice e inseriamo gli elementi in vec

        L'elemento di posto k del vettore si ottiene come k-esimo offset dall'indirizzo di vec
 
        L'elemento [i,j] della matrice si ottiene accedendo al contenuto dell'i-esimo offset dall'indirizzo di mat
        che è un indirizzo e aggiungendo a quest'ultimo l'offset j lungo la riga i
    */
    for(int i = 0, k = 0; i < rows; i++)
        for(int j = 0; j < cols; j++, k++)
            *(vec + k) = *(*(mat + i) + j);
    
    /* Stampiamo il vettore vec */
    for(int i = 0; i < vecsize; i++)
        printf("%lf\n",vec[i]);
    
    /* Stampiamo il vettore colonna richiesto dall'utente */
    printf("Scegli una colonna della matrice, partendo da 0: ");
    scanf("%d",&col);
    
    c = colonna(mat, col, rows, cols);

    if(c == NULL)
        printf("Errore nell'estrazione del vettore colonna\n");
    else{
        /* Stampiamo il vettore colonna selezionato */
        for(int i = 0; i < rows; i++)
            printf("%lf\n",c[i]);
    }
    
    return 0;       
}

double *colonna(double **mat, int col, int rows, int cols){

    double *column;             /* Vettore colonna risultato */

    if(col < 0 || col >= cols)  /* Caso in cui la colonna non rientra nell'intervallo */
        return NULL;
    
    column = (double *)calloc(rows, sizeof(double));    /* allocazione della memoria*/

    if(column != NULL)              /* Riempio il vettore solo se l'allocazione è andata a buon fine */
        for(int i = 0;i < rows;i++) /* itero sulle righe di mat */
            
            /* L'elemento i-esimo di column viene inizializzato con l'elemento (i, col) di mat */
            /* è equivalente a column[i] = mat[i][col] */
            *(column + i) = *(*(mat + i) + col);
    
    return column;
}