#include<iostream>
#include<sstream>
using namespace std;
const char c[3] = { '+','-','*' };
int cnt;
int num[2];
int len=2;
int main()
{
	int flag = 0, n = 0, ans = 0;;
	string s;
	cin >> n;
	while (cin >> s)
	{
		stringstream ss;
		ss << s;
		if (s[0] >= 'a' && s[0] <= 'c')
			flag = s[0] - 'a';
		else
		{
			ss >> num[(cnt++) % 2], len += s.length();
			if (cnt % 2 == 0)
			{
				cout << num[0] << c[flag] << num[1] << "=";
				stringstream ts;
				switch (flag)
				{
				case 0:ans = num[0] + num[1]; break;
				case 1:ans = num[0] - num[1]; break;
				case 2:ans = num[0] * num[1]; break;
				}
				ts << ans;
				len += ts.str().length();
				cout << ans << '\n' << len;
				if (cnt == 2 * n)break;
				cout << endl;
				len = 2;
			}
		}
	}
	return 0;
}