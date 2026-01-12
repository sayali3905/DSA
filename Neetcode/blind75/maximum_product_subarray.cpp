class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0], maximum = nums[0], minimum = nums[0];
        for(int i=1; i<nums.size(); i++) {
            int num = nums[i];
            if(num<0) {
                swap(minimum, maximum);
            }
            maximum = max(num, maximum*num);
            minimum = min(num, minimum*num);
            result = max(result, maximum);
        }
        return result;
    }
};