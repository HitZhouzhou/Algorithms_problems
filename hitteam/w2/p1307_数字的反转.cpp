#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string s;
void revout(int l,int r)
{
    int i=l,j=r;
    while(i<j)
    {
        swap(s[i],s[j]);
        i++,j--;
    }
    i=l;
    while(s[i]=='0')
    i++;
    bool flag=false;
    for(;i<=r;i++)
    {
        flag=true;
        cout<<s[i];
    }
    if(!flag)
    cout<<0;
    cout<<endl;
    return ;
}
int main()
{
    cin >> s;
    int len = s.length();
    if (s[0] == '-')
    {
        cout << '-';
        revout(1, len - 1);
    }
    else
    {
        revout(0,len-1);
    }
    return 0;
}