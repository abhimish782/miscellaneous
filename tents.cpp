#include<bits/stdc++.h>
using namespace std;
int findTents(int intro,int extro,int uni){
    int tents=0;
    tents+=intro;
    if(extro%3==0) {
        tents+=extro/3;
        tents+=floor(uni/3);
        if(uni%3!=0) tents++;
    }
    else{
        int temp=extro%3;
        tents+=floor(extro/3);
        if(uni+temp<3) return -1;
        else {
            tents+=floor((uni+temp)/3) ;//+ floor((uni+temp)%3);
            if( (uni+temp)%3!=0 ) tents++;
        }
    }
    return tents;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int intro,extro,uni;
        cin>>intro>>extro>>uni;
        cout<<findTents(intro,extro,uni)<<endl;
    }
    return 0;
}