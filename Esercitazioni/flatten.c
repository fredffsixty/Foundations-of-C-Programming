#include <stdio.h>
#include <stdlib.h>

/*
    Il programma richiederà l'inserimento dei valori 
    della matrice attraverso il terminale

*/
int main(int argc, char* argv[]){

    double mat[2][3];       /* la matrice è allocata, ma vuota */
    double *vec;            /* il vettore è dichiarato come puntatore,
                                e la memoria necessaria sarà allocata
                                dinamicamente
                            */
    
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 3; j++){
            printf("Elemento (%d, %d): ",i,j);
            scanf("%lf",&mat[i][j]);
        }
    
    /* Allochiamo la memoria per il vettore vec: 2*3*sizeof(double) byte */
    vec = (double *)calloc(2*3,sizeof(double));

    /* Avremmo potuto anche scrivere: vec = (double *)malloc(2*3*sizeof(double)); */

    /* Controlliamo che l'allocazione sia andata a buon fine */
    if(vec == NULL){
        printf("Allocazione di memoria fallita!\n");
        exit(-1);
    }

    /* Serializziamo la matrice e inseriamo gli elementi in vec */
    for(int i = 0, k = 0; i < 2; i++)
        for(int j = 0; j < 3; j++, k++)
            /* l'indice del vettore si calcola: <n. riga> * <dim. colonna> + <num. colonna> */
            vec[k] = mat[i][j];
    
    /* Stampiamo il vettore vec */
    for(int i = 0; i < 6; i++)
        printf("%lf\n",vec[i]);
    
    return 0;       
}