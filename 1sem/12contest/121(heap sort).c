#include <stdio.h>

#define N 500003
int heap[N], res[N];

void swap(int *arr, int t1, int t2) {
    int temp = arr[t1];
    arr[t1] = arr[t2];
    arr[t2] = temp;
}

void siftUp(int v, int *arr) {//меньшие вверх
    int f = (v - 1) / 2;
    if (v == 0)return;
    if (arr[v] < arr[f]) {
        swap(arr, v, f);
        siftUp(f, arr);
    }
}

void siftdown1(int i, int len, int *arr) {
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    if (l >= len && r >= len) return;
    if (l < len && r < len) {
        int m;
        (arr[l] < arr[r]) ? (m = l) : (m = r);
        if (arr[m] < arr[i]) {
            swap(arr, i, m);
            siftdown1(m, len, arr);
        }
    }
    else if (l < len && arr[l] < arr[i]) {
        swap(arr, i, l);
        siftdown1(l, len, arr);
    }
}

int b = 0;

int extractMin(int k, int *arr) {
    int ans = arr[0];
    swap(arr, 0, k - 1);
    siftdown1(0,k-1,arr);
    return ans;
}

int main() {
    FILE *filein = fopen("input.bin", "rb");
    FILE *fileout = fopen("output.bin", "wb");
    int request;
    fread(&request, 1, 4, filein);
    for (int i = 0; i < request; ++i) {
        fread(&heap[i], 1, 4, filein);
        siftUp(i, heap);
    }
    for (int i = request; i > 0; --i) {
        res[i] = extractMin(request - b, heap);
        b++;
    }
    for (int i = request; i >0 ; --i) {
        fwrite(&res[i], 1, 4, fileout);
    }
    fclose(filein);
    fclose(fileout);
    return 0;
}

