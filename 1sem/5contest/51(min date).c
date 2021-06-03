#include <stdio.h>
#define N 50001
typedef struct DateTime_s {
    int year , month , day ;
    int hours , minutes , seconds ;
} DateTime ;
DateTime min ( const DateTime * arr , int cnt ){
    DateTime result=*(arr);
    for (int i = 1; i < cnt; ++i) {
        if ((arr+i)->year<result.year)
            result = *(arr + i);
        else if ((arr+i)->year==result.year){
            if ((arr+i)->month<result.month)
                result=*(arr+i);
            else if ((arr+i)->month==result.month){
                if ((arr+i)->day<result.day)
                    result=*(arr+i);
                else if ((arr+i)->day==result.day){
                    if ((arr+i)->hours<result.hours)
                        result=*(arr+i);
                    else if ((arr+i)->hours==result.hours){
                        if ((arr+i)->minutes<result.minutes)
                            result=*(arr+i);
                        else if((arr+i)->minutes==result.minutes){
                            if ((arr+i)->seconds<result.seconds)
                                result=*(arr+i);
                        }
                    }
                }
            }
        }
    }
    return result;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int num=0;
    DateTime dates[N];
    scanf("%d",&num);
    for (int i = 0; i < num; ++i) {
        scanf("%d",&dates[i].year);
        scanf("%d",&dates[i].month);
        scanf("%d",&dates[i].day);
        scanf("%d",&dates[i].hours);
        scanf("%d",&dates[i].minutes);
        scanf("%d",&dates[i].seconds);
    }
    DateTime answ = min(&dates[0],num);
    printf("%d %d %d %d %d %d",answ.year,answ.month,answ.day,answ.hours,answ.minutes,answ.seconds);
    return 0;
}

