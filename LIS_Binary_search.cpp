class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int cnt=1;
        vector<int>temp;
        temp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(temp.back()<nums[i]){
                cnt++;
                temp.push_back(nums[i]);
            }else{
                int pos=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[pos]=nums[i];
            }
        }
        return cnt;
    }
};