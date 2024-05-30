#include <stdio.h>

typedef struct person_struct {
    int index;
    char name[20];
    int age;
} person;

int main(void){

    FILE *db;                       /* puntatore a file del database */
    person persons[4], *ptr;        /* vettore dei dati e puntatore al singolo dato */

    /* Calcoliamo esplicitamente la lunghezza del vettore persons per usarla nei cicli for */
    long int len = sizeof(persons)/sizeof(person);

    int i;                          /* contatore sul vettore persons */
    db = fopen("./database.bin","wb");

    for(i = 0, ptr = persons; i < len; ptr += ++i){
        /* leggo il nome e l'età del soggetto */
        printf("Nome ed età: ");
        scanf("%s %d",ptr->name,&(ptr->age));

        /* inserisco l'indice del record */
        ptr->index = i + 1;

        fwrite(ptr,sizeof(person),1,db);
    }

    /*
        Si poteva fare anche così (tutto insieme)
        fwrite(persons,sizeof(person),len,db);
    */

    /* chiudiamo il file e lo riapriamo in lettura */
    fclose(db);
    db = fopen("./database.bin","rb");

    /* Leggiamo il numero di record richiesto */
    printf("Inserisci il numero di record richiesto tra 1 e %ld: ",len);
    scanf("%d", &i);

    /* Ci spostiamo in posizione i-1 */
    fseek(db,(long int)(i-1)*sizeof(person), SEEK_SET);

    /* leggiamo un elemento di tipo person dalla posizione selezionata */
    fread(ptr,sizeof(person),1,db);

    printf("Record n.: %d\n------------------\nNome: %s\nEtà: %d\n\n",ptr->index,ptr->name,ptr->age);

    return 0;
}