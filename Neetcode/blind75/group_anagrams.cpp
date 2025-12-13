// using frequency array method
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> anagrams;
        for (const string& s : strs) {
            vector<int> charCount(26, 0);
            for (char c : s) {
                charCount[c - 'a']++;
            }
            anagrams[charCount].push_back(s);
        }
        vector<vector<string>> result;
        for (auto& entry : anagrams) {
            result.push_back(entry.second);
        }
        return result;
    }
};

// using sorting method
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        for(string s: strs) {
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end());
            anagrams[sorted_s].push_back(s);
        }
        for(const auto& pair: anagrams) {
            result.push_back(pair.second);
        }
        return result;
    }
};