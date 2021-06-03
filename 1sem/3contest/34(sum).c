#include <stdio.h>
#define N 5001
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int sum=0,index=0,quantity=0,sum1=0;
    scanf("%d",&quantity);
    quantity= (quantity>=0)?quantity:(-quantity);
    int index1=quantity-1;
    int numbers[N];
    for (int i = 0; i < quantity; ++i) {
        scanf("%d",&numbers[i]);
        sum+=numbers[i];
    }
    for (int j = 1; j < quantity; ++j) {
        sum1=numbers[j-1];
        index1=(sum==numbers[j-1])?(j-1):index1;
        for (int i = j; i < quantity; ++i) {
            if (sum1 > sum) {
                sum = sum1;
                index = j - 1;
                index1 = i - 1;
            }
            /*if (sum1 + numbers[i] > sum1) {
                sum1 += numbers[i];
            } else {
                break;
            }*/
            sum1 += numbers[i];
            if (sum1 > sum) {
                sum = sum1;
                index = j-1;
                index1 = i;
            }
        }
    }
    if (numbers[quantity-1]>=sum){
        index=index1=quantity-1;
        sum=numbers[quantity-1];
    }
    if(sum==numbers[0]){
        index1=index=0;
    }
    printf("%d %d %d",index,index1,sum);
    return 0;
}

