//NOT ACCEPTED!!!
//NOT FINISHED!!!
//NOT WORKING!!!
#include <stdio.h>
#define N 1250003
typedef unsigned char bitword;
bitword array[N];
void bitsetZero(bitword *arr, int num) {
    int len = (num / 8) + 2;
    for (int i = 0; i < len; ++i) {
        arr[i] = 0;
    }

}
int bitsetGet(const bitword *arr, int idx) {
    int word = idx / 8;
    bitword slovo = arr[word];
    unsigned int num = idx % 8;
    int bit = (slovo >> num) & 1;
    return bit;
}
void bitsetSet(bitword *arr, int idx, int newval) {
    int word = idx / 8;
    unsigned int num = idx % 8;
    if (newval) {
        arr[word] |= (1 << num);
    } else {
        arr[word] &= ~(1 << num);
    }
}
int bitsetAny(const bitword *arr, int left, int right) {
    unsigned int word = left / 8, current = left % 8;
    int end_word = right / 8, end_bit = right % 8;
    while (word < end_word) {
        switch (current) {
            case 10:
                if (arr[word]){
                    return 1;
                } else break;
            case 7:
                if (arr[word] >= 128) {
                    return 1;
                } else break;
            case 6:
                if (arr[word] % 128) {
                    return 1;
                } else break;
            case 5:
                if (arr[word] % 64) {
                    return 1;
                } else break;
            case 4:
                if (arr[word] % 32) {
                    return 1;
                } else break;
            case 3:
                if (arr[word] % 16) {
                    return 1;
                } else break;
            case 2:
                if (arr[word] % 8) {
                    return 1;
                } else break;
            case 1:
                if (arr[word] % 4) {
                    return 1;
                } else break;
            case 0:
                if (arr[word] % 2) {
                    return 1;
                } else break;
            default:
                return 0;
        }
        word++;
        current = (word != end_word) ? 10 : end_bit;
    }
    return 0;
}
int main() {
    FILE *filein = fopen("input.txt", "rt");
    FILE *fileout = fopen("output.txt", "wt");
    int request;
    fscanf(filein, "%d", &request);
    for (int i = 0; i < request; ++i) {
        int oper;
        fscanf(filein, "%d", &oper);
        if (!oper) {
            int num;
            fscanf(filein, "%d", &num);
            bitsetZero(array, num);
        }
        if (oper == 1) {
            int ind, bit;
            fscanf(filein, "%d", &ind);
            bit = bitsetGet(array, ind);
            fprintf(fileout, "%d\n", bit);
        }
        if (oper == 2) {
            int ind, val;
            fscanf(filein, "%d%d", &ind, &val);
            bitsetSet(array, ind, val);
        }
        if (oper == 3) {
            int r, l;
            fscanf(filein, "%d%d", &l, &r);
            int any = bitsetAny(array, l, r);
            if (any) {
                fprintf(fileout, "%s", "some\n");
            } else {
                fprintf(fileout, "%s", "none\n");
            }
        }
    }
    fclose(filein);
    fclose(fileout);
    return 0;
}

