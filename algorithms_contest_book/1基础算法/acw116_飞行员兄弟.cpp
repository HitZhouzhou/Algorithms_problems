#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N =4;
char g[N+1][N+1],backup[N+1][N+1];
int get(int x,int y)
{
    return x*4+y;
}
void turn_one(int x,int y)
{
    if(g[x][y]=='+')
    {
        g[x][y]='-';
    }
    else
    g[x][y]='+';
}
void turn(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        turn_one(x,i);
        turn_one(i,y);
    }
    turn_one(x,y);
}
int main()
{
    for(int i=0;i<4;i++)
    {
        cin>>g[i];
    }
    long long  ans0=0x3f3f3f3f,ans1;
    for(long long op=0;op<1<<N*N;op++)
    {
        int sum=0;
        memcpy(backup,g,sizeof(g));
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if((op>>get(i,j))&1)
                {
                    turn(i,j);
                    sum++;
                }
            }
        }
        bool is_success=true;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(g[i][j]=='+')
                {
                    is_success=false;
                    break;
                }
            }
        }
        if(is_success)
        {
            if(ans0>sum)
            {
                ans0=sum;
                ans1=op;
            }
        }
        memcpy(g,backup,sizeof g);
    }
    cout<<ans0<<endl;
    for(int i=0;i<N*N;i++)
    {
        if((ans1>>i)&1)
        {
            printf("%d %d\n",i/4+1,i%4+1);
        }
    }
    return 0;
}