#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

int a[10001], b[10001], c[10001], n, m, s[10000001];

int main() {
    scanf("%d %d", &n, &m);//����n,m
    for (int i = 1; i <= n; i++) scanf("%d %d %d", &a[i], &b[i], &c[i]);//����3������
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            s[j + (i - 1) * 100] = a[i] * j * j + b[i] * j + c[i];//����
        }
    }
    sort(s + 1, s + 1 + n * 100);//����
    for (int i = 1; i <= m; i++)
        printf("%d ", s[i]);//���
    return 0;
}