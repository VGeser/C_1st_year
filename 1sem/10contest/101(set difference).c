#include <stdio.h>
#include <stdlib.h>
#define N 200003
typedef struct Record_s{
    int value;
    int occurrence;
}Record;
int comp(const int *i, const int *j) {
    return *i - *j;
}
Record record[N]={0};
int pos_val [N]={0};
int res [N]={0};
int main() {
    FILE *filein = fopen("input.txt", "rt");
    FILE *fileout = fopen("output.txt", "wt");
    int elems=0;
    fscanf(filein, "%d", &elems);
    for (int i = 0; i < elems; ++i) {
        int temp;
        fscanf(filein, "%d", &temp);
        pos_val[i]=temp;
    }
    qsort(pos_val, elems, sizeof(int), (int (*)(const void *, const void *)) comp);
    int k=0;
    for (int i = 0; i < elems; ++i) {
        short isDif=(pos_val[i]==pos_val[i-1])?0:1;
        if (isDif){
            //новая запись
            record[k].value=pos_val[i];
            record[k].occurrence++;
            k++;
        } else
            record[k].occurrence++;
    }
    fscanf(filein, "%d", &elems);
    for (int i = 0; i < elems; ++i) {
        int temp;
        fscanf(filein, "%d", &temp);
        pos_val[i]=temp;
    }
    qsort(pos_val, elems, sizeof(int), (int (*)(const void *, const void *)) comp);
    for (int i = 0; i < elems; ++i) {
        short isDif=(pos_val[i]==pos_val[i-1])?0:1;
        if (isDif){
            //новая запись
            record[k].value=pos_val[i];
            k++;
        }
        record[k].occurrence=-1;
    }
    qsort(record, k, sizeof(Record), (int (*)(const void *, const void *)) comp);
    int count=0;
    int r=0;
    for (int i = 0; i <= k; ++i) {
        short isDif=(record[i].value==record[i-1].value || record[i].value==record[i+1].value)?0:1;
        if (isDif && record[i].occurrence>0){
            count++;
            res[r]=record[i].value;
            r++;
        }
    }
    fprintf(fileout,"%d\n",count);
    for (int i = 0; i < count; ++i) {
        fprintf(fileout,"%d ",res[i]);
    }
    fclose(filein);
    fclose(fileout);
    return 0;
}

