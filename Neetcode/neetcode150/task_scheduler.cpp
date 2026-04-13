class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int, vector<int>, less<int>> maxHeap;
        vector<int> count(26,0);
        int time = 0;
        for(char c:tasks) {
                count[c-'A']++;
        }
        for(int c:count) {
                if(c>0) {
                        maxHeap.push(c);
                }
        }
        queue<pair<int, int>> q;
        while(maxHeap.empty()==0 || q.empty()==0) {
                time++;
                if(maxHeap.empty()==0) {
                        int top = maxHeap.top();
                        maxHeap.pop();
                        if(top-1>0) {        
                        q.push({top-1, time+n});
                } 
                }     
                while(q.empty()==0 && time==q.front().second) {
                        maxHeap.push(q.front().first);
                        q.pop();
                }
        }
        return time;
    }
};