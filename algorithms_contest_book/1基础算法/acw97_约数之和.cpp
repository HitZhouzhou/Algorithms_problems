#include<iostream>
using namespace std;
const int mod=9901;
int qmi(int a,int k)
{
    a%=mod;
    int res=1;
    while(k)
    {
        if(k&1)res=res*a%mod;
        a=a*a%mod;
        k>>=1;
    }   
    return res;
}
int sum(int p,int k)
{
    if(k==0)return 1;
    if(k%2==0)return (1+qmi(p,k/2)%mod)*sum(p,k/2-1)%mod+qmi(p,k)%mod;
    return sum(p,(k-1)/2)%mod*(1+qmi(p,(k+1)/2))%mod;
}
int main()
{
    int A,B;
    cin>>A>>B;
    int res=1;
    for(int i=2;i<=A;i++)
    {
        int s=0;
        while(A%i==0)
        {
            s++;
            A/=i;
        }
        if(s)res=res*sum(i,s*B)%mod;
    }
    if(!A)res=0;
    cout<<res<<endl;
    return 0;
}