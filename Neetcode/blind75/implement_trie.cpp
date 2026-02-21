class TrieNode {
    public:
        vector<TrieNode*> children;
        bool EndOfWord;
        TrieNode() {
            children = vector<TrieNode*>(26, nullptr);
            EndOfWord = false;
        }
};

class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() { 
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for(char c:word) {
            if(cur->children[c-'a']==nullptr) {
                cur->children[c-'a'] = new TrieNode();
            }
            cur = cur->children[c-'a'];
        }
        cur->EndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for(char c: word) {
            if(cur->children[c-'a']==nullptr) {
                return false;
            }
            cur = cur->children[c-'a'];
        }
        return cur->EndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(char c:prefix) {
            if(cur->children[c-'a']==nullptr) {
                return false;
            }
            cur = cur->children[c-'a'];
        }
        return true;
    }
};
