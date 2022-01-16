#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main()
{
	vector<int> data;
	vector<int>::iterator it1, it2;
	unordered_map<int, int> data_plus;
	int len,sum=0;
	cin >> len;
	data.resize(len);
	for (int i = 0; i < len; i++)
	{
		cin >> data[i];
	}
	for (it1=data.begin();it1!=data.end();it1++)
	{
		for (it2=it1,it2++;it2!=data.end();it2++)
		{
			++data_plus[*it1 + *it2];
		}
	}
	for (int i : data)
	{
		if (data_plus[i])
			sum++;
	}
	cout << sum << endl;
	return 0;
}