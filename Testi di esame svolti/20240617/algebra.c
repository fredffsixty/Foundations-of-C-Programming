/*
    Il programma da implementare verrà eseguito da linea di comando come segue:

    algebra <nome_file_csv>

    il file di esempio allegato al compito è algebra.csv e ha la seguente struttura:

    Mat1_rows,Mat1_cols,Mat1_data,Mat2_rows,Mat2_cols,Mat2_data,Op
    3,2,3.0 2.3 4.5 6.7 1.2 5.6,2,3,1.1 3.4 8.9 2.3 7.4 5.6,*
    2,2,3.0 2.3 4.5 6.7,2,2,1.1 3.4 8.9 2.3,+
    3,3,3.0 2.3 4.5 6.7 1.2 5.6 1.4 7.2 4.5,3,3,1.1 3.4 8.9 2.3 7.4 5.6 2.2 3.7 4.6,-

    Il programma dovrà leggere i dati di ogni coppia di matrici da una riga,
    eseguire l'operazione indicata nel campo Op e stampare la matrice risultato

    Tutte le matrici sono del tipo matrix definito appositamente
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Tipo del dato matrice che contiene righe, colonne e dati */
typedef struct mat{
    int rows,
        cols;
    double **data;
} matrix;

/*
    read_mat:   legge i dati di una matrice dal file csv e crea
                l'elemento corrispondente di tipo matrix

*/
matrix read_mat(FILE *file);

/*
    sum:    Esegue la somma delle due matrici passate come argomento
            elemento per elemento e restituisce la matrice risultato

    Siano date A(n,n) e B(n,n), la somma si può fare solo se le dimensioni coincidono

    C(n,n) = A + B in modo tale che c(i,j) = a(i,j) + b(i,j)
*/
matrix sum(matrix m1, matrix m2);

/*
    sub:    Esegue la differenza delle due matrici passate come argomento
            elemento per elemento e restituisce la matrice risultato

    Siano date A(n,n) e B(n,n), la somma si può fare solo se le dimensioni coincidono

    C(n,n) = A - B in modo tale che c(i,j) = a(i,j) - b(i,j)
*/
matrix sub(matrix m1, matrix m2);

/*
    prod:   Esegue il prodotto riga x colonna delle due matrici 
            passate come argomento e restituisce la matrice risultato

    Siano date A(m,n) e B(n,l), la somma si può fare solo se 
                                le colonne di A sono uguali alle righe di B

    C(m,l) = A * B in modo tale che c(i,j) = 𝚺_k a(i,k) * b(k,j)
*/
matrix mult(matrix m1, matrix m2);

int main(int argc, char *argv[]){

    FILE *fp;
    matrix m1, m2, res;
    char operation, header[100];

    /*  Verifichiamo il corretto numero degli argomenti da linea di comando 
        e se il percorso del file sia corretto e inviamo un apposito
        messaggio di errore 
    */
    if(argc != 2){
        printf("Argomenti errati\nalgebra <nome_file_csv>\n");
        return 0;
    }
    else{
        fp = fopen(argv[1],"r");
        if(fp == NULL){
            printf("Il file %s non esiste\n", argv[1]);
            return 0;
        }
    }

    /* Skip della linea di titolo */
    fgets(header,100,fp);

    while(!feof(fp)){
        /* Leggiamo i dati delle due matrici dal file */
        m1 = read_mat(fp);

        m2 = read_mat(fp);

        /* Leggiamo l'operazione da svolgere e concludiamo la linea di lettura */
        fscanf(fp, "%c\n", &operation);

        switch (operation)
        {
        case '+':
            res = sum(m1, m2);
            break;
        case '-':
            res = sub(m1, m2);
            break;
        case '*':
            res = mult(m1, m2);
        }
    
        for(int i = 0;i < res.rows; i ++){
            printf("%s ", i == 0? "[[" : " [");
            for(int j = 0; j < res.cols; j++)
                printf(j == res.cols - 1? "%5.2lf]": "%5.2lf, ",res.data[i][j]);
            printf(i == res.rows - 1 ? "]\n" : "\n");
        }
    }

    return 0;
}

matrix read_mat(FILE *file){

    char data_str[100]="";
    matrix m;
    
    fscanf(file,"%d,%d,",&m.cols,&m.rows);

    m.data = (double **)calloc(m.rows,sizeof(double *));
    for(int i = 0; i < m.rows; i ++){
        m.data[i] = (double *)calloc(m.cols,sizeof(double));
        for(int j = 0; j < m.cols; j ++)
            fscanf(file, "%lf",&(m.data[i][j]));
    }

    fscanf(file, ",");

    return m;
}

matrix sum(matrix m1, matrix m2){

    matrix res;

    res.cols = res.rows = 0;
    res.data = NULL;

    if(m1.rows != m2.rows || m1.cols != m2.cols)
        return res;
    
    res.rows = m1.rows;
    res.cols = m1.cols;

    res.data = (double **)calloc(res.rows,sizeof(double *));
    for(int i = 0; i < res.rows; i ++)
        res.data[i] = (double *)calloc(res.cols,sizeof(double));
    
    for(int i = 0; i < res.rows; i ++)
        for(int j = 0; j < res.cols; j ++)
            res.data[i][j] = m1.data[i][j] + m2.data[i][j];
    
    return res;
}

matrix sub(matrix m1, matrix m2){

    matrix res;

    res.cols = res.rows = 0;
    res.data = NULL;

    if(m1.rows != m2.rows || m1.cols != m2.cols)
        return res;
    
    res.rows = m1.rows;
    res.cols = m1.cols;

    res.data = (double **)calloc(res.rows,sizeof(double *));
    for(int i = 0; i < res.rows; i ++)
        res.data[i] = (double *)calloc(res.cols,sizeof(double));
    
    for(int i = 0; i < res.rows; i ++)
        for(int j = 0; j < res.cols; j ++)
            res.data[i][j] = m1.data[i][j] - m2.data[i][j];
    
    return res;    
}

matrix mult(matrix m1, matrix m2){
    
    matrix res;

    res.cols = res.rows = 0;
    res.data = NULL;

    if(m1.cols != m2.rows)
        return res;
    
    res.rows = m1.rows;
    res.cols = m2.cols;

    res.data = (double **)calloc(res.rows,sizeof(double *));
    for(int i = 0; i < res.rows; i ++)
        res.data[i] = (double *)calloc(res.cols,sizeof(double));
    
    for(int i = 0; i < res.rows; i ++)
        for(int j = 0; j < res.cols; j ++){
            res.data[i][j] = 0.0;
            for(int k = 0; k < m1.cols; k ++)
                res.data[i][j] += m1.data[i][k] * m2.data[k][j];
        }

    return res;
}