#include <stdio.h>

int main(){

    double v[5] = {3.5, 7.6, 1.2, -3.2};
    double *p = v;

    printf("Il vettore v vale: %lX\n", v);
    printf("il puntatore p vale: %lX\n", p);

    for(int i = 0; i < 5; i++){
        printf("L'elemento v[%d] vale: %lf\n", i, *(p + i));
    }

    return 0;
}