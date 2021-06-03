#include <stdio.h>
#define N 10001
void MyQuickSort(int *numbers, int myleft, int myright)
{
    int piv= numbers[myleft],l_hold = myleft,r_hold = myright;
    while (myleft < myright){
        while ((numbers[myright] >= piv) && (myleft < myright)){
            myright--;
        }
        if (myleft != myright){
            numbers[myleft] = numbers[myright];
            myleft++;
        }
        while ((numbers[myleft] <= piv) && (myleft < myright)) {
            myleft++;
        }
        if (myleft != myright){
            numbers[myright] = numbers[myleft];
            myright--;
        }
    }
    numbers[myleft] = piv;
    piv = myleft;
    myleft = l_hold;
    myright = r_hold;
    if (myleft < piv) {
        MyQuickSort(numbers, myleft, piv - 1);
    }
    if (myright > piv) {
        MyQuickSort(numbers, piv + 1, myright);
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int numbers[N];
    int num=0;
    scanf("%d",&num);
    for (int i = 0; i < N; ++i) {
        numbers[i]=-100001;
    }
    for (int i = 0; i < num; ++i) {
        scanf("%d",&numbers[i]);
    }
    MyQuickSort(numbers, 0, num-1);
    for (int i = 0; i < num; ++i) {
        printf("%d ",numbers[i]);
    }
    return 0;
}

