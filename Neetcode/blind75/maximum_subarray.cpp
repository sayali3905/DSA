//dynamic programming approach
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int result = nums[0];
        int maximum = nums[0];
        for(int i=1; i<n; i++) {
            maximum = max(nums[i], maximum+nums[i]);
            result = max(result, maximum);
        }
        return result;
    }
};

//greedy approach
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0;
        int maxSum = nums[0];
        for(int i=0; i<nums.size(); i++) {
            if(curSum<0) {
                curSum = 0;
            }
            curSum = curSum + nums[i];
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};