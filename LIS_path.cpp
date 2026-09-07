class Solution {
	public:
	vector<int> getLIS(vector<int>& nums) {
		int n = nums.size();
		vector<int>dp(n, 1), hash(n );
		int last = 0, mx = 0;
		
		for(int i=0;i<n;i++)hash[i]=i;
		for (int i = 0; i<n; i++) {
			for (int j = i + 1; j<n; j++) {
				if (nums[j]>nums[i] && dp[i]+1>dp[j]) {
					dp[j] = dp[i]+1;
					hash[j] = i;
				}
			}
		}
		
		for(int i=0;i<n;i++){
		    	if (mx<dp[i]) {
				mx = dp[i];
				last = i;
			}
		}
		vector<int> path;
        
		while (hash[last] != last) {
			path.push_back(nums[last]);
			last = hash[last];
		}
		path.push_back(nums[last]);
		reverse(path.begin(),path.end());
		
	    return path;
	}
};
