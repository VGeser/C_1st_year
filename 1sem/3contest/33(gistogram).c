#include <stdio.h>
#define N 100002
int occur[N]={};
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int num,max=-N;
    scanf("%d",&num);
    for (int i = 0; i < num; ++i) {
        int temp;
        scanf("%d",&temp);
        occur[temp]++;
        max=(max>=temp)?max:temp;
    }
    for (int i = 0; i <= max; ++i) {
        if (occur[i])printf("%d: %d\n",i,occur[i]);
    }
    return 0;
}

