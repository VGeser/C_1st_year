#include <stdio.h>
#define N 100001
long numbers[N]={};
int binSearch(int lefti, int rigi, long num, long *subptr) {
    int micro = rigi+lefti;
    int midi=(micro%2)?(micro/2 +1):(micro/2);
    if (numbers[rigi]==numbers[lefti]){
        *subptr=numbers[rigi]-num;
        //*subptr=(*subptr>0)?*subptr:-*subptr;
        return rigi;
    }
    if (rigi-lefti == 1){
        long diffr = numbers[rigi]-num;
        long diffl = num-numbers[lefti];
        if (diffl>diffr){
            *subptr=diffr;
            return rigi;
        } else {
            *subptr=diffl;
            return lefti;
        }
    } else{
        if (numbers[midi]>num){
            return binSearch(lefti, midi, num, subptr);
        } else
            return binSearch(midi, rigi, num, subptr);
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
        long sub=0;
        int answ = binSearch(0, len - 1, query, &sub);
        sub=(sub>=0)?sub:(-sub);
        printf("%d %ld\n",answ,sub);
        scanf("%ld",&query);
        //query+=answ;
    }
    return 0;
}

