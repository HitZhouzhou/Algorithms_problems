#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef pair<int,int>PII;
const int N =3000;
PII screen[N];
PII sp[N];
int c,l;
bool cmp(PII a,PII b)
{
    return a.first>b.first;
}
int main()
{
    cin>>c>>l;
    for(int i=1;i<=c;i++)
    {
        cin>>sp[i].first>>sp[i].second;
    }
    for(int i=1;i<=l;i++)
    {
        cin>>screen[i].first>>screen[i].second;
    }
    sort(sp+1,sp+c+1,cmp);
    sort(screen+1,screen+l+1,cmp);
    int ans=0;
    for(int i=1;i<=c;i++)
    {
        for(int j=1;j<=l;j++)
        {
            if(sp[i].first<=screen[j].first&&sp[i].second>=screen[j].first&&screen[j].second)
            {
                ans++;
                screen[j].second--;
                break;
            }
        }
    }
    cout<<ans<<endl;

}