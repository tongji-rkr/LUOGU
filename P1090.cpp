#include<iostream>
#include<queue>
using namespace std;

priority_queue<int,vector<int>,greater<int> > q;
int n,x;

int main()
{
	long long sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		q.push(x);
	}
	while (q.size() >= 2)
	{
		int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();
		sum += a + b;
		q.push(a + b);
	}
	cout << sum << endl;
	return 0;
}