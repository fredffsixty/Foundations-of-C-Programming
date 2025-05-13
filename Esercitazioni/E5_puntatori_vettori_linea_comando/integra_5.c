#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

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

    versione con argomenti da linea di comando
*/
int main(int argc, char *argv[]){

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

    // Controllo della lista degli argomenti da linea di comando
    if(argc != 5){
        printf("Numero errato di argomenti.\n\nDigitare:\nintegra_5 fun a b nsteps\n");
        exit(-1);
    }

    // normalizziamo il carattere di selezione della funzione che è il **primo**
    // carattere di argv[1]
    fun = tolower(argv[1][0]);
    if(fun != 'c' && fun !='s' && fun != 'l' && fun != 't'){
        printf("Selezione errata!\n\nInserire:\n'C'|'c' --> coseno, 'S'|'s' --> seno 'L'|'l' --> logaritmo 'T'|'t --> tangente");
        exit(-1);
    }

    // leggiamo i due estremi di integrazione
    a = atof(argv[2]);
    b = atof(argv[3]);

    if(b < a){
        printf("L'estremo superiore risulta più piccolo dell'estremo inferiore\n");
        exit(-1);
    }

    // leggiamo i passi di integrazione
    steps = atoi(argv[4]);

    if(steps <= 0){
        printf("Inserire un numero di passi di integrazione > 0\n");
        exit(-1);
    }


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