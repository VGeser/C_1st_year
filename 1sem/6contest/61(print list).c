#include <stdio.h>
#define N 100000

typedef struct Data_s{
    double value;
    struct Data_s *pointer;
} Data;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    Data List[N]={0};
    int num;
    scanf("%d",&num);
    int init=0;
    scanf("%d",&init);
    for (int i = 0; i < num; ++i) {
        int p=0;
        scanf("%lf%d",&List[i].value,&p);
        if (p==(-1)){
            continue;
        }
        List[i].pointer= &List[p];
    }
    Data *p=0;
    for (int i = 0; i < num; ++i) {
        if (!i){
            printf("%0.3lf\n",List[init].value);
            p=List[init].pointer;
        } else {
            printf("%0.3lf\n",p->value);
            p=p->pointer;
        }
    }
    return 0;
}

