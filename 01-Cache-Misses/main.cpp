#include <iostream>
#include <math.h>
#include <ctime>
#include "include/matrix_generator.hpp"
using namespace std;

unsigned t0, t1;
#define MAX 1000


double blocked_matrix_multiply(int** A, int** B, int** C, int n, int nro_bloques){
    // b = tamaño de los bloques;
    // n = tamaño de la matriz
    // nro_bloques = numero de bloques que se quiere particionar
    int b = n/nro_bloques; 
    t0=clock();
    for(int ii=1; ii < nro_bloques; ii+=b)
     for(int jj=1; jj < nro_bloques; jj+=b)
      for(int kk=1; kk < nro_bloques; kk+=b)
       for(int i =(ii-1)*b; i<ii*b; i++)
        for(int j=(jj-1)*b; j<jj*b; j++)
         for(int k=(kk-1)*b; k<kk*b; k++)
          C[i][j] += A[i][k] * B[k][j]; 
    t1=clock();
    return (double(t1-t0)/CLOCKS_PER_SEC);
}


    
double matrix_multiply(int** A, int** B, int** C, int n){
    /* Classic Algorithm matrix multiplication */
    t0=clock();
    for( int i=0; i < n; i++){
        for( int j=0; j < n; j++){
            for( int k=0; k < n; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    t1=clock();
    return (double(t1-t0)/CLOCKS_PER_SEC);
}

// void loop(int **A, int *x, int *y, int n){
//     for (int i = 0; i < MAX; i++)
//         for (int j = 0; j < MAX; j++) 
//             y[i] += A[i][j]* x[j];
//     /* Second pair of loops */ 
//     for (int j = 0; j < MAX; j++)
//         for (int i = 0; i < MAX; i++) 
//             y[i] += A[i][j]*x[j];
// }

int main(){
    /* Initialize A and x, assign y = 0 */
    srand (time(NULL));
    /********************************************************
    *   Implementar y comparar los 2-bucles anidados        *
    *   FOR presentados en el cap. 2 del libro, pag. 22     *
    *********************************************************/
    /* First pair of loops */
    // int init = 1000;
    // for(int i = init; i < MAX; i+=init){
    //     llenar_mtr(A,i);
    //     llenar_array(x,y,i);    
    // }

    /************************************************************
    *   Implementar en C/C++ la multiplicación de matrices      *
    *   clásica, la versión de tres bucles anidados y evaluar   *
    *   su desempeño considerando diferentes tamaños de matriz. *
    *************************************************************/
    /*  Initialize B and C nxn matrix  */

    /*CREANDO LOS CASOS DE PRUEBA*/
    int init = 100;
    for (int i = init; i <= MAX; i+=init){
        int **A = create_matrix(i);
        int **B = create_matrix(i);
        int **C = create_matrix(i);
        llenar_mtr(A, i);
        llenar_mtr(B, i);
        empty_mtr(C,i);
        cout<<"Tamano: "<<i<<endl;
        cout<<"\t- Clasico: "<<matrix_multiply(A,B,C,i)<<" s. \n";
        cout<<"\t- En Bloques: "<<blocked_matrix_multiply(A,B,C,i,4)<<" s.\n\n";
    }

    



    /******************************************************************
    *   Implementar la versión por bloques (investigar en internet),  *
    *   seis bloques anidados, evaluar su desempeño y compararlo con  *
    *   la multiplicación de matrices clásica.                        *  
    *******************************************************************/


    // int init = 100;
    // for (int i = init; i <= MAX; i+=init){
    //     int **A = create_matrix(i);
    //     int **B = create_matrix(i);
    //     int **C = create_matrix(i);
    //     llenar_mtr(A, i);
    //     llenar_mtr(B, i);
    //     empty_mtr(C,i);
        
    // }


    return 0;
}