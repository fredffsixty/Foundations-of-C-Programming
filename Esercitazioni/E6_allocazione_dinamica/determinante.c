/*
    determinante: programma che deve accettare 4 o 9 numeri reali da lina di comando
    e conseguentemente allocare una matrice 2x2 o 3x3 e calcolarne il determinante tramite
    un'apposita funzione


    Pseudicodifica:

    1. Leggere da linea di comando gli elementi della matrice

    2. controllare il numero di elementi inseriti

    3. controllare che siano stati inseriti tutti numeri 
        NO perché lo faremo durante l'inserimento degli elementi nella matrice

    4. Stabilire la dimensione della matrice

    5. Allocare la memoria per la matrice e inseriamo i valori

    6. Inserire i valori nella matrice

    7. Calcolare il determinante richiamando l'apposita funzione det che dovrà 
    accettare in ingresso la matrice e la sua dimensione e restituire il valore del determinante
    per cui avrà la seguente firma: double det(double **, int)

    8. Stampare il risultato
*/

#include <stdio.h>      // Gestione I/O
#include <stdlib.h>     // Allocazione dinamica della memoria e conversione stringa-numero
#include <math.h>       // calcolo della radice quadrata del numero di elementi per ottenere la dimensione



double det(double **, int);     // dichiarazione della firma della funzione determinante

int main(int argc, char *argv[]){

    double **m;     // La matrice da gestire
    int size;       // dimensione della matrice

    if(argc != 5 && argc != 10){
        printf("Errore nell'inserimento degli elementi della matrice\nSi possono inserire solo 4 o 9 valori\n");
        exit(-1);
    }

    size = (int)sqrt(argc - 1);    // la dimensione della matrice è pari radice quadrata di  argc - 1 
                                   // perché non dobbiamo contare il nome del programma che è in argv[0]


    // allocazione dinamica della memoria
    m = (double **)malloc(size * sizeof(double *));
    for(int i = 0; i < size; i++){
        m[i] = (double *)malloc(size * sizeof(double));
    }

    // Inseriamo i valori nella matrice
    for(int i = 0, k = 1; i < size; i++){
        for(int j = 0; j < size; j++, k++){
            // k scorre l'intero vettore argv a partire dal secondo elemento
            m[i][j] = atof(argv[k]);    
        }
    }

    // Calcoliamo e stampiamo il determinante
    printf("Il determinante della matrice è pari a %lf\n\n", det(m, size));

    return 0;

}

double det(double **matrice, int dim){

    if(dim == 2){
        return matrice[0][0] * matrice[1][1] - matrice[0][1] * matrice[1][0];
    }
    else{
        // regola di Sarrus
        return matrice[0][0] * matrice[1][1] * matrice[2][2] + 
                matrice[0][2] * matrice[1][0] * matrice[2][1] +
                matrice[2][0] * matrice[0][1] * matrice[1][2] -
                matrice[0][2] * matrice[1][1] * matrice[2][0] -
                matrice[0][0] * matrice[1][2] * matrice[2][1] -
                matrice[2][2] * matrice[1][0] * matrice[0][1];
    }
}