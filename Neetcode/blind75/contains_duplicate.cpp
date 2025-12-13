class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> original_set;
        for(int i=0; i<n; i++) {
            if(original_set.count(nums[i])) {
                return true;
            }
            original_set.insert(nums[i]);
        }
        return false;
    }    
};