#include <stdio.h>
#include <string.h>
int main() {
    char weekday[4]={};
    int number=0;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    gets(weekday);
    char Mon[] = "Mon";
    char Tue[] = "Tue";
    char Wed[] = "Wed";
    char Thu[] = "Thu";
    char Fri[] = "Fri";
    char Sat[] = "Sat";
    if (strcmp(weekday,Mon)==0) {
        number=1;
    }else if(strcmp(weekday,Tue)==0){
        number=2;
    }else if (strcmp(weekday,Wed)==0){
        number=3;
    }else if (strcmp(weekday,Thu)==0){
        number=4;
    }else if (strcmp(weekday,Fri)==0){
        number=5;
    }else if (strcmp(weekday,Sat)==0){
        number=6;
    } else {
        number=7;
    }
    printf("%d",number);
    return 0;
}


