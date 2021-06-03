#include <stdio.h>
#include <stdlib.h>

typedef struct uz_s{
    struct uz_s *prev;
    struct uz_s *post;
    int value;
}uzel;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int people, number;
    int size = sizeof(uzel);
    scanf("%d %d", &people, &number);
    uzel *begin = malloc(size);
    begin->post = begin;
    begin->prev = begin;
    begin->value=1;
    for(int i = 2; i <= people; i++){
        uzel *new = malloc(size);
        new->post = begin;
        new->prev = begin->prev;
        begin->prev->post = new;
        begin->prev = new;
        new->value=i;
    }
    number %= people;
    uzel *curr = begin;
    while (curr != curr->post){
        for(int i = 1; i < number; i++)curr=curr->post;
        printf("%d\n", curr->value);
        uzel *prcurr = curr;
        curr = curr->post;
        prcurr->prev->post = prcurr->post;
        prcurr->post->prev = prcurr->prev;
        free(prcurr);
    }
    printf("%d", curr->value);
    return 0;

}
