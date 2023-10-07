#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1010;
const int M = 1e7;
struct People
{
    int x, y;
};
queue<int> q[N];
queue<int> q0;
int a[M];
int main()
{
    int t;
    int k = 0;
    while (cin >> t, t)
    {
        k++;
        printf("Scenario #%d\n", k);
        for(int i=0;i<N;i++)
        {
            q[i]=queue<int>();
        }
        q0=queue<int>();
        for (int i = 0; i < t; i++)
        {
            int x;
            cin >> x;
            for (int j = 0; j < x; j++)
            {
                int y;
                cin >> y;
                a[y] = i + 1;
            }
        }
        char op[15];
        while (cin >> op, *op != 'S')
        {
            if (*op == 'E')
            {
                int x;
                cin >> x;
                if (q[a[x]].empty())
                {
                    q0.push(a[x]);
                }
                q[a[x]].push(x);
            }
            else if (*op == 'D')
            {
                if (q0.size())
                {
                    int x = q0.front();
                    printf("%d\n", q[x].front());
                    q[x].pop();
                    if (q[x].empty())
                        q0.pop();
                }
            }
            else if (*op == 'S')
            {
                puts("");
                break;
            }
        }
        puts("");
    }
    return 0;
}