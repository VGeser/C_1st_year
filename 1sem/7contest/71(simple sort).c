#include <stdio.h>
#define N 10003
typedef struct Record_s{
    int key;
    char value[8];
}Record;
Record records[N];
int main(){
    FILE *file = fopen("input.txt","rt");
    int request;
    fscanf(file,"%d",&request);
    for (int i = 0; i < request; ++i) {
        fscanf(file,"%d",&records[i].key);
        fscanf(file,"%s",records[i].value);
    }
    for (int i = 0; i < request; ++i) {
        for (int j = 0; j < request; ++j) {
            if (records[i].key>=records[j].key){
                Record temp=records[i];
                records[i]=records[j];
                records[j]=temp;
            }
        }
    }
    fclose(file);
    file=fopen("output.txt","wt");
    for (int i = request-1; i >=0; --i) {
        fprintf(file,"%d %s\n",records[i].key,records[i].value);
    }
    fclose(file);
    return 0;
}

