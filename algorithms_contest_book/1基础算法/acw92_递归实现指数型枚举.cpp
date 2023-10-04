#include<iostream>
#include<vector>

using namespace std;
vector<int>chosen;
int n;
void cal(int u)
{
    if(u==n+1)
    {
        for(int i=0;i<chosen.size();i++)
        {
            printf("%d ",chosen[i]);
        }
        puts("");
        return;
    }
    cal(u+1);
    chosen.push_back(u);
    cal(u+1);
    chosen.pop_back();
}
int main()
{
    cin>>n;
    cal(1);
    return 0;
}