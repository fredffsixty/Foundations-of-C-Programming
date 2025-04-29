#include <stdio.h>

int main() {
    int voto;           // Variabile per memorizzare il voto inserito dall'utente
    int somma = 0;      // Variabile per la somma dei voti
    int conteggio = 0;  // Variabile per contare il numero di voti validi
    float media;        // Variabile per calcolare la media

    printf("Inserisci i voti degli esami (tra 18 e 30, -1 per terminare):\n");

    voto = 0; // Inizializza il voto a 0 per entrare nel ciclo

    while (voto != -1) {    // Ciclo fino a quando l'utente non inserisce il valore sentinella -1
        // Richiesta di input all'utente
        printf("Inserisci un voto: ");
        scanf("%d", &voto);

        // Controllo per verificare che il voto sia valido
        if (voto >= 18 && voto <= 30) {
            somma += voto; // Aggiungi il voto alla somma
            conteggio++; // Incrementa il conteggio dei voti
        } else {
            printf("Voto non valido. Inserisci un valore tra 18 e 30.\n");
        }
    }

    // Calcolo della media se sono stati inseriti voti validi
    if (conteggio > 0) {
        media = (float)somma / conteggio;            // il cast a float è necessario per evitare la divisione intera
        printf("La media dei voti è: %.2f\n", media);
    } else {
        printf("Non sono stati inseriti voti validi.\n");
    }

    return 0;
}