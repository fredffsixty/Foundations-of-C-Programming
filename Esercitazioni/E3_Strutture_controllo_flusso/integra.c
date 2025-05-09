#include <stdio.h>
#include <math.h>
#include <ctype.h>

/*
    Programma di calcolo dell'integrale definito in forma di somma di rettangoli
*/
int main(){

    // Estremi di integrazione
    double a, b;

    // numero di passi
    int steps;

    // risultato dell'integrale e passo di integrazione
    double integrale = 0, delta;

    // valore corrente della funzione integranda
    double f;

    // funzione selezionata (può valere 'C'|'c' --> coseno, 'S'|'s' --> seno 'L'|'l' --> logaritmo)
    char fun;

    /*
        Richiediamo i dati all'utente
    */
   do{
        printf("Inserisci la funzione da integrare\n('C'|'c' --> coseno, 'S'|'s' --> seno 'L'|'l' --> logaritmo): ");
        scanf("%c", &fun);

        // leggiamo il carattere '\n' che è stato lasciato nel buffer da scanf
        getchar();

        // normalizziamo il carattere selezionato
        fun = tolower(fun);

        if(fun != 'c' && fun !='s' && fun != 'l'){
            printf("Selezione errata!\n\n");
        }
   }while(fun != 'c' && fun !='s' && fun != 'l');

   do{
    printf("Inserisci il numero di passi di valutazione della funzione (> 0): ");
    scanf("%d", &steps);
        
        if(steps <= 0){
            printf("Devi inserire un numero di passi > 0\n\n");
        }
    }while(steps <= 0);

    do{
        printf("Inserisci gli estremi di integrazione a e b (a < b): ");
        scanf("%lg%lg", &a, &b);
    
            if(b < a){
                printf("L'estremo superiore è più piccolo dell'estremo inferiore\n\n");
            }
    }while(b < a);

    // Calcoliamo il passo di integrazione
    delta = (b - a) / steps;
    
    // Iniziamo la procedura di calcolo dell'integrale
    for(double x = a; x < b; x += delta){

        switch (fun)
        {
        case 'c':
            f = cos(x);
            break;
        case 's':
            f = sin(x);
            break;
        default:
            f = log(x);
            break;
        }

        integrale = integrale + f*delta;
    }

    printf("L'integrale definito da %lg a %lg della funzione è: %lg\n\n", a, b, integrale);

    return 0;
   
}
