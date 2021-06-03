#include <stdio.h>

int year_identifier(int yr){
    if ((yr%400==0) || (yr%4==0 && yr%100!=0)){
        return 366;
    } else {
        return 365;
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int month=0,year=0,given=0,days=0;
    long tempdays=0;
    scanf("%d%d%d%d",&days,&month,&year,&given);
    tempdays=given+days;
    while (tempdays>=31){
        if (month>12){
            year++;
            month=1;
        }
        switch (month) {
            case 2:
                if (year_identifier(year)==365){
                    tempdays-=28;
                } else tempdays-=29;
                break;
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                tempdays-=31;
                break;
            default:
                tempdays-=30;
        }
        month++;
    }
    if (month>12){
        year++;
        month=1;
    }
    printf("%ld%c%d%c%d",tempdays,' ',month,' ',year);
    return 0;
}

