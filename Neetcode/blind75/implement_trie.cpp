class TrieNode {
    public:
    bool EndofWord;
    unordered_map<char, TrieNode*> children;
    TrieNode() : EndofWord(false) {};
};

class Trie {
private:
    TrieNode* root;    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(char c:word) {
            if(node->children.count(c)==0) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->EndofWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(char c:word) {
            if(node->children.count(c)==0) {
                return false;
            }
            node = node->children[c];
        }
        return node->EndofWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char c:prefix) {
            if(node->children.count(c)==0) {
                return false;
            }
            node = node->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */