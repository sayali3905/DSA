class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;
        int n = s.size();
        int left = 0;
        unordered_set <int> duplicate;
        for(int i=0; i<n; i++) {
           while(duplicate.count(s[i])) {
                duplicate.erase(s[left]);
                left++;
           }
           duplicate.insert(s[i]);
           length = max(length, i-left+1);
        }
        return length;
    }
};