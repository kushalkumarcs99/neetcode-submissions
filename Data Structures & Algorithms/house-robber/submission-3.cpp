class Solution {
public:
    int robHelper(int ind, vector<int>& nums, vector<int>& dp)
    {
        if(ind >= nums.size())
        {
            return 0;
        }
        if(dp[ind] != -1) return dp[ind];
        int considerThis = nums[ind] + robHelper(ind+2, nums, dp);
        int notConsiderThis = 0 + robHelper(ind+1,nums, dp);
        return dp[ind] = max(considerThis, notConsiderThis);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return robHelper(0,nums,dp);
    }
};