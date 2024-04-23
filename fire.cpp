#include<bits/stdc++.h>
using namespace std;
int findValue(long long int start,long long int end){
    long long int i=1;
    i=floor(end/start);
    i+=end%start;
    long long int cnt=0;
    end=end*2;
    return (ceil(end*1.0/start)-i)+1;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long int a,b,c;
        cin>>a>>b>>c;
        long long int ans=0;
        ans+=findValue(a,c);
        ans+=findValue(b,c);
        cout<<"answer is"<<ans<<endl;
    }
    return 0;
}