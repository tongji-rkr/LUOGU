#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;

struct Line{
    int l,r;
    double v;
}a[500010];
int n,k;
int b[1005],c[1005],fa[1005];
double dis(int i,int j)
{
    return sqrt((b[i]-b[j])*(b[i]-b[j])+(c[i]-c[j])*(c[i]-c[j]));
}
bool cmp(Line& l1,Line& l2)
{
    return l1.v<l2.v;
}
int find(int x)
{
    if(fa[x]!=x)fa[x]=find(fa[x]);
    return fa[x];
}
int main()
{
    int cnt=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&b[i],&c[i]);
        fa[i]=i;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            a[++cnt].l=i;
            a[cnt].r=j;
            a[cnt].v=dis(i,j);
        }
    }
    sort(a+1,a+1+cnt,cmp);
    
    double ans=0;
    for(int i=1;i<=cnt,n>=k;i++)
    {
        int k1=a[i].l;
        int k2=a[i].r;
        if(find(k1)!=find(k2))
        {
            fa[find(k1)]=find(k2);
            ans=a[i].v;
            n--;
        }
    }
    printf("%.2lf",ans);
    return 0;
}