#include <string.h>
#include <stdio.h>
#define N 1002
typedef struct File_s{
    char name[22];
    unsigned long long size;
    short isDirectory;
    unsigned long long created;
    unsigned long long modified;
    short isHidden;
}File;
int main(){
    FILE *filein = fopen("input.bin","rb");
    int request;
    fread(&request,1,4,filein);
    unsigned long long create,modify;
    fread(&create,1,8,filein);
    fread(&modify,1,8,filein);
    File files[N]={0};
    int index[N]={0},k=0;
    for (int i = 0; i < request; ++i) {
        File file;
        fread(file.name,1,21,filein);
        fread(&file.size, 1, 8, filein);
        fread(&file.isDirectory,1,1,filein);
        fread(&file.created,1,8,filein);
        fread(&file.modified,1,8,filein);
        fread(&file.isHidden,1,1,filein);
        if(!file.isDirectory && !file.isHidden && file.created>=create && file.modified<=modify){
            files[k]=file;
            index[k]=k;
            k++;
        }
    }
    fclose(filein);
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            if(strcmp(files[index[i]].name,files[index[j]].name)<0){
                int t =index[i];
                index[i]=index[j];
                index[j]=t;
            }
        }
    }
    FILE *fileout = fopen("output.bin","wb");
    for (int i = 0; i < k; ++i) {
        File file =files[index[i]];
        fwrite(file.name,1,21,fileout);
        fwrite(&file.size,1,8,fileout);
        fwrite(&file.isDirectory,1,1,fileout);
        fwrite(&file.created,1,8,fileout);
        fwrite(&file.modified,1,8,fileout);
        fwrite(&file.isHidden,1,1,fileout);
    }
    fclose(fileout);
    return 0;
}

