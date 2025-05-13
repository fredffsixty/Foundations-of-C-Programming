#include <stdio.h>
#include <stdlib.h>

int main(){

    // dichiariamo la matrice
    double **m;

    // definiamo le dimensioni di m
    int righe = 3, colonne = 2;

    // Codice di allocazione dinamica della matrice m
    m = (double **)malloc(righe * sizeof(double *));
    
    // alloco le singole righe
    for(int i = 0;i < righe; i++){
        m[i] = (double *)malloc(colonne * sizeof(double));
    }

    // Leggo gli elementi della matrice
    for(int i = 0; i < righe; i++)
        for(int j = 0; j < colonne; j++){
            printf("Inserisci l'elemento [%d][%d]> ",i, j);
            scanf("%lf",&m[i][j]);
        }
    
    // Stampiamo la nostra matrice
    printf("[");
    for(int i = 0; i < righe; i++){
        printf("[");
        for(int j = 0; j < colonne; j++){
            // uso l'operatore ternario al posto di if - else per valutare la stringa formato
            printf(j == colonne - 1 ? "%lf" : "%lf, ",m[i][j]);
        }
        // uso l'operatore ternario al posto di if - else per valutare la stringa formato
        printf(i == righe - 1 ? "]" : "]\n");
    }
    printf("]\n");

    return 0;
}