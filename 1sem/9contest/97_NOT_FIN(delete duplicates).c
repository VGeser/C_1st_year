//NOT ACCEPTED!!
//NOT FINISHED!!
//NOT WORKING!!!
#include <stdio.h>
#define N 300002
int arr[N]={0},res[N]={0};
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
    FILE *file = fopen("input.txt","rt");
    int num;
    fscanf(file,"%d",&num);
    for (int i = 0; i < num; ++i) {
        fscanf(file,"%d",&arr[i]);
    }
    MyQuickSort(arr,0,num-1);
    int k=0;
    short hasZero=0;
    if (!arr[0] || !arr[num-1])hasZero=1;
    for (int i = 0; i <= num; ++i) {
        if (arr[i]!=arr[i-1]){
            res[k]=arr[i];
            k++;
        }
    }
    k=(hasZero)?k:k-1;
    fclose(file);
    file=fopen("output.txt","wt");
    fprintf(file,"%d\n",k);
    for (int i = 0; i < k; ++i) {
        fprintf(file,"%d\n",res[i]);
    }
    fclose(file);
    return 0;
}

