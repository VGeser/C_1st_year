//NOT ACCEPTED!!!
//NOT FINISHED!!!
//NOT WORKING!!!
#include <stdio.h>
#define N 300002
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
    int arr[N]={0},num;
    long long sum=0;
    fscanf(file,"%d",&num);
    for (int i = 0; i < num; ++i) {
        fscanf(file,"%d",&arr[i]);
    }
    fclose(file);
    MyQuickSort(arr,0,num-1);
    int ind=num-1;
    long long temp=0;
    for (int i = 0; i < num; ++i) {
        temp=arr[i];
        temp*=ind;
        sum+=temp;
        ind--;
    }
    file=fopen("output.txt","wt");
    fprintf(file,"%lld",sum);
    fclose(file);
    return 0;
}

