class Solution {
public:
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, bool> visited;
    string result;
    string foreignDictionary(vector<string>& words) {
        for(const auto& word: words) {
            for(char c:word) {
                adj[c];
            }
        }
        for(int i=0; i<words.size()-1; i++) {
            string w1 = words[i];
            string w2 = words[i+1];
            int minLen = min(w1.length(), w2.length());
            if(w1.length()>w2.length() && w1.substr(0, minLen)==w2.substr(0, minLen)) {
                return "";
            }
            for(int j=0; j<minLen; j++) {
                if(w1[j]!=w2[j]) {
                    adj[w1[j]].insert(w2[j]);
                    break;
                }
            }
        }
        for(const auto& pair: adj) {
            if(dfs(pair.first)) {
                return "";
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }

    bool dfs(char c) {
        if(visited.find(c)!=visited.end()) {
            return visited[c];
        }
        visited[c] = true;
        for(char next: adj[c]) {
            if(dfs(next)) {
                return true;
            }
        }
        visited[c] = false;
        result.push_back(c);
        return false;
    }
};
