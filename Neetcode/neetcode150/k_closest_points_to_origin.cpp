class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> closest;
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> minHeap;
        int n = points.size();
        for(int i=0; i<n; i++) {
                int x = points[i][0];
                int y = points[i][1];
                int distance = x*x + y*y;
                minHeap.push({distance, points[i]});
        }
        for(int i=0; i<k; i++) {
                closest.push_back(minHeap.top().second);
                minHeap.pop();
        }
        return closest;
    }
};
