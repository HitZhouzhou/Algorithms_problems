#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,k;
typedef long long LL;
typedef pair<LL,int>PLI;
int main()
{
    cin>>n>>k;
    priority_queue<PLI,vector<PLI>,greater<PLI> >heap;
    for(int i=0;i<n;i++)
    {
        LL x;
        cin>>x;
        heap.push(make_pair(x,0));
    }
    while((n-1)%(k-1))heap.push(make_pair(0,0)),n++;
    LL ans=0;
    while(heap.size()>1)
    {
        LL new_size=0;
        int depth=0;
        for(int i=0;i<k;i++)
        {
            auto t=heap.top();
            new_size+=t.first;
            depth=max(depth,t.second);
            heap.pop();
        }
        ans+=new_size;
        heap.push(make_pair(new_size,depth+1));
    }
    cout<<ans<<endl<<heap.top().second<<endl;
    return 0;
}