#include <iostream>
#include <cstring>
#include <string>
#include <map>
using namespace std;
map<string, int> m;
int main()
{
    m["tourist"] = 3858;
    m["ksun48"] = 3679;
    m["Benq"] = 3658;
    m["Um_nik"] = 3648;
    m["apiad"] = 3638;
    m["Stonefeang"] = 3630;
    m["ecnerwala"] = 3613;
    m["mnbvmar"] = 3555;
    m["newbiedmy"] = 3516;
    m["semiexp"] = 3481;
    string s;
    cin >> s;
    cout << m[s];
    return 0;
}