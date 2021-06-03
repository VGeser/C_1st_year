#define N 100005
long long precount[N];
int inarr[N],nums;
long long Sum ( int l , int r );
int Query ( int l , long long sum){
    int i=l;
    //if (!sum)return l;
    sum-=inarr[l];
    if (sum<0)return l;
    long long st=Sum(l,i);
    while (i<=nums && st<=sum){
        i++;
        st=Sum(l,i);
    }
    return i-1;
}

