#include <stdio.h>
#include <string.h>
#define N 1000002
char string[N];
char buf[N];
void Wordator(int* big,int* length,const char * word){
    int i=0;
    while (word[i] &&word[i] != 44 && word[i] != 46 && word[i] != 58 && word[i] != 59){
        if (word[i]>=65 && word[i]<=90){
            (*big)++;
        }
        i++;
        (*length)++;
    }
}
int main(){
    gets(string);
    int i=0;
    while (string[i]){
        int up=0,len=0;
        char test=string[i];
        if (test!=44 && test!=46 && test!=58 && test!=59){
            Wordator(&up,&len,&string[i]);
            strncpy(buf,&string[i],len);
            buf[len]=0;
            printf("%d/%d %s\n",up,len,buf);
            i+=len;
        } else
            i++;
    }
    return 0;
}

