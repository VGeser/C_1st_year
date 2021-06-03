#include <stdio.h>

#define N 103
int divisors[N], rests[N];

long long nodext(long long a, long long b, long long *x, long long *y) {
    long long nod, x1, y1;
    if (!a) {
        *x = 0, *y = 1;
        return b;
    }
    nod = nodext(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return nod;
}

long long flip(long long a, long long mod) {
    long long k1, k2, div;
    div = nodext(a, mod, &k1, &k2);
    if (div != 1) {
        return -1;
    } else {
        return ((k1 % mod) + mod) % mod;
    }
}

int main() {
    FILE *filein = fopen("input.txt", "rt");
    FILE *fileout = fopen("output.txt", "wt");
    int k;
    long long M = 1, ans = 0;
    fscanf(filein, "%d", &k);
    for (int i = 0; i < k; ++i) {
        fscanf(filein, "%d", &divisors[i]);
        M *= divisors[i];
    }
    for (int i = 0; i < k; ++i) {
        fscanf(filein, "%d", &rests[i]);
    }
    long long Mi, q = 0;
    for (int i = 0; i < k; i++) {
        Mi = M / divisors[i];
        q = flip(Mi, divisors[i]);
        ans = (ans + Mi * ((q * rests[i]) % divisors[i])) % M;
    }
    fprintf(fileout, "%lld", ans);
    fclose(filein);
    fclose(fileout);
    return 0;
}

