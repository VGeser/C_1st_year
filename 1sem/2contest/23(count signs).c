#include <stdio.h>

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int quantity=0,numpos=0,numneg=0,numzer=0;
    double negative=0,positive=0,zero=0;
    scanf("%d",&quantity);
    int numbers[quantity];
    for (int i = 0; i < quantity; ++i) {
        scanf("%d",&numbers[i]);
    }
    for (int i = 0; i < quantity; ++i) {
        if (numbers[i]>0){
            numpos++;
        }else if (numbers[i]==0){
            numzer++;
        }else {
            numneg++;
        }
    }
    negative=(double) numneg/quantity;
    positive=(double) numpos/quantity;
    zero=(double) numzer/quantity;
    printf("%0.5lf%c%0.5lf%c%0.5lf",negative,' ',zero,' ',positive);
    return 0;
}


