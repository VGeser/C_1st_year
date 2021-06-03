#define num 20000001
#include <stdio.h>

long data[20000001];

int prime(int x)
{
    if (data[x] != 0 && x != 0 && x != 1)
        return 0;
    else return 1;
}

int main()
{
    int limit, quantity, current, ans;
    for (int i = 0;i < num; i++)
        data[i] = i;
    for (int i = 2; i < 4473; i++)
    {
        if (data[i] != 0)
            for (int j = i * 2; j < num; j += i)
                data[j] = 0;
    }
    scanf("%d%d", &limit, &quantity);
    for (int i = 0; i < quantity; i++)
    {
        scanf("%d", &current);
        ans = prime(current);
        if (ans != 1) printf("%d prime\n", current);
        else printf("%d not\n", current);
    }
    return 0;
}

