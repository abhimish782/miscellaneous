#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int ans;
    while(n>0)
    {
        int a,b,c;
        cin>>a>>b>>c;
        ans=a;
        while(b>=3)
        {
            ans++;
            b=b-3;
        }
        if(b!=0)
        {
            if(c>=3-b)
            {
                ans++;
                c=c-(3-b);
            }
            else
            {
            ans=-1;
            c=0;
            }
        }
        while(c>=3)
        {
            ans++;
            c=c-3;
        }
        if(ans==-1)
        //cout<<-1;
        if( c!=0)
        ans++;
        cout<<ans<<endl;
        n--;
    }
    
}