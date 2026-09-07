class Solution {
  public:
    int rec(int i,int j,vector<int> &arr,vector<vector<int>>&dp){
        if(i==j)return 0;
        int ans=1e9;
        if(dp[i][j]!=-1)return dp[i][j];
        for(int k=i;k<j;k++){
            int step=arr[i-1]*arr[k]*arr[j]+rec(i,k,arr,dp)+rec(k+1,j,arr,dp);
            ans=min(step,ans);
        }
        return dp[i][j]=ans;
    }
    int matrixMultiplication(vector<int> &arr) {
       int n=arr.size();
       vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       return rec(1,n-1,arr,dp);
        
    }
};