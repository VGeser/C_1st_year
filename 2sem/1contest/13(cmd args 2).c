#include <stdio.h>
#include <string.h>
char string[102];
int bracket(int start,char *dest){
    int cur=start;
    while (string[cur]!='\"'){
        cur++;
    }strncpy(dest,&string[start],cur-start);
    return cur;
}
int space(int start,char *dest){
    int cur=start;
    while (string[cur] && string[cur]!=' ' &&string[cur]!='\n'){
        cur++;
    }strncpy(dest,&string[start],cur-start);
    return cur;
}
//ситуация когда не разделены пробелом?? мб убрать пров на сущ-е из функ скабки
int main() {
    FILE *filein = fopen("input.txt","rt");
    FILE *fileout =fopen("output.txt","wt");
    fgets(string,102,filein);
    int i=0;
    while (string[i] && string[i]!='\n'){
        if (string[i]=='\"'){
            char buff[102];
            i++;
            int len=bracket(i,buff);
            buff[len-i]=0;
            fprintf(fileout,"[%s]\n",buff);
            i=len+1;
            continue;
        } if (string[i]==' '){
            if (!string[i+1] || string[i+1]=='\n')break;
            if (string[i+1]=='\"' || string[i+1]==' '){
                i++;
            } else {
                char buff[102];
                i++;
                int len=space(i,buff);
                buff[len-i]=0;
                fprintf(fileout,"[%s]\n",buff);
                i=len;
            }
        } else {
            char buff[102];
            int len=space(i,buff);
            buff[len-i]=0;
            fprintf(fileout,"[%s]\n",buff);
            i=len;
        }
    }
    fclose(filein);
    fclose(fileout);
    return 0;
}

