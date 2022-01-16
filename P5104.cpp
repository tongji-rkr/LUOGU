#include<iostream>
using namespace std;

const int NUM=1e9+7;
typedef long long ll;
ll w,n,k;
ll ans;

ll mi(ll a,ll b)
{
    ll ans=1;
    for(;b;b>>=1,a=a*a%NUM)
        if(b&1) ans=ans*a%NUM;
    return ans;
}
int main()
{
    cin>>w>>n>>k;
    while(w%2==0&&k>0)w/=2,k--;
    k=k%(NUM-1);
    if(k)k=NUM-1-k;
    ans=(w%NUM)*mi(2,k)%NUM;
    cout<<ans<<endl;
    return 0;
}