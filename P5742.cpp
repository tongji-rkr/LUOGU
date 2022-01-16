#include<iostream>
#include<vector>
using namespace std;

struct student
{
	int num;
	int score1;
	int score2;
	double score3;
	const int total()
	{
		return score1 + score2;
	}
};
bool judge(student& s)
{
	if (s.score3 >= 80 && s.total() > 140)
		return true;
	else
		return false;
}
int main()
{
	vector<student> data;
	int n;
	cin >> n;
	data.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> data[i].num >> data[i].score1 >> data[i].score2;
		data[i].score3 = 0.7 * data[i].score1 + 0.3 * data[i].score2;
		if (judge(data[i]))
			cout << "Excellent" << endl;
		else
			cout << "Not excellent" << endl;
	}
	return 0;
}