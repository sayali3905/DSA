class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map <char, int> count;
        int left = 0;
        int right = 0;
        int maxlength = 0;
        int maxFreq = 0;
        for(int i=0;i<n;i++) {
            count[s[i]]++;
            maxFreq = max(maxFreq, count[s[i]]);
            if((i-left+1)-maxFreq>k) {
                count[s[left]]--;
                left++;
            }
            maxlength = max(maxlength, i-left+1);
        }
        return maxlength;
    }
};