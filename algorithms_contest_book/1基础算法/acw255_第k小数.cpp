#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
int n, m, a[N],b[N];
int quick_sort(int l, int r, int k)
{
    if (l >= r)
        return a[l];
    int mid=(l+r)>>1;
    int x = a[mid];
    int i = l - 1, j = r + 1;
    while (i < j)
    {
        do i++;
        while (a[i] < x);
        do j--;
        while (a[j] > x);
        if (i < j)
            swap(a[i], a[j]);
    }
    //l~j,j+1~r;
    if (j - l + 1 >= k)
    {
        return quick_sort(l, j, k);
    }
    else
    {
        return quick_sort(j + 1, r, k - j - 1 + l);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
    }
    while (m--)
    {
        memcpy(b,a,sizeof b);
        int l, r, k;
        scanf("%d%d%d",&l,&r,&k);
        printf("%d\n", quick_sort(l, r, k));
        memcpy(a,b,sizeof b);
    }
    return 0;
}