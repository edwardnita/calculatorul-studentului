#include <stdio.h>
#define TOL 0.0000001
#define MAXITER 100
#define pi 3.141592
#define APROX(x) ((x) + 5 * TOL * 10)
#define CHECK_TOL(x) ((x) < TOL && (x) > -TOL)

double arcsin(double x, int *imposibil) {
    double S = x, px = x;
    int i;

    // verificare interval
    *imposibil = 1;
    if(x < -1 || x > 1) {
        *imposibil = 0;
        return 0;
    }

    for (i = 1; i < MAXITER; i++) {
        px *= (2*i -1) * 2 * i * x * x/(4 * i * i);
        S += px/(2 * i + 1);
        if(CHECK_TOL(px/(2 * i + 1))) 
            return APROX(S);
    }
    return APROX(S);
}

double arccos(double x, int *imposibil) {
    // arcsin + arccos = pi/2
    return APROX(pi /  2 - arcsin(x, imposibil));
}