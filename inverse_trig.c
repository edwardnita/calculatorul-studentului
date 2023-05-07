#include <stdio.h>
#define TOL 0.0000001
#define MAXITER 100
#define pi 3.141592
#define APROX(x) ((x) + 5 * TOL)

double arcsin(double x, int *imposibil) {
    double S = x, px = x;
    int i;

    // verificare interval
    imposibil = 1;
    if(x < -1 || x > 1) {
        *imposibil = 0;
        return 0;
    }

    for (i = 1; i < MAXITER; i++) {
        px *= x * x * (2 * i - 1)/(i * 2);
        S += px/(2 * i + 1);
        if(px/(2 * i + 1) < TOL && px/(2 * i + 1) > -TOL) 
            return APROX(S);
    }
    return APROX(S);
}

double arccos(double x, int *imposibil) {
    // arcsin + arccos = pi/2
    return APROX(pi /  2 - arcsin(x, imposibil));
}

double arctan(double x) {
    double S = x, px = x;
    int i;
    if(x > 1) {
        return APROX(pi / 2 - arctan(1 / x));
    } else if (x < -1) {
        return APROX(-pi / 2 - arctan(1 / x));
    } else {
        for (i = 0; i < MAXITER; i++) {
            px *= -x*x;
            S += px/(2 * i + 1);
            if(px/(2 * i + 1) < TOL && px/(2 * i + 1) > -TOL) 
                return APROX(S);
        }
        return APROX(S);
    }
}

double arccot(double x) {
    if (x > 1) {
        return APROX(arctan(1 / x));
    } else if (x < -1) {
        return APROX(pi + arctan(1 / x));
    } else {
        return APROX(pi / 2 - arctan(x));
    }
}