#include <stdio.h>
#include <stdbool.h>

bool simplizer(int number){
    if (number==2)
        return true;
    if (number==1)
        return false;
    for (int i = 2; i < number; i++) {
        if (number%i==0)
            return false;
    }
    return true;
}

int main() {
    int end=0;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&end);
    for (int i = 2; i <= end; ++i) {
        if (simplizer(i)){
            printf("%d%s",i,"\n");
        }
    }
    return 0;
}
