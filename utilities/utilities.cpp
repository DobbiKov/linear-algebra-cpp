#include <iostream>

#include "utilities.hpp"

using namespace std;

int max(int num1, int num2){
    if(num1 >= num2)
        return num1;
    return num2;
}

int pgcd(int num1, int num2){
    int n = 1;
    int max_n = max(num1, num2);
    for(int i = 1; i < max_n; i++){
        if(num1 % i == 0 && num2 % i == 0 and i > n){
            n = i;
        }
    }
    return n;
}