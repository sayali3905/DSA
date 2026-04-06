class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int k = right;
        while(left<=right) {
            int mid = left+(right-left)/2;
            long long total_time = 0;
            for(int p:piles) {
                total_time = total_time + (p+mid-1)/mid;
            }
            if(total_time<=h) {
                right = mid-1;
                k = mid;
            }
            else {
                left = mid+1;
            }
        }
        return k;
    }
};