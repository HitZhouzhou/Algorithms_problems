#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e4 + 10;
int  n;
int main()
{
    cin >> n;
    priority_queue<int,vector<int>,greater<int> >heap;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        heap.push(x);
    }
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        int a=heap.top();
        heap.pop();
        int b=heap.top();
        heap.pop();
        heap.push(a+b);
        ans+=(a+b);
    }
    cout<<ans<<endl;
    return 0;
}