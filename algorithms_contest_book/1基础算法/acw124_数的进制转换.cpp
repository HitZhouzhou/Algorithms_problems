#include<iostream>
#include<math.h>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int a,b;
        string line;
        cin>>a>>b>>line;
        vector<int>number;
        for(auto c:line)
        {
            if(c>='0'&&c<='9')number.push_back(c-'0');
            else if(c>='A'&&c<='Z')number.push_back(c-'A'+10);
            else if(c>='a'&&c<='z')number.push_back(c-'a'+36);
        }
        reverse(number.begin(),number.end());
        vector<int>res;
        while(number.size())
        {
            int t=0;
            for(int i=number.size()-1;i>=0;i--)
            {
                number[i]+=t*a;
                t=number[i]%b;
                number[i]/=b;
            }
            res.push_back(t);
            while(number.size()&&!number.back())number.pop_back();
        }
        reverse(res.begin(),res.end());
        string b_line;
        for(auto x:res)
        {
        
            if(x<=9)b_line+=char(x+'0');
            else if(x<=35)b_line+=char(x-10+'A');
            else b_line+=char(x-36+'a');
        }
        cout<<a<<' '<<line<<endl;
        cout<<b<<' '<<b_line<<endl;
        cout<<endl;
    }
    return 0;
}