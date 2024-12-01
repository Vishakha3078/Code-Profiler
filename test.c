#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void compute_ideal_soliton_distribution(double* distribution, int K) {
    int i = 1;
    while (i <= K) {
        if (i == 1) {
            distribution[0] = 1.0 / K; 
        } else {
            distribution[i - 1] = 1.0 / (i * (i - 1));
        }
        i++;
    }
}

void compute_robust_soliton_distribution(double* distribution, int K, double delta) {
    double* tau = (double*)calloc(K, sizeof(double));
    double R = K / log(K / delta);  
    int i = 1;
    while (i <= ceil(R)) {
        tau[i - 1] = R / (i * K);
        i++;
    }
    tau[(int)ceil(R) - 1] += log(R / delta) / K;
    double total = 0.0;
    i = 0;
    while (i < K) {
        distribution[i] += tau[i];
        total += distribution[i];
        i++;
    }
    i = 0;
    while (i < K) {
        distribution[i] /= total;
        i++;
    }
    free(tau);
}

int sample_degree(double* distribution, int K) {
    double cumulative[K];
    cumulative[0] = distribution[0];
    int i = 1;

    while (i < K) {
        cumulative[i] = cumulative[i - 1] + distribution[i];
        i++;
    }

    double r = (double)rand() / RAND_MAX;
    i = 0;
    while (i < K) {
        if (r <= cumulative[i]) {
            return i + 1;
        }
        i++;
    }
    return K;
}
int main() {
    int K = 10;          
    double delta = 0.05;
    double distribution[K];
    int i = 0;
    while (i < K) {
        distribution[i] = 0.0;
        i++;
    }
    compute_ideal_soliton_distribution(distribution, K);
    compute_robust_soliton_distribution(distribution, K, delta);
    i = 0;
    while (i < K) {
        printf("P(%d) = %.6f\n", i + 1, distribution[i]);
        i++;
    }
    srand(time(NULL));
    i = 0;
    while (i < 20) {
        int degree = sample_degree(distribution, K);
        i++;
    }
    return 0;
} 
