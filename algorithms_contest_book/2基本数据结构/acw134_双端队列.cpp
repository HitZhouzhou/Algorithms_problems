#include<iostream>
#include<algorithm>
using namespace std;
const int N =2e5+10;
typedef pair<int,int>PII;
PII a[N];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a,a+n);
    int last=-0x3f3f3f3f;
    int dir=-1,cnt=0;
    for(int i=0;i<n;)
    {
        int j=i;
        for(;j<n&&a[j].first==a[i].first;j++);
        int minp=a[i].second,maxp=a[j-1].second;
        if(dir==-1)
        {
            if(maxp<=last)
            {
                last=minp;
            }
            else 
            {
                last=maxp;
                dir=1;
            }
        }
        else if (dir==1)
        {
            if(last<=minp)
            {
                last=maxp;
            }
            else
            {
                last=minp;
                dir=-1;
                cnt++;
            }
        }
        i=j;
    }
    if(!cnt)
    cout<<1<<endl;
    else
    cout<<cnt<<endl;
    return 0;
}