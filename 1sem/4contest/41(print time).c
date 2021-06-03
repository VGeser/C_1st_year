#include <stdio.h>
void printTime ( int h , int m , int s ){
    printf("%02d:%02d:%02d\n",h,m,s);
};
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int N=0,ho,mi,se;
    scanf("%d",&N);
    for (int i = 0; i < N; ++i) {
        scanf("%d%d%d",&ho,&mi,&se);
        printTime(ho,mi,se);
    }
    return 0;
}
