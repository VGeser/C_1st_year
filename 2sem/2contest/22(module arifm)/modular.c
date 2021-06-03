#include "modular.h"

int MOD;

int pnorm(int inp) {
    inp = inp % MOD;
    if (inp % MOD < 0) {
        inp = MOD + inp;
    }
    return inp;
}

int padd(int fir, int sec) {
    fir = pnorm(fir);
    sec = pnorm(sec);
    int ans = pnorm(fir + sec);
    return ans >= 0 ? ans : MOD + ans;
}

int psub(int fir, int sec) {
    fir = pnorm(fir);
    sec = pnorm(sec);
    return pnorm(fir - sec + MOD);
}

int pmul(int fir, int sec) {
    fir = pnorm(fir);
    sec = pnorm(sec);
    int ans = 0;
    if (fir >= (46341) || sec >= (46341)) {
        unsigned long long ans1=fir;
        ans1*=sec;
        ans1%=MOD;
        ans = pnorm((int) ans1);
    } else {
        ans = pnorm(fir * sec);
    }
    return ans >= 0 ? ans : MOD + ans;
}

void nodext(int a, int b, int *x, int *y) {
    if (!a) {
        (*x) = 0;
        (*y) = 1;
        return;
    }
    int x1 = 0, y1 = 0;
    nodext(b % a, a, &x1, &y1);
    (*x) = y1 - (b / a) * x1;
    (*y) = x1;
}

int pdiv(int fir, int sec) {
    int t = 0, t1 = 0;
    nodext(sec, MOD, &t, &t1);
    t = t < 0 ? t + MOD : t;
    return pmul(fir, t);
}


