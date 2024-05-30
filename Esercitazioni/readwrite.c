#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ALL_LINES 1000000000    /* Valore convenzionale per indicare che copiamo tutte le linee*/

/* 
PSEUDOCODICE:

1. Leggiamo la linea di comando (readwrite <inputfile> <outputfile> [-n num_linee])
2. Controlliamo:
    - che <inputfile> esiste davvero
    - Se esiste "-n" allora l'ultimo argomento deve essere un numero >= 0
    - il numero degli argomenti è 3 o 5
3. Se i controlli sono ok
    - Apriamo i file
    - Ripeti
        * fgets(<inputfile>)
        * fputs(<outputfile>)
    - Finché (non c'è EOF && non ho raggiunto num_linee)
*/

int main(int argc, char *argv[]){

    FILE *infp, *outfp;                     /* file sorgente e destinazione */

    int l, lines = ALL_LINES;               /* contatore di linea e numero di righe da copiare */

    char line[100];                         /* buffer che contiene la linea corrente */

    /* Variabile booleana che controlla il numero esatto di argomenti e la loro sintassi */
    int arg_error = (argc != 3 && argc != 5) || (argc == 5 && strcmp(argv[3],"-n") != 0);
    
    /* Variabile booleana che controlla la corretta conversione dell'argomento numerico */
    int num_error = (argc == 5 && strcmp(argv[3],"-n") == 0) && (lines = atoi(argv[4])) <= 0;

    if(arg_error || num_error){
        printf("Errore negli argomenti\nSintassi: readwrite <inputfile> <outputfile> [-n num_linee]\n\n");
        return 0;
    }

    /* Controllo che il file sorgente esista */
    if((infp = fopen(argv[1],"r")) == NULL){
        printf("Il file %s non esiste\n\n",argv[1]);
        return 0;
    }

    /* Apro il file di destinazione */
    outfp = fopen(argv[2],"w");

    /* Copio le linee richieste ovvero mi fermo se incontro EOF */
    for(l = 1, fgets(line,100,infp);    /* inizializzo a linea 1 e faccio la prima lettura */
        !feof(infp) && l <= lines;       /* controllo che non ho letto tutte le linee e che non ho incontrato EOF */
        l++, fgets(line,100,infp))      /* Aggiorno il contatore di linea e faccio un'altra lettura */

            fputs(line, outfp);

    /* Si poteva anche scrivere 
    l = 1;
    do {
        fgets(line,100,infp);
        fputs(line, outfp);
        l++;
    }while(!feof(infp) && l <= lines);
    */
    return 0;
}