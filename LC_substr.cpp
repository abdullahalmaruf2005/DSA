class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
       int n=s1.size(),m=s2.size();
       vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MIN));
       for(int i=0;i<=n;i++)dp[i][0]=0;
       for(int i=0;i<=m;i++)dp[0][i]=0;
       int ans=0;
       for(int i=1;i<=n;i++){
           for(int j=1;j<=m;j++){
               int clc=0;
               if(s1[i-1]==s2[j-1]){
                   clc=1+dp[i-1][j-1];
                   ans=max(ans,clc);
               }
               else clc=0;
               dp[i][j]=clc;
           }
       }
       return ans;
        
    }
};