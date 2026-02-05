//using sum formula
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = 0;
        int n = nums.size();
        int total = 0;
        int total_nums = 0;
        total = n*(n+1)/2;
        for(int i=0; i<n; i++) {
            total_nums = total_nums + nums[i];
        }
        missing = total - total_nums;
        return missing;
    }
};

//using XOR
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = nums.size();
        for(int i=0; i<nums.size(); i++) {
            missing = missing ^ (i^nums[i]);
        }
        return missing;
    }
};


