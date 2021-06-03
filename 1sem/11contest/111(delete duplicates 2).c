#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define N 1000002
uint32_t hash32 (uint32_t num) {
    num = (num >> 16) ^ num;
    num*= 0x45d9f3b;
    num = (num >> 16) ^ num;
    num*= 0x45d9f3b;
    num = (num >> 16) ^ num;
    return num;
}
typedef struct Record_s{
    unsigned int h;
    int k;
}Record;
typedef struct Queue_s{
    int key;
    struct Queue_s *pointer;
}Queue;
Queue *hash_table[N]={0};
Record possible[N]={};
int main(){
    FILE *filein =fopen("input.bin","rb");//bin
    FILE *fileout =fopen("output.bin","wb");//bin
    unsigned int quantity=0;
    int request,size=sizeof(Queue),cnt=0;
    fread(&request,1,4,filein);
    //fscanf(filein,"%d",&request);
    for (int i = 0; i < request; ++i) {
        int temp;
        fread(&temp,1,4,filein);
        //fscanf(filein,"%d",&temp);
        if (cnt>0 && possible[cnt-1].k==temp)continue;
        possible[cnt].k=temp;
        unsigned int hash = hash32(temp)%N;
        possible[cnt].h=hash;
        cnt++;
        if (!hash_table[hash]){
            quantity++;
            hash_table[hash]=malloc(size);
            hash_table[hash]->key=temp;
            hash_table[hash]->pointer=NULL;
        } else {
            Queue *q=hash_table[hash],*p=q;
            while (q){
                if (q->key==temp)goto n;
                p=(q->pointer)?q->pointer:p;
                q=q->pointer;
            }
            quantity++;
            p->pointer=malloc(size);
            p->pointer->key=temp;
            p->pointer->pointer=NULL;
            n:continue;
        }
    }
    fwrite(&quantity,1,4,fileout);
    for (int i = 0; i < cnt; ++i) {
        Queue *tmp=hash_table[possible[i].h];
        while (tmp){
            if (possible[i].k==tmp->key) {
                fwrite(&possible[i].k,1,4,fileout);
                //fprintf(fileout, "%d ", possible[i].k);
                Queue *t = tmp->pointer;
                free(tmp);
                hash_table[possible[i].h] = t;
                break;
            }
            tmp=tmp->pointer;
        }
    }
    fclose(filein);
    fclose(fileout);
    return 0;
}

