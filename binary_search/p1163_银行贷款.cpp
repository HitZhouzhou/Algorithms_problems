#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
double n,m,w,ans;
bool check(double p)
{
    double sum=0;
    double x=1;
    for(int i=0;i<m;i++)
    {
        x/=(1+p);
        sum+=x;
    }
    return sum>=n/w;
}
int main()
{
    cin>>n>>w>>m;
    double l=0,r=4;
    while((r-l)>=0.0001)
    {
        double mid=(l+r)/2;
        if(check(mid))
        l=mid;
        else
        r=mid;
    }
    printf("%.1lf\n",100*l);
    return 0;
}