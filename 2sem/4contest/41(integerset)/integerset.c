#include "integerset.h"
#include <stdlib.h>
#include <string.h>

int badsize = 0;
//по сигнатуре в IsInSet нельзя передать size
int intsize = sizeof(int);

int comp(const void *a, const void *b) {
    long long a1 = *((int *) a);
    long long b1 = *((int *) b);
    long long c1 = a1 - b1;
    if (c1 < 0)
        return -1;
    if (c1 > 0)
        return 1;
    return 0;
}

void swap(int *arr, int t1, int t2) {
    int temp = arr[t1];
    arr[t1] = arr[t2];
    arr[t2] = temp;
}

void shuffle(int r, int *arr) {
    for (int i = 0; i < r; ++i) {
        int k = rand() % (i + 1);
        swap(arr, k, i);
    }
}
IntegerSet *CreateSet(int* src, int k){
    IntegerSet *res = calloc(1,sizeof (IntegerSet));
    res->arr = calloc(k,intsize);
    memmove(res->arr, src, k * intsize);
    res->n = k;
    shuffle(k,res->arr);
    qsort(res->arr, k, intsize, comp);
    for (int i = 0; i < k - 1; i++){
        if (res->arr[i] == res->arr[i+1]) return 0;
    }
    return res;
}

int IsInSet(IntegerSet* array, int n){
    if (!array){
        return 0;
    }
    int *res = (int*) bsearch(&n, array->arr, array->n, intsize, comp);
    if (res) {
        return 1;
    }
    return 0;
}
/*IntegerSet *CreateSet(int *array, int size) {
    badsize = size;
    if (!size)return array;
    IntegerSet *res = (int *) malloc(size * intsize);
    memmove(res, array, size * intsize);
    shuffle(size, res);
    qsort(res, size, intsize, comp);
    for (int i = 0; i < size - 1; ++i) {
        if (res[i] == res[i + 1]) {
            return 0;
        }
    }
    return res;
}

char IsInSet(const IntegerSet *intset, int elem) {
    if (!intset)return 0;
    if (elem < intset[0] || elem > intset[badsize - 1])return 0;
    int *res = 0;
    res = (int *) bsearch(&elem, intset, badsize, intsize, comp);
    if (res) {
        return 1;
    } else return 0;
}
 */

