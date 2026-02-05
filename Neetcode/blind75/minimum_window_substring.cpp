class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> countT;
        unordered_map<char, int> countS;
        for(char c:t) {
            countT[c]++;
        }
        int need = countT.size();
        int left = 0, minStart = 0;
        int n = s.size();
        int have = 0;
        int minLen = INT_MAX;
        for(int i=0; i<n; i++) {
            if(countT.count(s[i])) {
                countS[s[i]]++;
                if(countT[s[i]]==countS[s[i]]) {
                    have++;
                }
            }
            while(have == need) {
                if(i-left+1<minLen) {
                    minLen = i-left+1;
                    minStart = left;
                }
                if(countT.count(s[left])) {
                    countS[s[left]]--;
                    if(countS[s[left]]<countT[s[left]]) {
                        have--;
                    }
                }
                left++;
            }
        }
        if(minLen==INT_MAX) {
            return "";
        }
        else {
            return s.substr(minStart, minLen);
        }
    }
};