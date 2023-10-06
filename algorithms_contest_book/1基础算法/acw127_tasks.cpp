#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
const int N =100010;
typedef long long ll;
int n,m;
typedef pair<int,int>PII;
PII mchs[N],tasks[N];
int main()
{
    while(cin>>n>>m)
    {
        for(int i=0;i<n;i++)
        cin>>mchs[i].first>>mchs[i].second;
        for(int i=0;i<m;i++)
        cin>>tasks[i].first>>tasks[i].second;
        sort(mchs,mchs+n);
        sort(tasks,tasks+m);
        ll cnt=0,ans=0;
        multiset<int>ys;
        for(int i=m-1,j=n-1;i>=0;i--)
        {
            while(j>=0&&mchs[j].first>=tasks[i].first)
            ys.insert(mchs[j--].second);
            auto it=ys.lower_bound(tasks[i].second);
            if(it!=ys.end())
            {
                ans+=tasks[i].first*500+tasks[i].second*2;
                cnt++;
                ys.erase(it);
            }
        }
        cout<<cnt<<' '<<ans<<endl;
    }
    return 0;
}