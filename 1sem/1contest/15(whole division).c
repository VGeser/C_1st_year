#include <stdio.h>

int main() {
    int a=0;
    int b=0;
    scanf("%d%d",&a,&b);
    int res1,res2,res4;
    res4=a%b;
    res4=(res4>=0?res4:-res4);
    if (a%b>0){
        res1=a/b;
        res2=(a/b)+1;
    }
    if (a%b<0){
        res1=(a/b)-1;
        res2=a/b;
        res4=b-res4;
    }
    if (a%b==0){
        res1=res2=a/b;
    }

    printf("%d%s%d%s%d%s%d",res1," ",res2," ",a/b," ",res4);
    return 0;
}

