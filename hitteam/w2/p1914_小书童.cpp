#include<iostream>
#include<cstring>
using namespace std;
char map[30];
int main()
{
    int x;
    string a;
    cin>>x>>a;
    for(int i=0;i<a.length();i++)
    {
        map[i]=a[i]-'a';
        map[i]=(map[i]+x)%26;
        printf("%c",map[i]+'a');
    }

    return 0;
}