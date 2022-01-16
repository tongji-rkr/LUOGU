#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

long long a, b, p;

long long quickPower(long long a, long long b)//����a��b�η�
{
	long long ans = 1, base = a;//ansΪ�𰸣�baseΪa^(2^n)
	while (b > 0)//b��һ���仯�Ķ��������������û������
	{
		if (b & 1)//&��λ���㣬b&1��ʾb�ڶ����������һλ�ǲ���1������ǣ�
			ans *= base;//��ans���϶�Ӧ��a^(2^n)

		base *= base;//base�Գˣ���a^(2^n)���a^(2^(n+1))
		b >>= 1;//λ���㣬b����һλ����101���10�������ұߵ�1�Ƶ��ˣ���10010���1001������b�ڶ����������һλ�Ǹոյĵ����ڶ�λ���������b & 1ʳ�ø���
	}
	return ans;
}

long long b, a, p, k, ans = 1, c;

int main()
{
	b = read(), p = read(), k = read();
	a = b; c = p;
	while (p > 0)//������
	{
		if (p % 2 != 0)
			ans = ans * b % k;//���pΪ�������˵�ans����ȥ��Ȼ��ȡģ
		b = b * b % k;//ÿ�����㶼ȡģ
		p = p >> 1;    //��λ�����2�����ܻ��һ��
	}
	ans %= k;//����ǰ�Ĵ����ˡ�������ͻȻ�����д��и�֪���������ϸһ������p = 0ʱû��ȡģ��������仰�Ϳ�����
	printf("%d^%d mod %d=%d", a, c, k, ans);//���
	return 0;
}