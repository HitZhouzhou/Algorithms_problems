#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N =2e4;
int a[N],cnt;
bool isPrime(int x)
{
    for(int i=2;i<=x/i;i++)
    {
        if(x%i==0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    for(int i=2;i<=N;i++)
    {
        if(isPrime(i))
        a[cnt++]=i;
    }
    for(int i=0;i<cnt;i++)
    {
        for(int j=0;j<cnt;j++)
        {
            for(int k=0;k<cnt;k++)
            {
                if(a[i]+a[j]+a[k]==n)
                {
                    cout<<a[i]<<' '<<a[j]<<' '<<a[k]<<' '<<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}