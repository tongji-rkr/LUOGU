#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

int fa[1005];


int find(int x)
{
	if (fa[x] != x)
		fa[x] = find(fa[x]);
	return fa[x];
}

int main()
{

	return 0;
}