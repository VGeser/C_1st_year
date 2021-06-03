#include <assert.h>
#include "modular.h"

int MOD;

int main() {
    MOD = 13;
    int a = 45;
    a = pnorm(a);
    assert (a == 6);
    int x = pmul(padd(7, psub(2, 3)), 5);
    assert (x == 4);
    int y = pdiv(7, x);
    assert (pmul(x, y) == 7);
    MOD = 2;
    assert (pnorm(5) == 1);
    MOD = 11;
    assert(pdiv(5, 7) == 7);
    MOD = 5;
    assert(pnorm(-3) == 2);
    assert(padd(4, 3) == 2);
    assert(psub(1, 4) == 2);
    MOD = 999999937;
    x = 999999936;
    y = 999999935;
    assert(pmul(x, y) == 2);
    assert(pdiv(x,y)==499999969);
    return 0;
}
