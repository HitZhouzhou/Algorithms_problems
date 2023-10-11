#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include<cstring>
using namespace std;
const int N = 2010;
int a[N], b[N], c[N], m, n;
typedef pair<int, int> PII;
void merge()
{
    priority_queue<PII, vector<PII>, greater<PII> > heap;
    for (int i = 0; i < n; i++)
    {
        heap.push(make_pair(a[0] + b[i], 0));
    }
    for (int i = 0; i < n; i++)
    {
        PII t = heap.top();
        heap.pop();
        int s = t.first, p = t.second;
        heap.push(make_pair(s - a[p] + a[p + 1], p + 1));
        c[i] = s;
    }
    for(int i=0;i<n;i++)
    a[i]=c[i];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        scanf("%d%d", &m, &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &b[j]);
            }
            merge();
        }
        for (int i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
        puts("");
    }
    return 0;
}