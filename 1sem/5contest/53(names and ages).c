#include <stdio.h>
#include <string.h>
#define N 1001
typedef struct Label_s {
    char name [16]; //имя автора (заканчивается нулём)
    int age ; //возраст автора (сколько лет)
} Label ;
typedef struct NameStats_s {
    int cntTotal ; //сколько всего подписей
    int cntLong ; //сколько подписей с именами длиннее 10 букв
} NameStats ;
typedef struct AgeStats_s {
    int cntTotal ; //сколько всего подписей
    int cntAdults ; //сколько подписей взрослых (хотя бы 18 лет)
    int cntKids ; //сколько подписей детей (меньше 14 лет)
} AgeStats ;
void calcStats ( const Label * arr , int cnt , NameStats * oNames , AgeStats * oAges ){
    oNames->cntTotal=cnt;
    oAges->cntTotal=cnt;
    for (int i = 0; i < cnt; ++i) {
        if (strlen((arr+i)->name)>10){
            oNames->cntLong++;
        }
        if ((arr+i)->age >=18){
            oAges->cntAdults++;
        }
        if ((arr+i)->age <14){
            oAges->cntKids++;
        }
    }
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int num=0;
    scanf("%d",&num);
    Label data[N];
    for (int i = 0; i < num; ++i) {
        scanf("%s",data[i].name);
        scanf("%d",&data[i].age);
        char separator [4]="";
        scanf("%s",separator);
    }
    AgeStats ages_st;
    ages_st.cntTotal=0;
    ages_st.cntAdults=0;
    ages_st.cntKids=0;
    NameStats names_st;
    names_st.cntTotal=0;
    names_st.cntLong=0;
    calcStats(&data[0],num,&names_st,&ages_st);
    printf("names: total = %d\n",names_st.cntTotal);
    printf("names: long = %d\n",names_st.cntLong);
    printf("ages: total = %d\n",ages_st.cntTotal);
    printf("ages: adult = %d\n",ages_st.cntAdults);
    printf("ages: kid = %d\n",ages_st.cntKids);
    return 0;
}

