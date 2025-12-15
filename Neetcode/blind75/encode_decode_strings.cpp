class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string;
        for(string s : strs) {
            encoded_string.append(to_string(s.size()));
            encoded_string.append("#");
            encoded_string.append(s);
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_string;
        int i=0;
        while(i<s.size()) {
            int j = i;
            while(s[j]!='#') {
                j = j+1;
            }
            int length = stoi(s.substr(i, j - i));
            decoded_string.push_back(s.substr(j + 1, length));
            i = j+1+length;
        }
        return decoded_string;    
    }
};
