#include <stdio.h>
#include <stdlib.h>
#define N 105
typedef struct List_s{
    int number;
    struct List_s * pointer;
}List;
typedef void (* callback )( int * ctx , int * value );
void sum(int *v1,int *v2){
    *v1=(*v1)+(*v2);
}
void arrayForeach ( int * ctx , callback func , int * arr , int n ){
    for (int i = 0; i < n; ++i) {
        if (arr[i]%2==0){
            func(ctx,&arr[i]);
        }
    }
};
void listForeach ( int * ctx , callback func , List * ptr){
    if (!ptr->pointer){
        if ((ptr->number)%2==0)
            func(ctx,&(ptr->number));
    }
    while (ptr->pointer){
        if ((ptr->number)%2==0){
            func(ctx,&(ptr->number));
        }
        ptr=ptr->pointer;
    }
};
int main(){
    FILE *filein = fopen("input.txt","rt");
    FILE *fileout = fopen("output.txt","wt");
    int array[N]={0};
    int request,size=sizeof(List);
    List *next,list_init;
    fscanf(filein,"%d",&request);
    int temp;
    fscanf(filein,"%d",&temp);
    array[0]=temp;
    if (request==1){
        list_init.number=temp;
        list_init.pointer=NULL;
    } else{
        list_init.number=temp;
        list_init.pointer=malloc(size);
        next=list_init.pointer;
        for (int i = 1; i < request; ++i) {
            fscanf(filein,"%d",&temp);
            array[i]=temp;
            next->number=temp;
            next->pointer=malloc(size);
            next=next->pointer;
            next->pointer=0;
            next->number=-105;
        }
    }
    int answer=0;
    arrayForeach(&answer,&sum,array,request);
    fprintf(fileout,"%d ",answer);
    answer=0;
    listForeach(&answer,&sum,&list_init);
    fprintf(fileout,"%d ",answer);
    fclose(filein);
    fclose(fileout);
    return 0;
}

