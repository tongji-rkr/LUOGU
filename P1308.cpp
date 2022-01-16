#include<iostream>
#include<string>
using namespace std;

int main()
{
	string sin, str, total,s;
	cin >> sin;
	cin.get();
	getline(cin,str);
	total = " " + str + " ";
	for (int i = 0; i < sin.length(); i++)
	{
		if (sin[i] >= 'A' && sin[i] <= 'Z')
		{
			sin[i] += 'a' - 'A';
		}
	}
	for (int i = 0; i < total.length(); i++)
	{
		if (total[i] >= 'A' && total[i] <= 'Z')
		{
			total[i] += 'a' - 'A';
		}
	}
	s = " " + sin + " ";
	int len = s.length(), tot_len = total.length();
	int num = 0, firstplace = 0;
	for (int i = 0; i < tot_len-len+1; i++)
	{
		string com(total.substr(i, len));
		if (s == com)
			num++;
		if (firstplace==0&&num == 1)
		{
			firstplace = i;
		}
	}
	if (num)
		cout << num <<" "<< firstplace << endl;
	else
		cout << -1 << endl;
	return 0;
}