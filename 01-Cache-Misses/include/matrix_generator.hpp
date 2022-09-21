#ifndef _MATRIX_GENERATOR_
#define _MATRIX_GENERATOR_
#include <iostream>


int ** create_matrix(int MAX){
    int **A = new int*[MAX];
    for(int i = 0; i < MAX; i++)
        A[i] = new int[MAX];
    
    return A;
}

template <typename T>
T* create_array(int MAX){
    T *y = new int[MAX];
    return y;
}



void llenar_mtr(int **A, int n){
    for(int i=0; i<n; i++) {    
        for(int j=0; j<n; j++) {
            *(*(A+i)+j) = rand() % 100 +1;
        }
    }
}

void llenar_array(int *x, int *y, int n){
    for(int i=0; i<n; i++) {    
        *(x+i) = rand() % 100 +1;
        *(y+i) = 0;
    }
}


void empty_mtr(int **A, int n){
    for(int i=0; i<n; i++) {    
        for(int j=0; j<n; j++) {
            *(*(A+i)+j) = 0;
        }
    }
}

void print_mtr(int **A, int n){
    for(int i=0; i<n; i++) {    
        for(int j=0; j<n; j++) {
            std::cout<<*(*(A+i)+j)<<"  ";
        }
        std::cout<<std::endl;
    }
}

#endif