#include <stdio.h>
typedef struct LongNum_s {
    int len ; //сколько цифр в числе
    int arr [3000]; //массив десятичных цифр числа
} LongNum ;
LongNum factorial (LongNum *curr,int number){
    LongNum result;
    result.len=0;
    int length=1,temp=number;
    while (temp>=10){
        temp/=10;
        length++;
    }
    length+=curr->len;
    if (number<4){
        length=1;
    }
    if (number>1){
        for (int i = 0; i < length+3; ++i) {
            result.arr[i]=0;
        }
    }
    for (int i = 0; i < length; ++i) {
        result.arr[i]+=(curr->arr[i]*number);
        result.arr[i+1]+=(result.arr[i])/10;
        result.arr[i]%=10;
        int j=i+1;
        while (result.arr[j]>=10){
            result.arr[j+1]+=(result.arr[j])/10;
            result.arr[j]%=10;
            j++;
        }
        result.len++;
    }
    if (!result.arr[length-1]){
        result.len--;
    }
    return result;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    LongNum current_fact;
    current_fact.len=1;
    current_fact.arr[0]=1;
    int n =0;
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        current_fact=factorial(&current_fact,i);
    }
    for (int i = current_fact.len-1; i>=0; --i) {
        printf("%d",current_fact.arr[i]);
    }
    return 0;
}

