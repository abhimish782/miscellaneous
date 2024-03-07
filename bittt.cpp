#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int solve1(int n){
    int cnt=0;
    for(int i=0;i<=n;i++){
        if((n|i)<=n) cnt++;
    }
    return cnt;
}

int solve(int n){
    int cnt=0;
    while(n>0){
        int bit=n%2;
        if(bit==1)cnt++;
        n/=2;
    }
    return pow(2,cnt);
    
}
int main() {
    for(int i=10000;i<100000;i++){
        if(solve(i)!=solve1(i)) cout<<i<<" ";
    }
    return 0;
}