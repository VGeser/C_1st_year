#include <stdio.h>
#define N 200003

typedef struct Data_s{
    char value[8];
    struct Data_s *pointer;
} Data;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tests=0;
    scanf("%d",&tests);
    for (int i = 0; i < tests; ++i) {
        Data *ifdelinit = NULL;
        int num,init,oper;
        Data List[N]={0};
        scanf("%d%d%d",&num,&init,&oper);
        for (int j = 0; j < num; ++j) {
            scanf("%s",List[j].value);
            int p=0;
            scanf("%d",&p);
            if (p==(-1)){
                List[j].pointer=NULL;
                continue;
            }
            List[j].pointer= &List[p];
        }
        if (oper){
            int mem=num;
            for (int j = 0; j < oper; ++j) {
                short code;
                scanf("%hd",&code);
                int temp;
                scanf("%d",&temp);
                if (!code){
                    if (temp<0){
                        List[mem].pointer=(init>=0)?&List[init]:ifdelinit;
                        init=mem;
                        scanf("%s",List[mem].value);
                        printf("%d\n",mem);
                        mem++;
                        continue;
                    }
                    //Data *n =List[temp].pointer;
                    //List[temp].pointer=&List[mem];
                    //List[mem].pointer=n;
                    List[mem].pointer=List[temp].pointer;
                    List[temp].pointer=&List[mem];
                    scanf("%s",List[mem].value);
                    printf("%d\n",mem);
                    mem++;
                } else{
                    if (temp<0){
                        if (init>=0) {
                            printf("%s\n", List[init].value);
                            ifdelinit=List[init].pointer;
                            init=-1;
                            continue;
                        }else {
                            printf("%s\n", ifdelinit->value);
                            ifdelinit=ifdelinit->pointer;
                            continue;
                        }
                    }
                    printf("%s\n",List[temp].pointer->value);
                    List[temp].pointer=List[temp].pointer->pointer;
                }
            }
        }
        printf("===\n");
        Data *p=(init>=0)?&List[init]:ifdelinit;
        while (p && (p!=p->pointer)){
            printf("%s\n",p->value);
            if (p->pointer){
                p=p->pointer;
            } else
                break;
        }
        printf("===\n");
    }
    return 0;
}

