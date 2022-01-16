#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
struct fantastic     //�ţ���ʼ������
{
    int len, s[9999];
    fantastic()
    {
        memset(s, 0, sizeof(s));
        len = 1;
    }
    fantastic operator=(const char* num)
    {
        len = strlen(num);
        for (int i = 0; i < len; ++i)
            s[i] = num[len - i - 1] - '0';
        return *this;
    }
    fantastic operator=(const int num)
    {
        char a[9999];
        sprintf(a, "%d", num);
        *this = a;
        return *this;
    }
    fantastic(const int num)
    {
        *this = num;
    }
    fantastic(const char* num)
    {
        *this = num;
    }
    fantastic operator+(const fantastic& a)   //���������� ��+�� ������
    {
        fantastic c;
        c.len = max(len, a.len) + 1;                //�������������Ϥ����ʽģ����
        for (int i = 0, x = 0; i < c.len; ++i)
        {
            c.s[i] = s[i] + a.s[i] + x;
            x = c.s[i] / 10;
            c.s[i] = c.s[i] % 10;
        }
        if (c.s[c.len - 1] == 0)
            --c.len;
        return c;
    }
    fantastic operator * (const fantastic& x)           //Ȼ�������� ��*�� ������
    {
        fantastic c;
        c.len = len + x.len;                 //����������Ϥ����ʽģ��
        for (int i = 0; i < len; ++i)
            for (int j = 0; j < x.len; ++j)
            {
                c.s[i + j] += s[i] * x.s[j];
                c.s[i + j + 1] += c.s[i + j] / 10;
                c.s[i + j] %= 10;
            }
        if (c.s[c.len - 1] == 0)
            --c.len;
        return c;
    }
};
ostream& operator<<(ostream& out, const fantastic& x)   //����һ�����
{
    for (int i = x.len - 1; i >= 0; --i)
        cout << x.s[i];
    return out;
}
istream& operator>>(istream& in, fantastic& x)       //����һ������
{
    char num[9999];
    in >> num;
    x = num;
    return in;
}
int main()         //Ȼ��Ϳ������Ŀ�ʼ��������
{
    int n;
    fantastic ans = 0, num = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        num = num * i;
        ans = ans + num;
    }
    cout << ans << endl;
}                                         //�ǳ��ļ�����