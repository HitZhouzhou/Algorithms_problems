#include <iostream>
#include <cstring>
#include <algorithm>
#include<stack>
using namespace std;
const int N = 1e5;
int a[N];
int main()
{
    int n;
    while(cin>>n,n)
    {
        stack<long long>stk;
        stack<long long>w;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];    
        }
        a[n+1]=0;
        stk.push(0);
        w.push(0);
        long long ans=0;
        for(int i=1;i<=n+1;i++)
        {
            if(a[i]>stk.top())
            {
                stk.push(a[i]);
                w.push(1);
            }
            else
            {
                int width=0;
                while(stk.top()>a[i])
                {
                    width+=w.top();
                    w.pop();
                    ans=max(ans,(long long)width*stk.top());
                    stk.pop();
                }
                stk.push(a[i]);
                w.push(width+1);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
