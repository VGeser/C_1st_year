#include <stdio.h>
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int N=0;
    scanf("%d",&N);
    int times = 0;
    if (N%8==0){
        times=N/8;
    }else if (N%8!=0){
        times=N/8+1;
    }
    int bytegoes =0;
    for (int i = 0; i < times; ++i) {
        int result=0;
        int two_exp=1;
        char one ='1';
        char zero ='0';
        if(N>=8){
            bytegoes=8;
        } else if (N<8){
            bytegoes=N;
        }
        for (int j = 0; j < bytegoes; ++j) {
            int bit=getchar();
            if (bit!=(int)one && bit!=(int)zero){
                bit=getchar();
            }
            if (bit==(int)one){
                result+=two_exp;
            }
            two_exp*=2;
            N--;
        }
        printf("%d%c",result,' ');
    }
    return 0;
}


