#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DBLEN 6

typedef struct riga{
    char cognome_nome[40];
    char CF[20];
    int eta;
    double paga;
    char reparto[10];
} row;

void print_rows(row *db);

row *reparto(row *db, char *r);

row *eta(row *db, int e);

row *paga(row *db, double p);

int dblen(char *filename){

    FILE *fp = fopen(filename, "r");
    int i;
    char line[200];

    fgets(line, 200, fp); /* skip della linea di titolo */

    for(i=0; !feof(fp); i++)
        fgets(line, 200, fp);
    
    fclose(fp);

    return i;
}

int main(int argc, char *argv[]){

    FILE *fp;
    char filename[30], line[200], *token[5];
    row *database;
    int dbl, k;

    printf("Nome del file: ");
    scanf("%30s",filename);

    dbl = dblen(filename);

    database = calloc((size_t)dbl, sizeof(row));

    fp = fopen(filename,"r");

    fgets(line,200,fp); /* leggo la linea del titolo */

    for(int i = 0; i < dbl; i++){
        fgets(line,200,fp); /* leggo la linea */
        line[strlen(line)-1]='\0'; /* rimuovo il newline a fine stringa */
        token[0] = strtok(line,","); /* avvio la tokenizzazione */
        k = 0;
        while(token[k] != NULL){
            k++;
            token[k] = strtok(NULL,","); /* nuovo passo di tokenizzazione */
        }

        /* inserisco nella riga corrente del database */
        strcpy(database[i].cognome_nome, token[0]);
        strcpy(database[i].CF, token[1]);
        database[i].eta = atoi(token[2]);
        database[i].paga = atof(token[3]);
        strcpy(database[i].reparto, token[4]);
    }

    printf("Nome e Cognome\t\t\tCod. Fisc.\t\tEtà\tPaga\tReparto\n");
    for(int i = 0; i < dbl; i++)
        printf("%-30s\t%16s\t%3d\t%2.2lf\t%s\n",
                                        database[i].cognome_nome,
                                        database[i].CF,
                                        database[i].eta,
                                        database[i].paga,
                                        database[i].reparto);

    fclose(fp);
    
    return 0;
}