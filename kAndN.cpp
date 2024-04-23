#include<bits/stdc++.h>
using namespace std;


// bool f1(long long int k, long long int n){
//     vector<vector<bool>> dp(k + 1, vector<bool>(n + 1, false));

//     // Base case: If k = 0 and x = N, return true
//     dp[0][n] = true;

//     for (int i = 1; i <= k; ++i) {
//         for (int j = 1; j <= n; ++j) {
//             // If x-1 is feasible and leads to N, or x*2 is feasible and leads to N
//             dp[i][j] = (j - 1 >= 0 && dp[i - 1][j - 1]) || (j * 2 <= n && dp[i - 1][j * 2]);
//         }
//     }

//     return dp[k][1]; // Check if starting from 1 is feasible after k operations
// }
bool f1(long long int x,long long int k,const long long int N,vector<vector<int>>&tbl){
    if(tbl[k][x]!=-1) return tbl[k][x];
    if(k==0&&x==N) return tbl[k][x]= true;
    if(k==0||x<=0) return tbl[k][x]= false;
    bool sub=f1(x-1,k-1,N,tbl);
    bool mul=f1(x*2,k-1,N,tbl);
    return tbl[k][x]= sub||mul;
}
string solve(long long int k,long long int n){
    vector<vector<int>>tbl(k+1,vector<int>(n+1,-1));
    bool ans=f1(1,k,n,tbl);
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long int k,N;
        cin>>k>>N;
        solve(k,N);
    }
}