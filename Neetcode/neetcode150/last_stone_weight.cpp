class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> maxHeap;
        int n = stones.size();
        for(int i=0; i<n; i++) {
                maxHeap.push(stones[i]);                
        }
        while(maxHeap.size()>1) {
                int heavy1 = maxHeap.top();
                maxHeap.pop();
                int heavy2 = maxHeap.top();
                maxHeap.pop();
                int diff = heavy1 - heavy2;
                if(diff!=0) {
                        maxHeap.push(diff);
                }  
        }
        if(maxHeap.empty()) {
                return 0;
        }              
        else {
                return maxHeap.top();
        }
    }
};