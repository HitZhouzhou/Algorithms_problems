#include <iostream>
#include <algorithm>
using namespace std;
const int N = 10;
int a[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        a[i]=i;
    }
    do
    {
        /* code */
        for(int i=1;i<=n;i++)
        cout<<a[i]<<' ';
        cout<<endl;
    } while(next_permutation(a+1,a+n+1));
    
}