#include<iostream>
using namespace std;
int n, l, p, r[20004], ans;

int main() 
{
	cin >> n >> l;
	for (int i = 1; i <= n; i++)
		cin >> p, r[p * 2] = 1;
	for (int i = 1; i < 2 * l; i++) {//ö��λ��
		int pd = 1, s = 0;//pd���Ƿ���У�sΪ���������ŵĳ���
		while (i >= s && i + s <= 2 * l) {//�Ƿ�Խ��
			if (r[i - s] != r[i + s])pd = 0;
			s++;
		}//ö�ٳ���
		ans += pd;
	}
	cout << ans;
	return 0;
}