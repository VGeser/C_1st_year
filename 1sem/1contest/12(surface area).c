#include <stdio.h>

int space(int a,int b,int c){
    if (a<=0)
        return -1;
    if (b<=0)
        return -2;
    if (c<=0)
        return -3;
    else return 2*(a*b+b*c+a*c);
}
int main() {
    int width=0;
    int height=0;
    int length=0;
    scanf("%d%d%d",&width,&height,&length);
    printf("%d",space(width,height,length));
    return 0;
}


