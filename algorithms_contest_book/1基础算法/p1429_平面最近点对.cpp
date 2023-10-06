#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int N = 200010;
const double INF = 1e10;
struct Point
{
    double x, y;
    bool operator<(const Point &W) const
    {
        return x < W.x;
    }
};
Point points[N], temp[N];
double dist(Point a, Point b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}
double dfs(int l, int r)
{
    if (l >= r)
        return INF;
    int mid = (l + r) >> 1;
    double mid_x = points[mid].x;
    double res = min(dfs(l, mid), dfs(mid + 1, r));
    {
        int k = 0, i = l, j = mid + 1;
        while (i <= mid && j <= r)
        {
            if (points[i].y < points[j].y)
                temp[k++] = points[i++];
            else
                temp[k++] = points[j++];
        }
        while (i <= mid)
            temp[k++] = points[i++];
        while (j <= r)
            temp[k++] = points[j++];
        for (int i = l, j = 0; j < k; i++, j++)
            points[i] = temp[j];
    }
    int k = 0;
    for (int i = l; i <= r; i++)
    {
        if (points[i].x >= mid_x - res && points[i].x <= mid_x + res)
        {
            temp[k++] = points[i];
        }
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = i - 1; j >= 0 && temp[i].y - temp[j].y < res; j--)
        {
            res = min(res, dist(temp[i], temp[j]));
        }
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%lf%lf", &points[i].x, &points[i].y);
    }
    random_shuffle(points, points + n);
    sort(points, points +  n);
    printf("%.4lf\n", dfs(0, n-1));
    return 0;
}