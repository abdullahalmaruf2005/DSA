class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
       vector<int>dp(sum+1,-1);
       dp[0]=1;
       for(int i=0;i<arr.size();i++){
           for(int j=sum;j>=0;j--){
               if(j+arr[i]>sum)continue;
               if(dp[j]==-1)continue;
               dp[j+arr[i]]=dp[j];
           }
       }
       return dp[sum]==-1? false:true;
        
    }
};