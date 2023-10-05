#include<iostream>
#include<algorithm>
using namespace std;
const int N =1e5+10;
int a[N],n;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    long long ans=0;
    for(int i=1;i<n;i++)
    {
        ans+=max(0,a[i]-a[i-1]);
    }
    cout<<ans<<endl;
    return 0;
}