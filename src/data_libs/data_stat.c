#include "data_stat.h"

double max(double *a, int n) {
    double max = a[0];
    for (int p = 1; p < n; p++) {
        if (a[p] > max) max = a[p];
    }
    return max;
};

double min(double *a, int n) {
    double min = a[0];
    for (int p = 1; p < n; p++) {
        if (a[p] < min) min = a[p];
    }
    return min;
};

double mean(double *a, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return (double)sum / n;
};

double variance(double *a, int n) {
    double sum = 0;
    double m = mean(a, n);
    for (int i = 0; i < n; i++) {
        double t = (double)(a[i] - m);
        sum += t * t;
    }
    return (double)sum / n;
};

