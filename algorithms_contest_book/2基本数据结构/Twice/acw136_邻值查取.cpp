#include <iostream>
#include <algorithm>
#include <set>
#include<limits.h>
#include<math.h>
using namespace std;
typedef pair<int, int> PII;
set<PII> s;
int main()
{
    int n;
    int a;
    cin >> n >> a;
    s.insert({a, 1});
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        s.insert({x, i});
        set<PII>::iterator it = s.find({x, i});
        PII ans;
        int dif1=INT_MAX;
        ans.first=INT_MAX;
        if (++it != s.end())
        {
            dif1 = (*it).first - x;
            ans = {dif1, (*it).second};
        }
        it--;
        if (it-- != s.begin() &&(x-(*it).first<ans.first||(x-(*it).first==ans.first&&(*it).second>ans.second)))
        {
            ans={x-(*it).first,(*it).second};  
        }
        cout<<ans.first<<' '<<ans.second<<endl;
    }
    return 0;
}