class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1);
        if(n==1) {
            return nums[0];
        }
        vector<int> v1(nums.begin() + 1, nums.end());
        vector<int> v2(nums.begin(), nums.end() - 1);
        return max(helper(v1), helper(v2));
    }

    int helper(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1);
        if(n==1) {
            return nums[0];
        }
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i=2; i<n; i++) {
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        return dp[n-1];
    }
};