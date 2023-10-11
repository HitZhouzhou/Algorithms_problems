#include<iostream>
#include<algorithm>
using namespace std;
const int N =1e6+10;
int n,ne[N];
char s[N];
int main()
{
    int cnt=1;
    while(cin>>n,n)
    {
        printf("Test case #%d\n",cnt++);
        scanf("%s",s+1);
        for(int i=2,j=0;i<=n;i++)
        {
            while(j&&s[i]!=s[j+1])
            j=ne[j];
            if(s[i]==s[j+1])
            j++;
            ne[i]=j;
        }
        for(int i=2;i<=n;i++)
        {
            int t=i-ne[i];
            if(i>t&&i%t==0)
            {
                printf("%d %d\n",i,i/t);
            }
        }
        puts("");
    }
    return 0;
}