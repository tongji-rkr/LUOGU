#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

#define N 10007
long long n, m, num[100005], cot[2][100005], col;
long long sum[6][100005];
long long ans;

int main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++)num[i] = read();
	for (int i = 1; i <= n; i++)
	{
		col = read();
		int t = (i % 2) * 3;
		ans = (ans + sum[t][col] % N + i * sum[t + 1][col] % N + num[i] * sum[t + 2][col] % N + cot[i % 2][col] * i * num[i]) % N;
		sum[t][col] = (sum[t][col] + i * num[i]) % N;
		sum[t + 1][col] = (sum[t + 1][col] + num[i]) % N;
		sum[t + 2][col] = (sum[t + 2][col] + i) % N;
		cot[i % 2][col]++;
	}
	cout << ans % N;
	return 0;
}