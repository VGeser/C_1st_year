#include <stdio.h>
#define cap 1000002
int arr1[cap],arr2[cap];
int src[cap];
void partition (int piv,int *len1,int *len2,int n){
    short isRight=0;
    for (int i = 0; i < n; ++i) {
        if (src[i]<piv){
            arr1[*len1]=src[i];
            (*len1)++;
        }
        if (src[i]>piv){
            arr2[*len2]=src[i];
            (*len2)++;
        }
        if (src[i]==piv && isRight){
            arr2[*len2]=src[i];
            (*len2)++;
            isRight=0;
            continue;
        }
        if (src[i]==piv && !isRight){
            arr1[*len1]=src[i];
            (*len1)++;
            isRight=1;
        }
    }
}
int main(){
    FILE *file = fopen("input.bin","rb");
    int pivot,l1=0,l2=0,num;
    fread(&num,1,4,file);
    fread(&pivot,1,4,file);
    //fscanf(file,"%d",&num);
    //fscanf(file,"%d",&pivot);
    for (int i = 0; i < num; ++i) {
        fread(&src[i],1,4,file);
        //fscanf(file,"%d",&src[i]);
    }
    partition(pivot,&l1,&l2,num);
    fclose(file);
    file=fopen("output.bin","wb");
    fwrite(&l1,1,4,file);
    for (int i = 0; i < l1; ++i) {
        fwrite(&arr1[i],1,4,file);
        //fprintf(file,"%d ",arr1[i]);
    }
    for (int i = 0; i < l2; ++i) {
        fwrite(&arr2[i],1,4,file);
        //fprintf(file,"%d ",arr2[i]);
    }
    fclose(file);
    return 0;
}

