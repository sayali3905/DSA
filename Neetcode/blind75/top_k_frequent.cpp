class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            freq[nums[i]]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> min_heap;
        for(const auto& pair: freq) {
            min_heap.push({pair.second, pair.first});
            if(min_heap.size()>k) {
                min_heap.pop();
            }
        }
        vector<int> result;
        while(min_heap.empty()==0) {
            result.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return result;
    }
};