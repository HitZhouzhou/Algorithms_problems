#include<iostream>
#include<cstring>
#include<vector>

using namespace std;
int n;
vector<int>step;
int st[25];
void cal(int u)
{
    if(u==n+1)
    {
        for(int i=0;i<step.size();i++)
        printf("%d ",step[i]);
        puts("");
    }
    for(int i=1;i<=n;i++)
    {
        if(!st[i])
        {
            st[i]=1;
            step.push_back(i);
            cal(u+1);
            step.pop_back();
            st[i]=0;
        }
    }

}
int main()
{
    cin>>n;
    cal(1);
    return 0;
}