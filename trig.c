#include <stdio.h>
#define TOL 0.0000001
#define MAXITER 100

double sinus(double x) {
    double px = x, S = x;
    int i;
    for(i = 1; i < MAXITER; i++) {
        px *= -x*x/(2 * i * (2 * i + 1));
        S += px;
        if(px < TOL && px > -TOL) 
            return S;
    }
    return S;
}

double cosinus(double x) {
    double px = 1, S = 1;
    int i;
    for(i = 1; i < MAXITER; i++) {
        px *= -x*x/((2 * i - 1) * 2 * i);
        S += px;
        if(px < TOL && px > -TOL)
            return S;
    }
    return S;
}

double tangent(double x) {
    return sinus(x) / cosinus(x);
}

double cotangent(double x) {
    return cosinus(x) / sinus(x);
}