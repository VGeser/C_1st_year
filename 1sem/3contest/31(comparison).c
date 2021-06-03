#include <stdio.h>
#define N 101
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int numbers[N];
    int quantity=0;
    scanf("%d",&quantity);
    for (int i = 0; i < quantity; ++i) {
        scanf("%d",&numbers[i]);
    }
    for (int i = 0; i < quantity; ++i) {
        int counter=0;
        int reference = numbers[i];
        for (int j = i+1; j < quantity; ++j) {
            if (numbers[j]<reference){
                counter++;
            }
        }
        printf("%d%c",counter,' ');
    }
    return 0;
}

