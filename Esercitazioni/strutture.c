#include <stdio.h>
#include <string.h>


typedef struct anag_t
{
    char nome[20],
         cognome[20];
    int eta;
    enum genere {M, F} sesso;
    char indirizzo[80];
} anagrafica;

int main(void){

    anagrafica a, b[5];
    char g;

    printf("dimensioni della struttura: %lu\n",sizeof(a));

    printf("Nome e cognome: ");
    scanf("%s%s",a.nome, a.cognome);

    printf("Età: ");
    scanf("%d",&(a.eta));
    getchar();      /* ripulisco il buffer del newline pendente  */

    printf("Genere ('M' o 'F'): ");
    g = getchar();  /* leggo un solo carattere da standard input */
    
    switch(g){
        case 'M':
        case 'm':
            a.sesso = M;
            break;
        case 'F':
        case 'f':
            a.sesso = F;
            break;
        default:
            printf("Carattere non valido");
            return 0;
    }

    printf("Indirizzo: ");
    strcpy(a.indirizzo,""); /* Inizializzo l'indirizzo con stringa nulla */
    getchar();              /* pulizia del buffer dal newline che segue la specifica del genere */
    g = '\0';
    for(int i = 0; g != '\n'; i++){
        g=getchar();
        if(g != '\n')
            a.indirizzo[i] = g;
    }

    printf("Hai immesso la seguente anagrafica: \n");
    printf("Nome e cognome: %s %s\n",a.nome, a.cognome);
    printf("Età : %d\n",a.eta);
    
    if(a.sesso == M)
        g = 'M';
    else
        g = 'F';
    printf("Sesso: %c",g);

    printf("%c\n",a.sesso);

    printf("Indirizzo: %s\n",a.indirizzo);

    return 0;
}
