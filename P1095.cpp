#include<iostream>
#include<cstring>
using namespace std;
int m,s,t;

int main()
{
    cin>>m>>s>>t;
    int s1=0,s2=0;
    for(int i=1;i<=t;i++)
    {
        s1+=17;
        if(m>=10)
        {
            m-=10;
            s2+=60;
        }
        else
            m+=4;
        if(s2>s1)s1=s2;
        if(s1>s)
        {
            cout<<"Yes"<<endl<<i;
            return 0;
        }
    }
    cout<<"No"<<endl<<s1;
    return 0;
}