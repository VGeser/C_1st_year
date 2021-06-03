#include <stdio.h>
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int first,second,quantity,result=0;
    scanf("%d%d%d",&first,&second,&quantity);
    for (int i = first; i <= second-quantity+1; ++i) {
        for (int d = 1; d <=(second-first)/(quantity-1) ; ++d) {
            if((i+(quantity-1)*d <=second)&& (i+quantity*d > second)){
                result++;
            }
        }

    }
    printf("%d",result);
    return 0;
}

