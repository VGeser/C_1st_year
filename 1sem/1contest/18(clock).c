#include <stdio.h>

int main() {
    int hours=0;
    int minutes=0;
    int seconds=0;
    int given =0;
    scanf("%d%d%d%d",&hours,&minutes,&seconds,&given);
    int htemp,mintemp,sectemp;
    htemp=given/3600;
    mintemp=(given-htemp*3600)/60;
    sectemp=(given-3600*htemp)-mintemp*60;
    seconds+=sectemp;
    if (seconds>=60){
        minutes++;
        seconds-=60;
    }
    minutes+=mintemp;
    if (minutes>=60){
        hours++;
        minutes-=60;
    }
    hours+=htemp;
    if (hours>=24){
        hours%=24;
    }
    printf("%d%s%d%s%d",hours," ",minutes," ",seconds);
    return 0;
}

