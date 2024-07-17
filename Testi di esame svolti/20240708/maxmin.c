/*
    Il propgramma verrà invocato come:
        
        maxmin <nome_funzione> <estremo_inferiore> <estremo_superiore> <n_punti>
    
    calcolerà la derivata della funzione lungo una sequenza di <n_punti> 
    valori equispaziati nell'intervallo specificato e stamperà in uscita un messaggio
    ogni volta che la derivata è in valore assoluto **più piccola** del valore ROUND
    di arrotondamento definito nel programma.

    I messaggi saranno di questo tipo:

    Rilevato un punto estremo per x = ...
    Rilevato un punto estremo per x = ...

    e così via.

    Ad esempio, la chiamata:

    maxmin poly2 0.0 2.0 5000

    fornirà un messaggio:

    "Rilevato un punto estremo per x = 0.333200"

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
    tipo enumerativo con la lista delle funzioni
*/
typedef enum {seno, coseno, parabola, cubica} funtype;


#define ROUND 0.001     /* Arrotondamento per verificare se la derivata si annulla */
#define DELTA 0.00001   /* Step per il calcolo della derivata */

/*
    Fa il check della stringa con il nome della funzione.

    Legge l'argmento da linea di comando per verificare cha appartenga ad una delle
    scelte ammesse: 'sin', 'cos', 'poly2', 'poly3'

    Restituisce l'elemento del tipo funtype corrispondente alla scelta passata
    nell'argomento str

    Args:
        str: la stringa da verificare

    Output: la selezione sotto forma di tipo enumerativo
*/
funtype check_fun(char *str);

/*
    Calcola la derivata numerica di una funzione f(x) usando la formula
    del rapporto incrementale:

        df/dx = [f(x+𝚫)-f(x-𝚫)]/2𝚫
    
    Args:
            f: la funzione da derivare, di tipo 'double (double)'
            x: il punto in cui calcolare la derivata, di tipo double
    
    Output: il valore della derivata di tipo double

*/
double derivata(double f(double), double x);

/*
    Funzione polinomiale di secondo grado definita tra le scelte di input
*/
double poly2(double x){

    return 3*x*x - 2*x - 4;
}

/*
    Funzione polinomiale di terzo grado definita tra le scelte di input
*/
double poly3(double x){

    return 3*x*x*x - 2*x*x + 7*x - 4;
}

int main(int argc, char *argv[]){

    double inf, sup;        /* estremi dell'intervallo */
    double step;            /* passo di incremento dell'ascissa */
    int n_punti;            /* numero dei punti da verificare */
    double x, d;            /* ascissa e derivata corrente */

    if((inf = atof(argv[2])) >= (sup = atof(argv[3]))){
        printf("L'intervallo è stato specificato in maniera errata\n");
        return 0;        
    }
    if((n_punti = atoi(argv[4])) <=0){
        printf("numero di punti da analizzare negativo o nullo\n");
        return 0;        
    }

    step = (sup - inf)/n_punti;

    funtype fun = check_fun(argv[1]);

    for(int i = 1; i <= n_punti; i++){

        x = inf + i * step;

        switch (fun)
        {
        case seno:
            d = derivata(sin, x);
            break;
        case coseno:
            d = derivata(cos, x);
            break;
        case parabola:
            d = derivata(poly2, x);
            break;
        case cubica:
            d = derivata(poly3, x);
            break;
        default:
            printf("Specifica errata della funzione\nUsare solo 'sin', 'cos', 'poly2' e 'poly3'\n");
            return 0;
        }

        if(fabs(d) <= ROUND)
            printf("Rilevato un punto estremo per x = %lf\n",x);
    }

    return 0;
}

double derivata(double f(double), double x){

    return (f(x+DELTA)-f(x-DELTA))/(2*DELTA);

}

funtype check_fun(char *str){

    funtype f;

    if(strcmp(str,"sin")==0)
        f = seno;
    if(strcmp(str,"cos")==0)
        f = coseno;
    if(strcmp(str,"poly2")==0)
        f = parabola;
    if(strcmp(str,"poly3")==0)
        f = cubica;
    
   return f; 
}
