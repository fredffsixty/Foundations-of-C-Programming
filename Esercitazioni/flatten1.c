#include <stdio.h>
#include <stdlib.h>

/*
    Il programma richiederà le dimensioni della matrice, l'inserimento dei suoi valori 
    attraverso il terminale e stamperà il vettore serializzato.
    
    Versione dinamica

*/
int main(int argc, char* argv[]){

    double **mat;           /* la matrice è un semplice puntatore di puntatore a double
                               e non è stata allocata la sua memoria */
    double *vec;            /* il vettore è dichiarato come puntatore,
                                e la memoria necessaria sarà allocata
                                dinamicamente
                            */
    int rows, cols,         /* Variabili che contengono le dimensioni della matrice */
        vecsize;            /* dimensione del vettore serializzato: rows*cols */
    
    /* Richiediamo le dimensioni della matrice da terminale */
    printf("Inserisci le dimensioni della matrice nel formato <righe> <colonne>: ");
    scanf("%d %d", &rows, &cols);

    /* Inizializziamo vecsize */
    vecsize = rows*cols;

    /* Eseguiamo l'allocazione dinamica della memoria della matrice
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
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++){
            printf("Elemento (%d, %d): ",i,j);
            scanf("%lf",&mat[i][j]);
        }

    /* Allochiamo la memoria per il vettore vec: rows*cols*sizeof(double) byte */
    vec = (double *)calloc(vecsize,sizeof(double));

    /* Avremmo potuto anche scrivere: vec = (double *)malloc(rows*cols*sizeof(double)); */

    /* Controlliamo che l'allocazione sia andata a buon fine */
    if(vec == NULL){
        printf("Allocazione di memoria fallita!\n");
        exit(-1);
    }

    /* Serializziamo la matrice e inseriamo gli elementi in vec */
    for(int i = 0, k = 0; i < rows; i++)
        for(int j = 0; j < cols; j++, k++)
            /* l'indice del vettore si calcola: <n. riga> * <dim. colonna> + <num. colonna> */
            vec[k] = mat[i][j];
    
    /* Stampiamo il vettore vec */
    for(int i = 0; i < vecsize; i++)
        printf("%lf\n",vec[i]);
    
    return 0;       
}