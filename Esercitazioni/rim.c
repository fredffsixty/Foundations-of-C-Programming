#include <stdio.h>

#define PI 3.141592

/*
    Calcola l'area del cerchio a partire dal suo diametro d
    che è un valore reale

    Pre: d deve essere definito e deve avere valore positivo
*/
double circle_area(double d);

/*
    Calcola l'area della guarnizione a partire dai sue diametri
    d1 e d2 riaspettivamente diametro interno ed esterno che sono
    di tipo double

    Pre: d1 e d2 devono essere definiti e positivi

    Richiama circle_area 
*/
double rim_area(double d1, double d2);

/*
    Calcola il volume di una guarnizione a partire dall'area rim_area di tipo double
    e dallo spessore thickness di tipo double

    Pre: thickness deve essere definito e positivo, 
    la funzione rim_area deve essere già stata chiamata
*/
double rim_volume(double rim_area, double thickness);

int main(void){

    /* Dichiaro le variabili legate alle dimensioni della guarnizione */
    double hole_diam, 
            edge_diam, 
            thickness, 
            area, 
            volume;

    /* Dichiaro la densità della guarnizione */
    double density;

    /* Dicharo il numero delle guarnizioni nel lotto */
    int n;

    /* Richiedo gli input all'utente */
    printf("Inserisci il diametro interno: ");
    scanf("%lf",&hole_diam);

    printf("Inserisci il diametro esterno: ");
    scanf("%lf",&edge_diam);

    printf("Inserisci lo spessore: ");
    scanf("%lf",&thickness);

    printf("Inserisci il numero di guarnizioni: ");
    scanf("%d",&n);

    printf("Inserisci la densità del materiale: ");
    scanf("%lf",&density);

    /* Calcolo l'area dell'anello della guarnizione */
    area = rim_area(hole_diam,edge_diam);

    /* Calcolo il volume della guarnizione */
    volume = rim_volume(area, thickness);

    /* Stampo il peso del lotto di guarnizioni */
    printf("Il peso del lotto è: %lf\n", n*density*volume);

    return 0;
}

double circle_area(double d){

    return PI * (d/2) * (d/2);
}

double rim_area(double d1, double d2){

    return circle_area(d2) - circle_area(d1);
}

double rim_volume(double rim_area, double thickness){

    return rim_area * thickness;
}