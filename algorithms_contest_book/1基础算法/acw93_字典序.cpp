#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int n,m;
vector<int>chosen;
void cal(int u,int start)
{
    if(u==m+1) 
    {
        for(int i=0;i<chosen.size();i++)
        {
            printf("%d ",chosen[i]);
        }
        puts("");
    }
    for(int i=start;i<=n;i++)
    {
        chosen.push_back(i);
        cal(u+1,i+1);
        chosen.pop_back();
    }
}
int main()
{
    cin>>n>>m;
    cal(1,1);
    return 0;
}