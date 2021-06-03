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
    int N=0;
    scanf("%d",&N);
    simplizer(N)?printf("YES"):printf("NO");
    return 0;
}

