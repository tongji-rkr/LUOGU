#include<iostream>
using namespace std;
int n, r, k;
int ans[20], l, m;

void had(int n)
{
	if (n == 0) return;
	int m = n % r;//mΪ���� 

	if (m < 0) m -= r, n += r;//�������С��0��ת��Ϊ����

	//������ת��Ϊascll�뷽�������ʡ����һ������ 
	if (m >= 10) m = 'A' + m - 10;
	else m += '0';

	had(n / r);

	printf("%c", m);//ע�⣬��Ϊ���Ϊ�����������Ҫд�ڵݹ���棬��Ȼ��˳����� 
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