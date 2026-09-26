class Solution {
public:
    int robHelper(int ind, vector<int>& nums, vector<int>& dp)
    {
        if(ind >= nums.size())
        {
            return 0;
        }
        if(dp[ind] != -1) return dp[ind];
        //notInclude
        int notInclude = 0 + robHelper(ind + 1, nums, dp);
        //include
        int include = INT_MIN;
        if(ind <= nums.size()-1)
        {
            include = nums[ind] + robHelper(ind+2, nums, dp);
        }

        return dp[ind] = max(notInclude, include);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return robHelper(0,nums, dp);
    }
};
