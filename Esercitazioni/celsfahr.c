#include <stdio.h>
#define CELS_TO_FAHRE 1.8

/*
    converti: converte la temperatura da gradi Celsius Fahreneit
    e viceversa in dipendenza da un parametro che indica il verso della
    conversione

    Input: temp di tipo double, la temperatura da convertire
           verso di tipo int che vale 1 o 0 per indicare il verso della conversione
    
    Output: la temperatura convertita di tipo double
*/
double converti(double temp, int verso);

/*
    Programma principale che gestisce la scelta errata da parte dell'utente
    sul verso di conversione
*/
int main(void){

    double temperatura; /* gradi Celsius o Fahreneit */
    int verso;          /* 0 --> C to F; 1 --> F to C */

    /* Richiediamo la temperatura ed il verso di conversione */
    printf("Inserisci la temperatura da convertire: ");
    scanf("%lf",&temperatura);

/*    printf("\nInserisci il verso di conversione (0 --> C2F; 1 --> F2C): ");
    scanf("%d",&verso);

    while(verso!=0 && verso!=1){
        /* Input errato */
/*        printf("Verso errato\n\n");
        printf("\nInserisci il verso di conversione (0 --> C2F; 1 --> F2C): ");
        scanf("%d",&verso);
    }
*/
    do{
        printf("\nInserisci il verso di conversione (0 --> C2F; 1 --> F2C): ");
        scanf("%d",&verso);

        if(verso!=0 && verso!=1)
            printf("Verso errato\n\n");

    }while(verso!=0 && verso!=1);

    printf("La temperatura convertita è: %5.2lf\n", converti(temperatura, verso));

    return 0;

}

double converti(double temp, int verso){

    double out_temp = 0.0;

    switch (verso)
    {
    case 0:
        /* Da Celsius a Fahreneit */
        out_temp = temp * CELS_TO_FAHRE + 32;
        break;
    
    case 1:
        /* Da Fahreneit a Celsius */
        out_temp = (temp - 32)/CELS_TO_FAHRE;
        break; /* questo break potrebbe non esserci perché siamo alla fine */
    }

    return out_temp;
}