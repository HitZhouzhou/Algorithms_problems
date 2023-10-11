#include<iostream>
#include<stack>
using namespace std;
stack<int>stk;
int main()
{
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        char c=s[i];
        bool flag=false;
        if(c==')'&&stk.size()&&s[stk.top()]=='(')
        stk.pop(),flag=true;
        if(c==']'&&stk.size()&&s[stk.top()]=='[')
        stk.pop(),flag=true;
        if(c=='}'&&stk.size()&&s[stk.top()]=='{')
        stk.pop(),flag=true;
        if(!flag)
        stk.push(i);
        if(stk.size()) 
        ans=max(ans,i-stk.top());
        else ans=max(ans,i+1);
            
    }
    cout<<ans<<endl;
    return 0;
}