#include<iostream>
#include<cstring>
using namespace std;

const int maxn=22;
int n,m;
int a[maxn],b[maxn];
bool vis[maxn],f[2020];
int ans;

void cul()
{
    int num=0;
    memset(f,0,sizeof f);
    int t=0;
    f[0]=true;
    for(int i=0;i<n;i++)
    {
        if(vis[i])continue;
        for(int j=t;j>=0;j--)
        {
            if(f[j]&&!f[j+a[i]])
            {
                f[j+a[i]]=true;
                num++;
            }
        }
        t+=a[i];
    }
    ans=max(ans,num);
}
void dfs(int cur,int k)
{
    if(k>m)return;
    if(cur==n)
    {
        if(k==m)cul();
        return;
    }
    dfs(cur+1,k);
    vis[cur]=true;
    dfs(cur+1,k+1);
    vis[cur]=false;
}
int main()
{
    cin>>n>>m;
    memset(vis,false,sizeof vis);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    dfs(0,0);
    cout<<ans;
    return 0;
}