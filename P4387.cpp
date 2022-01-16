#include<iostream>
#include<stack>
using namespace std;

int q;
int n;

stack<int> s;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> q;
	for (int i = 1; i <= q; i++)
	{
		int a[100005], b[100005], sum = 1;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> b[i];
		}
		for (int i = 1; i <= n; i++)
		{
			s.push(a[i]);
			while (s.top() == b[sum])
			{
				s.pop(); sum++;
				if (s.empty())
					break;
			}
		}
		if (s.empty())
			cout << "Yes" << endl;
		else
		{
			cout << "No" << endl;
			while (!s.empty())
				s.pop();
		}
	}
	return 0;
}