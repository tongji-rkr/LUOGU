#include<iostream>
using namespace std;
int n, l, p, r[20004], ans;

int main() 
{
	cin >> n >> l;
	for (int i = 1; i <= n; i++)
		cin >> p, r[p * 2] = 1;
	for (int i = 1; i < 2 * l; i++) {//枚举位置
		int pd = 1, s = 0;//pd：是否可行，s为向两端扩张的长度
		while (i >= s && i + s <= 2 * l) {//是否越界
			if (r[i - s] != r[i + s])pd = 0;
			s++;
		}//枚举长度
		ans += pd;
	}
	cout << ans;
	return 0;
}