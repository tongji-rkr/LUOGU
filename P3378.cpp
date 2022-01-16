#include<iostream>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

int n, op, m, top = 1;
int heap[1000005];

void del()
{
	heap[1] = heap[--top];
	heap[top] = 0;
	int k = 1;
	while (2 * k < top)
	{
		if (heap[2 * k + 1])
		{
			if (heap[k] > min(heap[2 * k], heap[2 * k + 1]))
			{
				if (heap[2 * k] > heap[2 * k + 1])
					swap(heap[k], heap[2 * k + 1]), k = 2 * k + 1;
				else
					swap(heap[k], heap[2 * k]), k = 2 * k;
			}
			else
				break;
		}
		else
		{
			if (heap[k] > heap[2 * k])
				swap(heap[k], heap[2 * k]), k *= 2;
			else
				break;
		}
	}
	return;
}
void insert(int m)
{ 
	heap[top++] = m;
	int k = top - 1;
	while (k > 1 && heap[k] < heap[k / 2])
		swap(heap[k], heap[k / 2]),k /= 2;
	return;
}
int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
	{
		op = read();
		if (op == 1)m = read(), insert(m);
		else if (op == 2)printf("%d\n", heap[1]);
		else del();
	}
	return 0;
}