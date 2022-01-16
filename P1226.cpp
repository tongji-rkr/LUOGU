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

long long quickPower(long long a, long long b)//是求a的b次方
{
	long long ans = 1, base = a;//ans为答案，base为a^(2^n)
	while (b > 0)//b是一个变化的二进制数，如果还没有用完
	{
		if (b & 1)//&是位运算，b&1表示b在二进制下最后一位是不是1，如果是：
			ans *= base;//把ans乘上对应的a^(2^n)

		base *= base;//base自乘，由a^(2^n)变成a^(2^(n+1))
		b >>= 1;//位运算，b右移一位，如101变成10（把最右边的1移掉了），10010变成1001。现在b在二进制下最后一位是刚刚的倒数第二位。结合上面b & 1食用更佳
	}
	return ans;
}

long long b, a, p, k, ans = 1, c;

int main()
{
	b = read(), p = read(), k = read();
	a = b; c = p;
	while (p > 0)//快速幂
	{
		if (p % 2 != 0)
			ans = ans * b % k;//如果p为单数，乘到ans里面去，然后取模
		b = b * b % k;//每次运算都取模
		p = p >> 1;    //用位运算除2，可能会快一点
	}
	ans %= k;//多年前的代码了……今天突然发现有大佬告知代码错误，仔细一看是在p = 0时没有取模，加上这句话就可以了
	printf("%d^%d mod %d=%d", a, c, k, ans);//输出
	return 0;
}