#define N 100005
long long precount[N];
//выполнить подготовку массива: запускается один раз перед запусками Sum
//здесь arr[0..n) –- это массив A из входного файла
void Init ( const int * arr , int n ){
    long long s=arr[0];
    for (int i = 0; i < n; ++i) {
        precount[i]=s;
        s+=arr[i+1];
    }
}
//найти сумму элементов A на отрезке [l..r)
//использует данные, посчитанные функцией Init
long long Sum ( int l , int r ){
    return (r!=l)?precount[r-1]-precount[l]:0;
}

