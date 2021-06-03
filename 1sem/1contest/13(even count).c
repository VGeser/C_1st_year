#include <stdio.h>

int main() {
    int N=0;
    int sum=0;
    scanf("%d",&N);
    int numbers[N];
    for (int j=0;j<N;j++)
        scanf("%d",&numbers[j]);
    for (int i=0;i<N;i++){
        if (numbers[i]%2==0)
            sum+=numbers[i];
    }
    printf("%d",sum);
    return 0;
}

