#include <stdio.h>
#define N 100001
long numbers[N]={};

int binSearch(int lefti,int rigi,long num){
    int micro = rigi+lefti;
    int midi=(micro%2)?(micro/2 +1):(micro/2);
    if (numbers[rigi]==numbers[lefti]){
        if (num==numbers[rigi]){
            return rigi;
        } else return -1;
    }
    if (rigi-lefti == 1){
        if (numbers[rigi]==num){
            return rigi;
        } else if (numbers[lefti]==num){
            return lefti;
        } else return -1;
    } else{
        if (numbers[midi]>num){
            return binSearch(lefti,midi,num);
        } else
            return binSearch(midi,rigi,num);
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int len=0;
    scanf("%d",&len);
    for (int i = 0; i < len; ++i) {
        scanf("%ld",&numbers[i]);
    }
    int request;
    scanf("%d",&request);
    long query;
    scanf("%ld",&query);
    for (int i = 0; i < request; ++i) {
        int answ = binSearch(0,len-1,query);
        printf("%d\n",answ);
        scanf("%ld",&query);
        query+=answ;
    }
    return 0;
}

