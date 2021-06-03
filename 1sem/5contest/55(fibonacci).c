#include <stdio.h>
#define N 200
typedef struct LongNum_s {
    int len ; //сколько цифр в числе
    int arr [500]; //массив десятичных цифр числа
} LongNum ;
LongNum summator (LongNum *first,LongNum *second){
    LongNum result;
    result.len=0;
    int qual=0;
    if (first->len>second->len){
        qual=first->len;
    }else{
        qual=second->len;
    }
    for (int i = 0; i < qual; ++i) {
        result.arr[i]=0;
        if (i>=first->len){
            first->arr[i]=0;
        }if (i>=second->len){
            second->arr[i]=0;
        }
    }
    for (int i = 0; i < qual; ++i) {
        result.arr[i]+=first->arr[i]+second->arr[i];
        if (result.arr[i]>=10){
            result.arr[i+1]=1;
            result.arr[i]-=10;
            if (i+1==qual){
                result.len++;
            }
        }
        result.len++;
    }
    return result;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    LongNum fibnum[N]={};
    fibnum[1].len=fibnum[0].len=1;
    fibnum[1].arr[0]=fibnum[0].arr[0]=1;
    int n =0;
    scanf("%d",&n);
    for (int i = 2; i < n; ++i) {
        fibnum[i]=summator(&fibnum[i-1],&fibnum[i-2]);
        if (n>200 && i==199){
            fibnum[0]=fibnum[198];
            fibnum[1]=fibnum[199];
            i=1;
            n-=198;
        }
    }
    for (int i = fibnum[n-1].len-1; i>=0; --i) {
        printf("%d",fibnum[n-1].arr[i]);
    }
    return 0;
}

