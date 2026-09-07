#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    ll rec(int i,ll last,vector<vector<ll>>&dp,vector<int>& nums){
        if(i==nums.size())return 0;
        ll tot=0;
        if(dp[i][last+1]!=-1)return dp[i][last+1];
        if(last==-1||nums[i]>nums[last]){
            tot=1+rec(i+1,i,dp,nums);
            tot=max(tot,rec(i+1,last,dp,nums));
        }else{
            tot=max(tot,rec(i+1,last,dp,nums));
        }
        return dp[i][last+1]=tot;
    }
    int lengthOfLIS(vector<int>& nums) {
        ll n=nums.size();
        vector<vector<ll>>dp(n+1,vector<ll>(n+1,-1));
       return rec(0,-1,dp,nums);

    }
};