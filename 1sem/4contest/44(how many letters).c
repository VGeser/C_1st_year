#include <stdio.h>
#include <string.h>
#define N 101
int calcLetters ( char * iStr , int * oLowerCnt , int * oUpperCnt , int * oDigitsCnt ){
    char temp = *iStr;
    int i=0;
    int lowc=0,upc=0,digc=0;
    while (temp){
        temp= *(iStr + i);
        if ((int)temp >= 48 && (int)temp <=57){
            digc++;
        }if ((int)temp >=65 && (int)temp <=90){
            upc++;
        }if ((int)temp >=97 && (int)temp <=122){
            lowc++;
        }
        i++;
    }*oLowerCnt = lowc;
    *oUpperCnt = upc;
    *oDigitsCnt = digc;
    return 0;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int *low_p,*up_p,*dig_p;
    char string[N];
    int low=0,up=0,dig=0;
    int line =1;
    low_p=&low;
    up_p=&up;
    dig_p=&dig;
    char *pointer;
    pointer=gets(string);
    while (pointer){
        calcLetters(pointer,low_p,up_p,dig_p);
        printf("Line %d has %d chars: %d are letters (%d lower, %d upper), %d are digits.\n",line,strlen(string),low+up,low,up,dig);
        line++;
        pointer=gets(string);
    }
    return 0;
}

