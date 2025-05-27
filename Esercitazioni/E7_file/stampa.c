#include <stdio.h>

int main(int argc, char *argv[]){

    FILE *fptr; // puntatore a file
    char c;     // cartattere che viene letto dal file e scritto sullo standard output

    /*
        Gestione argomenti linera di comando. Utilizzo: stampa <nome file>
    */
    if(argc != 2){
        printf("Errore nell'invocazione del programma\nUtilizzo: stampa <nome file>\n\n");
        return 0;
    }
    if((fptr = fopen(argv[1],"r")) == NULL){
        printf("File %s non esistente\n\n",argv[1]);
        return 0;
    }

    // Ciclo lettura-stampa
    do{
        c = fgetc(fptr);
        if(c != EOF){
            printf("%c",c);
        }
    }while(!feof(fptr));

    fclose(fptr);

    return 0;
}