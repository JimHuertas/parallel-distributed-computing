#ifndef _MATRIX_GENERATOR_CPP_
#define _MATRIX_GENERATOR_CPP_

#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

vector<int> vector_ram(int n){
    int random_num;
    vector<int> column;
    for (int i = 0; i < n; i++){
        random_num = rand() % 10000 + 1;
        column.push_back(random_num);
    }

    return column;
}

//return a matrix vector<vector<int>> did it by a nxn (tam) value
vector<vector<int>> matrix_generator(int n){
    srand (time(NULL));

    vector<vector<int>> matr;
    for (int i = 0; i < n; i++){
        vector<int> one_vector = vector_ram(n);
        matr.push_back(one_vector);
    }

    return matr;
}


void print_vector(vector<vector<int>> mtr){
    for(vector<int> i : mtr){
        for(int j : i){
            cout<<j<< "  ";
        }
        cout<<endl;
    }
}

#endif