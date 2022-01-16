#include<iostream>
#include<algorithm>
using namespace std;
string s[21];
string t[21];
int n;
bool cmp(string& s1,string& s2)
{
    if (s1.length() != s2.length())
        return s1.length() > s2.length() ? true : false;
    else
        return s1 > s2 ? true : false;
}
int main() 
{
    cin >>n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        t[i] = s[i];
    }
    sort(s + 1, s + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        if (t[i] == s[1])
        {
            cout << i << endl;
            cout << s[1] << endl;
            break;
        }
    }
    return 0;
}