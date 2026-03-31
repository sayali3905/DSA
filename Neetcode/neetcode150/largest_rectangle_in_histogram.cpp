class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> bar_stack;      // index, height

        for(int i=0; i<heights.size(); i++) {
            int start = i;
            while(bar_stack.empty()==0 &&  bar_stack.top().second>=heights[i]) {
                int index = bar_stack.top().first;
                int height = bar_stack.top().second;
                bar_stack.pop();
                maxArea = max(maxArea, height*(i-index));
                start = index;
            }
            bar_stack.push({start, heights[i]});
        }
        while(bar_stack.empty()==0) {
            int index = bar_stack.top().first;
            int height = bar_stack.top().second;
            int end = heights.size();
            maxArea = max(maxArea, height*(end-index));
            bar_stack.pop();
        }
        return maxArea;
    }
};