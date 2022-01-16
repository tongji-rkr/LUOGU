#include<iostream>
using namespace std;
int n, r, k;
int ans[20], l, m;

void had(int n)
{
	if (n == 0) return;
	int m = n % r;//m为余数 

	if (m < 0) m -= r, n += r;//如果余数小于0，转化为正数

	//将余数转化为ascll码方便输出，省略了一个数组 
	if (m >= 10) m = 'A' + m - 10;
	else m += '0';

	had(n / r);

	printf("%c", m);//注意，因为结果为余数倒序，输出要写在递归后面，不然会顺序输出 
	return;
}

int main()
{
	int i;
	cin >> n >> r;
	cout << n << "=";
	had(n);
	cout << "(base" << r << ")" << endl;
	return 0;
}