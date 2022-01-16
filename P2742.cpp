#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<iomanip>
using namespace std;

int n;
struct Node{
    double x,y;
}p[100005],s[100005];
double check(Node& a1,Node& a2,Node& b1,Node& b2)
{
    return (b2.y-b1.y)*(a2.x-a1.x)- (a2.y-a1.y)*(b2.x-b1.x);
}
double dis(Node& a,Node& b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool cmp(Node& a,Node& b)
{
    double tmp=check(p[1],a,p[1],b);
    if(tmp>0)return true;
    else if(tmp==0&&(dis(p[0],a)<dis(p[0],b)))
        return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].x>>p[i].y;
        if(i!=1&&(p[i].y<p[1].y)||(p[i].y==p[1].y&&p[i].x<p[1].x))
        {
            swap(p[i].x,p[1].x);
            swap(p[i].y,p[1].y);
        }
    }
    sort(p+2,p+1+n,cmp);
    s[1]=p[1];
    int cnt=1;
    for(int i=2;i<=n;i++)
    {
        while(cnt>1&&check(s[cnt-1],s[cnt],s[cnt],p[i])<=0)
            cnt--;
        s[++cnt]=p[i];
    }
    s[cnt+1]=p[1];
    double ans=0;
    for(int i=1;i<=cnt;i++)
    {
        ans+=dis(s[i],s[i+1]);
    }
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<ans;
    return 0;
}
