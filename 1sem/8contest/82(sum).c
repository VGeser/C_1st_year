#include <stdio.h>
void little_endian(FILE *f,long long *result,unsigned long query){
    for (int i = 0; i < query; ++i) {
        long temp;
        fread(&temp, 1, 4, f);
        *result+=temp;
    }
}
void big_endian(FILE *f,long long *result,unsigned long query){
    query = (query&0x00FF00FF)<<  8 | (query&0xFF00FF00) >>  8;
    query = (query&0x0000FFFF)<< 16 | (query&0xFFFF0000) >> 16;
    for (int i = 0; i < query; ++i) {
        long temp=0,arr[4]={0},c=1;
        for(int j=3;j>=0;j--){
            fread(&arr[j],1,1,f);
            temp+=arr[j]*c;
            c*=16*16;
        }
        temp = (temp&0x00FF00FF)<<  8 | (temp&0xFF00FF00) >>  8;
        temp = (temp&0x0000FFFF)<< 16 | (temp&0xFFFF0000) >> 16;
        *result+=temp;
    }
}
int main(){
    FILE *file = fopen("input.bin","rb");
    short end;
    long long sum=0;
    unsigned long request=0;
    fread(&request, 1, 4, file);
    if (request>10000){
        big_endian(file, &sum,request);
        end=1;
    } else {
        little_endian(file,&sum,request);
        end=0;
    }
    fclose(file);
    file= fopen("output.bin","wb");
    if (end){
        sum = (sum&0x00FF00FF)<<  8 | (sum&0xFF00FF00) >>  8;
        sum = (sum&0x0000FFFF)<< 16 | (sum&0xFFFF0000) >> 16;
    }
    fwrite(&sum,4,1,file);
    fclose(file);
    return 0;
}

