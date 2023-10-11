#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int p,n,m;
int main()
{
    cin>>p;
    while(p--)
    {
        cin>>n>>m;
        printf("%d %d\n",n,(m+1)/2);
        priority_queue<int>max_heap;
        priority_queue<int,vector<int>,greater<int> >min_heap;
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            int x;
            cin>>x;
            max_heap.push(x);
            if(min_heap.size()&&max_heap.top()>min_heap.top())
            {
                int a=max_heap.top();
                int b=min_heap.top();
                max_heap.pop();
                min_heap.pop();
                max_heap.push(b);
                min_heap.push(a);
            }
            if(max_heap.size()>min_heap.size()+1)
            {
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
            if(i%2==0)
            {
                printf("%d ",max_heap.top());
                if(++cnt%10==0)
                puts("");
            }
        }
        if(cnt%10)
        puts("");
    }
    
    return 0;
}