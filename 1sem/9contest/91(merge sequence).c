#include <stdio.h>
#define N 2000004
#define cap 1000002
int numbers[N];
int arr1[cap],arr2[cap];
void merge ( const int *a , int ak , const int *b , int bk , int * res ){
    int first=a[0],second=b[0];
    int an=0,bn=0,len=ak+bk;
    int i=0;
    while (len) {
        while ((first<second || (second<=first && bn>=bk))&& an<ak ){
            res[i]=first;
            i++;
            an++;
            first=a[an];
            len--;
        }
        while ((second<=first || (first<second && an>=ak))&& bn<bk ){
            res[i]=second;
            i++;
            bn++;
            second=b[bn];
            len--;
        }
    }
}
int main(){
    FILE *file = fopen("input.bin","rb");
    int first,second;
    //fscanf(file,"%d",&first);
    //fscanf(file,"%d",&second);
    fread(&first,1,4,file);
    fread(&second,1,4,file);
    for (int i = 0; i < first; ++i) {
        //fscanf(file,"%d",&arr1[i]);
        fread(&arr1[i],1,4,file);
    }
    for (int i = 0; i < second; ++i) {
        //fscanf(file,"%d",&arr2[i]);
        fread(&arr2[i],1,4,file);
    }
    fclose(file);
    merge(arr1,first,arr2,second,numbers);
    file=fopen("output.bin","wb");
    for (int i = 0; i < first+second; ++i) {
        //fprintf(file,"%d ",numbers[i]);
        fwrite(&numbers[i],1,4,file);
    }
    fclose(file);
    return 0;
}

