#include<iostream>
using namespace std;

string s;
int n;
int a[255];
int flag=0;

int main()
{
    cin>>s>>n;
    int len=s.length(),k=len-n,l=0,i,j;
    for(int i=0;i<len;i++)
    {
        a[i]=s[i]-'0';
    }
    for(i=1;i<=k;i++)
    {
        int nmax=10;
        for(j=l;j<n+i;j++)
        {
            if(a[j]<nmax)nmax=a[j],l=j;
        }
        if(flag||a[l]||k==1)cout<<a[l];
        if(a[l])flag=1;
        l++;
    }
    return 0;
}