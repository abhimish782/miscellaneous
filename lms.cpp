#include<bits/stdc++.h>
using namespace std;
int lms(vector<int>& nums,int k) {
        int n = nums.size();
        if (n <= 2)
            return n;

        int longest = 2;
        vector<unordered_map<int, int>> dp(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int mod = (nums[i]+nums[j])%k;
                dp[i][mod] = dp[j].count(mod) ? dp[j][mod] + 1 : 2;
                longest = max(longest, dp[i][mod]);
            }
        }

        return longest;
    }


int main(){
    vector<int>arr={1,2,4,1,2};
    int k=2;
    cout<< lms(arr,k);
    return 0;
}