#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
const int N = 1010;
typedef pair<double,double>Pdd;
Pdd isolates[N];
double pos=-0x3f3f3f3f;
int n,d;
int main()
{
    cin>>n>>d;
    for(int i=0;i<n;i++)
    {
        double x,y;
        if(y>d)
        {
            cout<<-1<<endl;
            return 0;
        }
        cin>>x>>y;
        isolates[i].first=x-sqrt(d*d-y*y);
        isolates[i].second=x+sqrt(d*d-y*y);
    }
    sort(isolates,isolates+n);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(pos<isolates[i].first)
        {
            ans++;
            pos=isolates[i].second;
        }
        else
        {
            pos=min(pos,isolates[i].second);
        }
    }
    
    cout<<ans<<endl;
    return 0;
}