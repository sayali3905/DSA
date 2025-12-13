class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> two_sum;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(two_sum.find(target-nums[i])!=two_sum.end()) {
                return {two_sum[target-nums[i]], i};
            }
            else {
                two_sum[nums[i]] = i;
            }
        }
        return {};
    }
};