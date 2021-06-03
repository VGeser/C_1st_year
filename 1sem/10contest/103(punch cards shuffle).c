#include <stdio.h>
#include <stdlib.h>

typedef struct Cycle_Deck_s {
    int *arr;
    int start;
    int end;
    int quantity;
} Cycle_Deck;
int identifier(const char c) {
    if (c >= 48 && c <= 57) {
        return c;
    } else
        switch (c) {
            case 65:
                return 10;
            case 66:
                return 11;
            case 67:
                return 12;
            case 68:
                return 13;
            case 69:
                return 14;
            case 70:
                return 15;
            default:
                return 0;
        }
}
void verbator(int number,int * arr){
    for (int i = 4; i >0; --i) {
        arr[i-1]=(number%2)?1:0;
        number/=2;
    }
}

int main() {
    FILE *filein = fopen("input.txt", "rt");
    FILE *fileout = fopen("output.txt", "wt");
    int num, oper;
    fscanf(filein, "%d%d", &num, &oper);
    Cycle_Deck left = {}, right = {};
    left.arr = malloc((2 * num + 1) * sizeof(int));
    right.arr = malloc((2 * num + 1) * sizeof(int));
    left.start = right.start = num + 1;
    left.end = right.end = 2 * num;
    left.quantity = right.quantity = num;
    int N = 1;
    for (int i = num + 1; i <= 2 * num; ++i) {
        left.arr[i] = N;
        right.arr[i] = -N;
        N++;
    }
    char tab;
    fscanf(filein, "%c", &tab);
    for (int i = 0; i < oper; ++i) {
        int verb [4]={0,0,0,0};
        char temp;
        fscanf(filein, "%c", &temp);
        int t = identifier(temp);
        verbator(t,verb);
        int buf;
        short hasOperation=1;
        if (verb[0]) {
            //right pop
            if (verb[1]) {
                //снизу правой
                if (right.quantity) {
                    buf = right.arr[right.end];
                    right.arr[right.end] = 0;
                    right.end = (right.end - 1 >= 0) ? right.end - 1 : 2 * num;
                    right.quantity--;
                } else hasOperation=0;
            } else {
                //сверху правой
                if (right.quantity) {
                    buf = right.arr[right.start];
                    right.arr[right.start] = 0;
                    right.start = (right.start + 1 > 2 * num) ? 0 : right.start + 1;
                    right.quantity--;
                } else hasOperation=0;
            }
        } else {
            //left pop
            if (verb[1]) {
                //снизу левой
                if (left.quantity) {
                    buf = left.arr[left.end];
                    left.arr[left.end] = 0;
                    left.end = (left.end - 1 >= 0) ? left.end - 1 : 2 * num;
                    left.quantity--;
                } else hasOperation=0;
            } else {
                //сверху левой
                if (left.quantity) {
                    buf = left.arr[left.start];
                    left.arr[left.start] = 0;
                    left.start = (left.start + 1 > 2 * num) ? 0 : left.start + 1;
                    left.quantity--;
                } else hasOperation=0;
            }
        }
        if (!hasOperation)continue;
        if (verb[2]) {
            //push right
            if (verb[3]) {
                //правая снизу
                int tmp=(right.end + 1 <= 2 * num) ? right.end + 1 : 0;
                right.arr[tmp] = buf;
                right.end = tmp;
            } else {
                //правая сверху
                int tmp=(right.start-1<0)?2*num:right.start-1;
                right.arr[tmp]=buf;
                right.start=tmp;
            }right.quantity++;
        } else {
            //push left
            if (verb[3]){
                //левая снизу
                int tmp=(left.end + 1 <= 2 * num) ? left.end + 1 : 0;
                left.arr[tmp] = buf;
                left.end = tmp;
            }else{
                //левая сверху
                int tmp=(left.start-1<0)?2*num:left.start-1;
                left.arr[tmp]=buf;
                left.start=tmp;
            }left.quantity++;
        }
    }
    fprintf(fileout,"%d ",left.quantity);
    int k=left.start;
    for (int i = 0; i < left.quantity; ++i) {
        fprintf(fileout,"%d ",left.arr[k]);
        k=(k+1>2*num)?0:k+1;
    }
    fprintf(fileout,"\n%d ",right.quantity);
    k=right.start;
    for (int i = 0; i < right.quantity; ++i) {
        fprintf(fileout,"%d ",right.arr[k]);
        k=(k+1>2*num)?0:k+1;
    }
    fclose(filein);
    fclose(fileout);
    return 0;
}

