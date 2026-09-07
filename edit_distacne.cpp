class Solution {
public:
    int rec(int i,int j,string &word1, string &word2,vector<vector<int>>&dp){
         if(i==0)return j;
        if(j==0){
            return i;
        }
       
        if(dp[i][j]!=-1)return dp[i][j];
        int cnt=INT_MAX;
        if(word1[i-1]==word2[j-1]){
            cnt=rec(i-1,j-1,word1,word2,dp);
        }else{
            cnt=min(1+rec(i-1,j-1,word1,word2,dp),1+rec(i-1,j,word1,word2,dp));
            cnt=min(cnt,1+rec(i,j-1,word1,word2,dp));
        }
        return dp[i][j]=cnt;
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return rec(n,m,word1,word2,dp);

    }
};