#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

int a,b;
int g[505][505];
bool vis[505];
int d[505];
int ans=0x3f3f3f3f;

void dfs(int k,int num,int sum)
{
    if(sum>=ans)return;
    if(num==b)
    {
        ans=min(ans,sum);
        return;
    }
    int nmin=0x3f3f3f3f,j=0;
    for(int i=1;i<=b;i++)
    {
        if(vis[i])continue;
        d[i]=min(d[i],g[k][i]);
        if(nmin>d[i])nmin=d[i],j=i;
    }
    vis[j]=true;
    dfs(j,num+1,sum+d[j]);
}
int main()
{
    int x;
    scanf("%d%d",&a,&b);
    for(int i=1;i<=b;i++)
    {
        for(int j=1;j<=b;j++)
        {
            scanf("%d",&x);
            if((x==0||x>a)&&i!=j)
                g[i][j]=a;
            else
                g[i][j]=x;
        }
    }
    for(int i=1;i<=b;i++)
    {
        memset(d,0x3f,sizeof d);
        memset(vis,false,sizeof vis);
        vis[i]=true;
        dfs(i,1,a);
    }
    printf("%d",ans);
    return 0;
}