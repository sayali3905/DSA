class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> sequence;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            sequence.insert(nums[i]);
        }  
        int count = 0;
        int longest = 0;
        for(const auto& element: sequence) {
            if(sequence.count(element-1)==0) {
                count = 1;
                int current = element+1;
                while(sequence.count(current)==1) {
                    count++;
                    current++;
                }
                longest = max(longest, count);
            }
        } 
        return longest;                
    }
};