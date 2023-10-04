#include<iostream>
#include<algorithm>
using namespace std;
int n;
bool check(int x)
{
    return x*(x+1)/2<n;
}
int main()
{
    cin>>n;
    int l=1,r=n;
    while(l<r)
    {
        int mid=(l+r+1)/2;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    int num=n-l*(l+1)/2;
    int x,y;
    if(l%2==1)
    {
        x=0+num;
        y=l+2-num;
    }
    else
    {
        x=l+2-num;
        y=0+num;
    }
    printf("%d/%d\n",x,y);
    return 0;
}