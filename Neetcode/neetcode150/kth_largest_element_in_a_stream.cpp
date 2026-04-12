class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        int n = nums.size();
        for(int i=0; i<n; i++) {
                minHeap.push(nums[i]);
                if(minHeap.size()>k) {
                        minHeap.pop();
                }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size()>k) {
                minHeap.pop();
        }
        return minHeap.top();
    }
};

