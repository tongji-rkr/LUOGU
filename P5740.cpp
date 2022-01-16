#include<iostream>
#include<vector>
using namespace std;

class student
{
private:
	string name;
	int score1;
	int score2;
	int score3;
public:
	int total;
	void print()
	{
		cout << name << ' ' << score1 << ' ' << score2 << ' ' << score3 << endl;
		return;
	}
	void init(string n, int s1, int s2, int s3)
	{
		name = n;
		score1 = s1;
		score2 = s2;
		score3 = s3;
		total = s1 + s2 + s3;
		return;
	}
};
int main()
{
	vector<student> data;
	int num,max=0;
	cin >> num;
	data.resize(num);
	for (int i = 0; i < num; i++)
	{
		string n;
		int s1, s2, s3;
		cin >> n >> s1 >> s2 >> s3;
		data[i].init(n, s1, s2, s3);
		if (data[i].total > max)
			max = data[i].total;
	}
	for (int i = 0; i < num; i++)
	{
		if (data[i].total == max)
		{
			data[i].print();
			break;
		}
	}
	return 0;
}