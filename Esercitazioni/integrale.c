#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define NO_INTEGRAL -1000.0

typedef enum {seno, coseno, logaritmo, esponenziale} funtype;


/*
    integrale:  calcola l'integrale definito di f(x) da a a b utilizzando la formula dei trapezi
                e valutando la funzione in un numero steps di passi

    Args:       f (double (*)(double) ): la funzione da integrare
                a (double): estremo inferiore dell'intervallo
                b (double): estremo superiore dell'intervallo
                steps (int): numero di passi di valutazione della funzione f
    
    Output:     l'integrale definito di tipo double

    Pre:        steps > 0, a <= b
*/
double integrale(double f(double), double a, double b, int steps);

/*
    parse_fun:  trasforma una stringa appartenenete all'insieme ("sin","cos","log,"exp")
                nel corrispondente valore enumerativo di tipo funtype

    Args:       fun (char[]): la stringa di ingresso letta da linea di comando

    Ouput:      il valore enumerativo di tippo funtype che definisce la funzione selezionata
*/
funtype parse_fun(char fun[]){
    if(strcmp(fun, "sin") == 0)
        return seno;
    else if(strcmp(fun, "cos") == 0)
        return coseno;
    else if(strcmp(fun, "log") == 0)
        return logaritmo;
    else if(strcmp(fun, "exp") == 0)
        return esponenziale;
    else{
        printf("La funzione indicata non è tra quelle consentite\nUtilizzare solo: sin, cos, log, exp\n");
        exit(-1);
    }
}

/*
    Invochiamo il programma da linea di comando come: integrale <funzione> <a> <b> <step>

    <funzione> si potrà scegliere tra "sin", "cos", "log", "exp"
*/
int main(int argc, char *argv[]){

    double a, b;                /* estremi dell'intervallo di integrazione */

    int steps;                  /* il numero di passi */

    double integ;               /* l'integrale da calcolare */

    funtype myfun;

    /* Convertiamo gli estremi e i lnumero di passi in variabili numeriche */
    a = atof(argv[2]);
    b = atof(argv[3]);

    steps = atoi(argv[4]);

    /* Eseguiamo il parsing del nome della funzione */
    myfun = parse_fun(argv[1]);

    switch (myfun)
    {
    case seno:
        integ = integrale(sin, a, b, steps);
        break;
    case coseno:
        integ = integrale(cos, a, b, steps);
        break;
    case logaritmo:
        integ = integrale(log, a, b, steps);
        break;
    case esponenziale:
        integ = integrale(exp, a, b, steps);
        break;
    }

    if(integ != NO_INTEGRAL)
        printf("L'integrale calcolato vale: %lf\n\n", integ);
    
    return 0;
}

double integrale(double f(double), double a, double b, int steps){

    double delta;                   /* il passo di campionamento di f */

    double f1, f2,                  /* i due valori di f consecutivi ad ogni passo */
           temp;                    /* valore di scambio: vale f2 al passo k e diventa 
                                       f1 al passo k+1 */

    double integ = 0;               /* accumulatore del valore dell'integrale */

    if(steps <= 0){
        printf("Errore nel numero di passi\n");
        return NO_INTEGRAL;
    }

    if(b < a){
        printf("Errore nell'intervallo: il secondo estremo deve essere maggiore o uguale al primo\n");
        return NO_INTEGRAL;
    } else if ( b == a)
        return 0.0;

    /* Inizializzazione del ciclo */
    delta = (b - a)/steps;
    temp = f(a);

    for(int i = 0; i < steps; i ++){

        f1 = temp;
        f2 = f(a + (i+1)*delta);    /* il valore di f all'estremo superiore 
                                       dell'i-esimo intervallo*/

        integ = integ + (f1 + f2) * delta / 2.0; /* Calcolo il trapezio corrente */

        temp = f2;                  /* Conservo f2 in temp per utilizzarlo come primo 
                                        estremo alla iterata successiva */
    }

    return integ;                   /* L'integrale si approssima come la somma delle
                                        aree dei trapezi */
}