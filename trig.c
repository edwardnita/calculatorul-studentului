#include <stdio.h>
#define TOL 0.0000001
#define MAXITER 100
#define APROX(x) ((x) + 5 * TOL)
#define CHECK_TOL(x) ((x) < TOL && (x) > -TOL)

double sinus(double x) {
    double px = x, S = x;
    int i;
    for(i = 1; i < MAXITER; i++) {
        px *= -x*x/(2 * i * (2 * i + 1));
        S += px;
        if(CHECK_TOL(px)) 
            return APROX(S);
    }
    return APROX(S);
}

double cosinus(double x) {
    double px = 1, S = 1;
    int i;
    for(i = 1; i < MAXITER; i++) {
        px *= -x*x/((2 * i - 1) * 2 * i);
        S += px;
        if(CHECK_TOL(px))
            return APROX(S);
    }
    return APROX(S);
}

double tangent(double x) {
    return APROX(sinus(x) / cosinus(x));
}

double cotangent(double x) {
    return APROX(cosinus(x) / sinus(x));
}