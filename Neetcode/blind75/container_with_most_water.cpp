class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int left = 0;
        int right = len-1;
        int res = 0;
        while(left<right) {
            int w = right - left;
            int h = min(height[left], height[right]);
            int area = w*h;
            res = max(area, res);
            if(height[left]>height[right]) {
                right--;
            }
            else {
                left++;
            }
        }
        return res;
    }
};