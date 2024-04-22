#include <stdio.h>

int main(void) {

    int input_status, score, sum = 0;

    printf("Scores\n");
    input_status = scanf("%d", &score); 
    
    while (input_status != EOF) {
        printf("%5d\n", score);
        sum += score;
        input_status = scanf("%d", &score);
    }

    printf("\nSum of exam scores is %d\n", sum);
    return (0);
}