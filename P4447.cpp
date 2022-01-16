#include<iostream>
#include<map>
using namespace std;

int n;
map<long long, int> a;

int main()
{
	typedef map<long long, int>::iterator IT;
	IT it,iti;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		long long s;
		cin >> s;
		a[s]++;
	}
	int min = n;
	while (a.size())
	{
		it = a.begin();
		int len = 1;
		(*it).second--;
		long long i = (*it).first+1;
		while(a[i]==1)
		{
			len++;
			a[i++]--;
		}
		while (a[i] >= 2)
		{
			len++;
			a[i++]--;
		}
		if (len < min)
			min = len;
		for (it = a.begin(); it != a.end();)
		{
			if ((*it).second == 0)
				it = a.erase(it);
			else
				it++;
		}
	}
	cout << min << endl;
	return 0;
}