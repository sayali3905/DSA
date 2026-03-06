class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) {
            return 0;
        }
        int n = height.size();
        int l = 0;
        int r = n-1;
        int result=0;
        int maxL = height[l];
        int maxR = height[r];
        while(l<r) {
            if(maxL<=maxR) {
                l++;
                maxL = max(maxL, height[l]);
                result = result+maxL-height[l];
            }
            else {
                r--;
                maxR = max(maxR, height[r]);
                result = result+maxR-height[r];
            }
        }
        return result;
    }
};