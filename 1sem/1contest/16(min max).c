#include <stdio.h>

int main() {
    int N=0;
    scanf("%d",&N);
    int array[N];
    for(int i=0;i<N;i++){
        scanf("%d",&array[i]);
    }
    int nummax,nummin=0;
    int max = -10001;
    int min = 10001;
    for (int i = 0; i < N; ++i) {
        if (array[i]>max){
            max=array[i];
            nummax=i;
        }
        if (array[i]<min){
            min=array[i];
            nummin=i;
        }
    }
    printf("%d%s%d%s",min," ",nummin+1," ");
    printf("%d%s%d%s",max," ",nummax+1," ");
    return 0;
}


