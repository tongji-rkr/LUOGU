#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int n;
unordered_map<string, int> m;

int main()
{
	char c;
	string name;
	int score;
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> c;
		switch (c - '0')
		{
			case 1:
			{
				cin >> name >> score;
				m[name] = score;
				cout << "OK" << endl;
				break;
			}
			case 2:
			{
				cin >> name;
				if (m[name])
					cout << m[name] << endl;
				else
					cout << "Not found" << endl;
				break;
			}
			case 3:
			{
				cin >> name;
				if (m[name]==0)
					cout << "Not found" << endl;
				else
				{
					m[name] = 0;
					cout << "Deleted successfully" << endl;
				}
				break;
			}
			case 4:
			{
				int num = 0;
				for (const auto& s : m)
				{
					if (s.second != 0)
						num++;
				}
				cout << num << endl;
				break;
			}
		}
	}
	return 0;
}