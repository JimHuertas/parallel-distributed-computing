#include <iostream>
#include "matrix_generator.cpp"
using namespace std;

int main(){
    vector<vector<int >> mtr = matrix_generator(4);
    print_vector(mtr);


    return 0;
}