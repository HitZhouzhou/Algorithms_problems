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
        if (++it != s.end())
        {
            dif1 = abs((*it).first - x);
            ans = {dif1, (*it).second};
        }
        it--;
        if (it-- != s.begin() &&abs((*it).first -x)<dif1||(abs((*it).first-x)==dif1&&(*it).second<ans.second))
        {
            ans={abs((*it).first-x),(*it).second};  
        }
        cout<<ans.first<<' '<<ans.second<<endl;
    }
    return 0;
}