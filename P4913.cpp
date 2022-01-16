#include <iostream>
using namespace std;


struct node {
    int left, right;
};
node tree[1000005];

int n, ans;

void dfs(int id, int deep) {
    if (id == 0) return;
    ans = max(ans, deep);
    dfs(tree[id].left, deep + 1);
    dfs(tree[id].right, deep + 1);
}

int main() 
{
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> tree[i].left >> tree[i].right;
    dfs(1, 1);
    cout << ans << endl;
    return 0;
}