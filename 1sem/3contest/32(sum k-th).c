#include <stdio.h>
int numbers[100001];
int sums[100001];

int main(){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int quantity=0;
    scanf("%d",&quantity);
    for (int i = 0; i < quantity; ++i) {
        scanf("%d",&numbers[i]);
    }
    for (int i = 0; i < quantity; ++i) {
        sums[i]=0;
    }
    for (int i = 0; i < quantity; ++i) {
        for (int j = i; j < quantity; j += (i+1)) {
            sums[i]+=numbers[j];
        }
    }
    for (int i = 0; i < quantity; ++i) {
        printf("%d\n",sums[i]);
    }
    return 0;
}

