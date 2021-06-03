#include <stdio.h>
#include <string.h>
#define N 1002
typedef struct LongNum_s {
    int len ; //сколько цифр в числе
    int arr [3000]; //массив десятичных цифр числа
} LongNum ;
LongNum multiply (LongNum *first, LongNum *second){
    LongNum result;
    result.len=0;
    if((first->len==1 && first->arr[0]==0)|| (second->len==1 && second->arr[0]==0)){
        result.len=1;
        result.arr[0]=0;
        return result;
    }
    int *big,*small;
    int num_big= first->len+second->len,num_small;
    if (first->len>second->len){
        big=&(first->arr[0]);
        small=&(second->arr[0]);
        num_small = second->len;
    } else{
        big=&(second->arr[0]);
        small=&(first->arr[0]);
        num_small = first->len;
    }
    int *temp=&(result.arr[0]);
    for (int i = 0; i < num_small; ++i) {
        for (int k = 0; k < num_big; ++k) {
            if (!temp){
                break;
            }
            temp[k] += (big[k] * small[i]);
            temp[k + 1] += (temp[k]) / 10;
            temp[k] %= 10;
            int j = k + 1;
            while (temp[j] >= 10 && j<=num_big+1) {
                temp[j + 1] += (temp[j]) / 10;
                temp[j] %= 10;
                j++;
            }
        }temp++;
    }
    num_big=first->len+second->len;
    result.len=num_big;
    for (int i = num_big-1; i >=0 ; --i) {
        if(result.arr[i]){
            break;
        }result.len--;
    }
    return result;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    LongNum first_give,second_give,answer;
    first_give.len=second_give.len=answer.len=0;
    for (int i = 0; i < 1000; ++i) {
        first_give.arr[i]=second_give.arr[i]=answer.arr[i]=0;
    }
    char string[N];
    gets(string);
    int j=0;
    for (int i = (int)strlen(string)-1; i >=0;--i) {
        first_give.arr[j]=(int)string[i]-48;
        first_give.len++;
        j++;
    }
    j=0;
    gets(string);
    for (int i = (int)strlen(string)-1; i >=0;--i) {
        second_give.arr[j]=(int)string[i]-48;
        second_give.len++;
        j++;
    }
    answer=multiply(&first_give,&second_give);
    for (int i = answer.len-1; i>=0; --i) {
        printf("%d",answer.arr[i]);
    }
    return 0;
}

