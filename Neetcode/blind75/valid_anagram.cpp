class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        int len_s = s.size();
        int len_t = t.size();
        if(len_s!=len_t) {
            return false;
        }
        for(char c: s) {
            map[c]++;
        }
        for(char c: t) {
            map[c]--;
        }
        for (const auto& pair : map) {
        if (pair.second != 0) {
            return false; 
        }
        }
        return true;
    }
};