#include <stdio.h>

int main(int argc, char *argv[]){

    FILE *infptr, *outfptr; // puntatore a file
    char c;                 // cartattere che viene letto dal file e scritto sullo standard output

    /*
        Gestione argomenti linera di comando. Utilizzo: copia <nome file in> <nome file out>
    */
    if(argc != 3){
        printf("Errore nell'invocazione del programma\nUtilizzo: copia <nome file in> <nome file out>\n\n");
        return 0;
    }
    if((infptr = fopen(argv[1],"r")) == NULL){
        printf("File di ingresso %s non esistente\n\n",argv[1]);
        return 0;
    }

    if((outfptr = fopen(argv[2],"w")) == NULL){
        printf("Il nome %s non è un percorso valido\n\n",argv[2]);
        return 0;
    }

    // Ciclo lettura-scrittura
    do{
        c = fgetc(infptr);
        if(c != EOF){
            fputc(c, outfptr);
        }
    }while(!feof(infptr)); // potremmo usare la condizione c != EOF

    /*
        Stesso ciclo con il while

   c = fgetc(infptr);
   while(!feof(infptr)){ // potremmo usare la condizione c != EOF
        fputc(c, outfptr); // a questo punto sono sicuro che non sono a fine file

        c = fgetc(infptr);
   }
    */

    fclose(infptr);
    fclose(outfptr);

    return 0;
}