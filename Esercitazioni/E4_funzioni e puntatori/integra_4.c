#include <stdio.h>
#include <math.h>
#include <ctype.h>

/*
    integrale: calcola l'integrale definito di una funzione tre i due estremi a e b 
               come somma di trapezi. Richiama la funzione f per scegliere la funzione
               integranda
    
    Args:
            fun: puntatore a funzione che richiede un double e restituisce un double
            a: double che contiene il primo estremo di integrazione
            b: double che contiene il secondo estremo di integrazione
            steps: intero che contiene il numero di passi di valutazione della funzione f
    
    Returns:
            un valore double che rappresenta l'integrale definito di f da a a b

    Pre:
            a deve essere minore di b
            steps deve essere > 0
*/
double integrale(double fun(double), double a, double b, int steps){

    double f1, f2;          // i due valori di f che mi servono ad ogni iterazione
    double delta;           // passo di campionamento della funzione f
    double integral = 0.0;  // valore dell'integrale

    delta = (b - a) / steps;

    // Inizializzo f1 con f(a) in modo da gestire lo scambio delle variabili alla prima iterazione
    f1 = fun(a);

    for(double x = a; x < b; x += delta){
        // Miserve calcolare solo f2 perché f1 è già noto
        f2 = fun(x + delta);

        // passo di accumulazione dell'integrale
        integral = integral + (f1 + f2) * delta / 2;

        // aggiorno f1 al valore corrente di f2 in modo che sia corretto per l'iterazione successiva
        f1 = f2;
    }

    return integral;
}

/*
    Programma di calcolo dell'integrale definito in forma di somma di trapezi
*/
int main(){

    // Estremi di integrazione
    double a, b;

    // numero di passi
    int steps;

    // risultato dell'integrale
    double result = 0;

    /*
        funzione selezionata
        (può valere 'C'|'c' --> coseno, 'S'|'s' --> seno 'L'|'l' --> logaritmo 'T'|'t --> tangente)
    */
    char fun;

    /*
        Richiediamo i dati all'utente
    */
   do{
        printf("Inserisci la funzione da integrare\n('C'|'c' --> coseno, 'S'|'s' --> seno 'L'|'l' --> logaritmo 'T'|'t --> tangente): ");
        scanf("%c", &fun);

        // leggiamo il carattere '\n' che è stato lasciato nel buffer da scanf
        getchar();

        // normalizziamo il carattere selezionato
        fun = tolower(fun);

        if(fun != 'c' && fun !='s' && fun != 'l' && fun != 't'){
            printf("Selezione errata!\n\n");
        }
   }while(fun != 'c' && fun !='s' && fun != 'l' && fun != 't');

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

    switch (fun)
    {
    case 's':
        result = integrale(sin, a, b, steps);
        break;
    case 'c':
        result = integrale(cos, a, b, steps);
        break;
    case 't':
        result = integrale(tan, a, b, steps);
        break;
    default:
        result = integrale(log, a, b, steps);
        break;
    }
     
    printf("L'integrale definito da %lg a %lg della funzione è: %lg\n\n", a, b, result);

    return 0;
}