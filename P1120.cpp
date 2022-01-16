#include<iostream>
#include<algorithm>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

int n, x, r, m, sum;
int length;
int len[70],nex[70];
int use[70], ok;

void dfs(int k, int last, int rest)
{
	int i;
	if (!rest)
	{
		if (k == m)
		{
			ok = 1;
			return;
		}
		for (i = 1; i <= r; i++)
		{
			if (!use[i])break;
		}
		use[i] = 1;
		dfs(k + 1, i, length - len[i]);
		use[i] = 0;
	}
	int l = last + 1, s = r;
	while (l < s)
	{
		int mid = l + (s - l) / 2;
		if (len[mid] <= rest)
			s = mid;
		else
			l = mid + 1;
	}
	for (i = l; i <= r; i++)
	{
		if (!use[i])
		{
			use[i] = 1;
			dfs(k, i, rest - len[i]);
			use[i] = 0;
			if (ok)return;

			if (rest == len[i] || rest == length)return;
			i = nex[i];
			if (i == r)return;
		}
	}
}
int main() 
{
	n = read();
	for (int i = 1; i <= n; i++)
	{
		x = read();
		if (x <= 50)len[++r] = x, sum += x;
	}
	sort(len + 1, len + 1 + r, [](int x1, int x2) { return x1 > x2; });
	nex[r] = r;
	for (int i = r - 1; i >= 1; i--)
	{
		if (len[i] == len[i + 1])nex[i] = nex[i + 1];
		else nex[i] = i;
	}
	for (length = len[1];length <= sum / 2; length++)
	{
		if (sum % length)continue;
		m = sum/length;
		ok = 0;
		use[1] = 1;
		dfs(1, 1, length - len[1]);
		use[1] = 0;
		if (ok) { printf("%d", length); return 0; }
	}
	printf("%d", sum);
    return 0;
}