#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e3 + 100;
typedef long long LL;
long long f[N];
int main()
{
    int n;
    cin >> n;
    f[1]=1;
    for(int i=2;i<=n;i++)
    {
        f[i]=1;
        int j=i/2;
        while(j)
        {
            f[i]+=f[j];
            j--;
        }
    }
    cout<<f[n]<<endl;
    return 0;
}