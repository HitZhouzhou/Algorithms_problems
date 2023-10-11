#include<iostream>
#include<queue>
#include<deque>
using namespace std;
int n,k;
const int N =1e6+10; 
int f[N],a[N];
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    deque<int>q1;
    for(int i=1;i<=n;i++)
    {
        if(q1.empty()||a[q1.back()]<a[i])
        {
            q1.push_back(i);
        }
        else
        {
            while(q1.size()&&a[q1.back()]>=a[i])
            {
                q1.pop_back();
            }
            q1.push_back(i);
        }
        if(q1.size()&&i-q1.front()>=k)
        q1.pop_front();
        if(i>=k)
        printf("%d ",a[q1.front()]);
    }
    q1.clear();
    for(int i=1;i<=n;i++)
    {
        if(q1.empty()||a[q1.back()]>a[i])
        {
            q1.push_back(i);
        }
        else
      {
            while(q1.size()&&a[q1.back()]<=a[i])
            {
                q1.pop_back();
            }
            q1.push_back(i);
        }
        if(q1.size()&&i-q1.front()>=k)
        q1.pop_front();
        if(i>=k)
        printf("%d ",a[q1.front()]);
    }
    return 0;
}