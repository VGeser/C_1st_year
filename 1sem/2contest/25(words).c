#include <stdio.h>
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int number=0;
    char dot = '.';
    char tab = '\n';
    int current1=getchar();
    int current2=getchar();
    if (current1!=(int)dot){
        number++;
    }
    while (current2!=(int)tab || current1!=(int)tab){
        if (current1==(int)tab || current2==(int)tab){
            break;
        }
        //printf("%c%c%c%c",current1,' ',current2,'\n');
        if (current1==(int)dot && current2!=(int)dot){
            number++;
        }
        int temp=current2;
        current1=temp;
        current2=getchar();
    }
    printf("%d",number);
    return 0;
}

