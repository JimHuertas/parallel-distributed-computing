#include <iostream>
#include "matrix_generator.cpp"
using namespace std;

#define MAX 4

int main(){
    /* Initialize A and x, assign y = 0 */
    srand (time(NULL));
    double A[MAX][MAX];
    double x[MAX];
    double y[MAX];

    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            A[i][j] = rand() % 10000 + 1;

    for(int i = 0; i < MAX; i++){
        x[i] = rand() % 100 + 1;
        y[i] = 0;
    }

    /********************************************************
    *   Implementar y comparar los 2-bucles anidados        *
    *   FOR presentados en el cap. 2 del libro, pag. 22     *
    *********************************************************/
    /* First pair of loops */
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++) 
            y[i] += A[i][j]* x[j];
    /* Assign y = 0 */
    for(int i = 0; i < MAX; i++)
        y[i] = 0;
    /* Second pair of loops */ 
    for (int j = 0; j < MAX; j++)
        for (int i = 0; i < MAX; i++) 
            y[i] += A[i][j]*x[j];


    /************************************************************
    *   Implementar en C/C++ la multiplicación de matrices      *
    *   clásica, la versión de tres bucles anidados y evaluar   *
    *   su desempeño considerando diferentes tamaños de matriz. *
    *************************************************************/
    /*  Initialize A and B nxn matrix  */

    double B[MAX][MAX];
    double C[MAX][MAX];
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++){
            A[i][j] = rand() % 10000 + 1;
            B[i][j] = rand() % 10000 + 1;
            C[i][j] = 0;
        }

    /* Classic Algorithm matrix multiplication */
    for( int i=0; i < MAX; i++){
        for( int j=0; j < MAX; j++){
            for( int k=0; k < MAX; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
   
    


    return 0;
}