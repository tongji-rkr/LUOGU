#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;

string s;
int main()
{
    cin >> s;
    for (int i=1;i<s.length();i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')s[i] -= 32;
    }
    cout << s;
    return 0;
}