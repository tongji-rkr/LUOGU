#include<iostream>
using namespace std;

const int N=100003;
int n,k;
pair<int,int> m;
int a[100005];

int main()
{
    cin>>n>>k;
    m.first=1;
    a[0]=1;
    for(int i=1;i<=n;i++)
    {
        a[i]=m.first;
        m.first=(m.first+a[i])%N;
        m.second++;
        if(m.second>=k)
        {
            m.first-=a[i-k],m.second--;
            if(m.first<0)m.first+=N;
        }
    }
    cout<<a[n]%N<<endl;
    return 0;
}