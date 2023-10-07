#include<iostream>
using namespace std;
const int N =1e5+10;
struct Rectangle
{
    int h,w;
}r[N];
ll a[N];
typedef long long ll;
int main()
{
    int n;
    while(cin>>n,n)
    {
        ll ans=0,tt=0;
        a[n+1]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n+1;i++)
        {
            if(a[i]>r[tt].h)
            {
                r[++tt].h=a[i];
                r[tt].w=1;
            }
            else
            {
                int width=0;
                while(r[tt].h>a[i])
                {
                    width+=r[tt].w;
                    ans=max(ans,(ll)width*r[tt--].h);
                }
                r[++tt].h=a[i];
                r[tt].w=width+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}