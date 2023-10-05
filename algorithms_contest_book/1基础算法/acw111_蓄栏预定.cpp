#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
const int N = 5e4 + 100;
pair<PII, int> cows[N];
int n,id[N];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>cows[i].first.first>>cows[i].first.second;
        cows[i].second=i;
    }
    sort(cows,cows+n);
    priority_queue<PII,vector<PII>,greater<PII> >heap;
    for(int i=0;i<n;i++)
    {
        if(heap.empty()||heap.top().first>=cows[i].first.first)
        {
            PII stall = {cows[i].first.second,heap.size()+1};
            id[cows[i].second]=stall.second;
            heap.push(stall);
        }
        else
        {
            PII stall =heap.top();
            stall.first=cows[i].first.second;
            id[cows[i].second]=stall.second;
            heap.pop();
            heap.push(stall);
        }
    }
    cout<<heap.size()<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<id[i]<<endl;
    }
    return 0;
}