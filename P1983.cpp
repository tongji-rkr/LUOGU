#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int n, m, num, ans;
int s[1005], tuopu[1005][1005], de[1005], tt[1005], top;
bool is[1005], bo[1005];

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

int main()
{
	n = read(), m = read();
	for (int i = 1; i <= m; i++)
	{
		memset(is, 0, sizeof(is));
		num = read();
		for (int i = 1; i <= num; i++)
		{
			s[i] = read();
			is[s[i]] = true;
		}
		for (int i = s[1]+1; i < s[num]; i++)
		{
			if (!is[i])
			{
				for (int k = 1; k <= num; k++)
				{
					if (!tuopu[i][s[k]])
					{
						tuopu[i][s[k]] = 1;
						de[s[k]]++;
					}
				}
			}
		}
	}
	do {
		top = 0;
		for (int i = 1; i <= n; i++)
		{
			if (de[i] == 0 && !bo[i]) 
			{
				tt[++top] = i, bo[i] = true;
			}
		}
		for (int i = 1; i <= top; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (tuopu[tt[i]][j]) 
					tuopu[tt[i]][j] = 0, de[j]--;
			}
		}
		ans++;
	} while (top);
	printf("%d", ans - 1);
	return 0;
}