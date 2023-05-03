#include <stdio.h>

double addition(double a, double b) {
    return a + b;
}

double subtraction(double a, double b) {
    return a - b;
}

double multiplication(double a, double b) {
    return a * b;
}

double division(double a, double b) {
    return a / b;
}

int modulo(int a, int b) {
    return a % b;
}

int negation(int a) {
    return ~a;
}

int bit_and(int a, int b) {
    return a & b;
}

int bit_or(int a, int b) {
    return a | b;
}

int bit_xor(int a, int b) {
    return a ^ b;
}

// calcularea factorialului cu acumulator
int recurssion(int n, int accumulator) {
    if(n == 0)
        return accumulator;
    else
        return recurssion(n-1, n * accumulator);
}

int factorial(int n) {
    return recurssion(n, 1);
}