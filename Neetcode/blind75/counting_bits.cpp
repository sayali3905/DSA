class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1,0);
        for(int i=0; i<=n; i++) {
            int num = i;
            while(num!=0) {
                result[i]++;
                num = num & (num-1);
            }
        }
        return result;
    }
};