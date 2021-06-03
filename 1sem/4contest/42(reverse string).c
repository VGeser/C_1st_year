#include <stdio.h>
#include <string.h>

void reverse ( char * start , int len ){
    char str[101];
    for (int i = 0; i < len; ++i) {
        str[i]=start[i];
    }
    int j=0;
    for (int i = len-1; i >=0; --i) {
        start[i]=str[j];
        j++;
    }
};
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int N=0;
    char s[101];
    scanf("%d",&N);
    for (int i = 0; i < N; ++i) {
        scanf("%s",s);
        reverse(s,(int) strlen(s));
        printf("%s\n",s);
    }
    return 0;
}

