#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;

struct Line{
    int l,r;
    double v;
}a[130010];
int s,p;
int b[505],c[505],fa[505];
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
    ios::sync_with_stdio(false);
    scanf("%d%d",&s,&p);
    for(int i=1;i<=p;i++)
    {
        scanf("%d%d",&b[i],&c[i]);
        fa[i]=i;
    }
    for(int i=1;i<=p;i++)
    {
        for(int j=i+1;j<=p;j++)
        {
            a[++cnt].l=i;
            a[cnt].r=j;
            a[cnt].v=dis(i,j);
        }
    }
    sort(a+1,a+1+cnt,cmp);
    s=p-s;
    double ans=0;
    for(int i=1;i<=cnt,s>0;i++)
    {
        int k1=a[i].l;
        int k2=a[i].r;
        if(find(k1)!=find(k2))
        {
            fa[find(k1)]=find(k2);
            ans=max(ans,a[i].v);
            s--;
        }
    }
    printf("%.2lf",ans);
    return 0;
}