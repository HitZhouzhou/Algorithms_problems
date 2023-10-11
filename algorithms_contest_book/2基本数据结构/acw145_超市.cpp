#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> PII;
int main()
{
    int n;
    while (cin >> n)
    {
        vector<PII> a;
        while (n--)
        {
            int d, v;
            cin >> v >> d;
            a.push_back(make_pair(d, v));
        }
        sort(a.begin(), a.end());
        priority_queue<int, vector<int>, greater<int> > heap;
        for (int i = 0; i < a.size(); i++)
        {
            heap.push(a[i].second);
            if (a[i].first < heap.size())
                heap.pop();
        }
        int ans = 0;
        while (heap.size())
        {
            ans += heap.top();
            heap.pop();
        }
        cout << ans << endl;
    }
    return 0;
}