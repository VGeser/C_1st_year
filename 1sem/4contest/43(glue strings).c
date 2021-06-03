#include <stdio.h>
#include <string.h>

char * concat(char *pref, char *suff) {
    unsigned int l1 = strlen(pref),l2 = strlen(suff);
    for (int i = 0; i < l2; i++) {
        pref[l1 + i] = suff[i];
    }
    pref[l1 + l2] = '\0';
    return pref + l1 + l2;
}

int main() {
    int N=0;
    char result[1000001],temp[101];
    char *s;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &N);
    scanf("%s", result);
    s = result;
    for (int i = 1; i < N; i++) {
        scanf("%s", temp);
        s = concat(s, temp);
    }
    printf("%s", result);
    return 0;
}
