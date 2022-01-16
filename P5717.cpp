#include<iostream>
using namespace std;

int main()
{
	long long int a, b, c, s1, s2, s3;
	cin >> a >> b >> c;
	s1 = a * a + b * b - c * c;
	s2 = a * a - b * b + c * c;
	s3 = -a * a + b * b + c * c;
	if (a + b > c && a + c > b && b + c > a)
	{
		if (s1 == 0 || s2 == 0 || s3 == 0)
			cout << "Right triangle" << endl;
		if (s1 > 0 && s2 > 0 && s3 > 0)
			cout << "Acute triangle" << endl;
		if (s1 < 0 || s2 < 0 || s3 < 0)
			cout << "Obtuse triangle" << endl;
		if (a == b || b == c || c == a)
			cout << "Isosceles triangle" << endl;
		if (a == b && b == c)
			cout << "Equilateral triangle" << endl;
	}
	else
		cout << "Not triangle" << endl;
	return 0;
}