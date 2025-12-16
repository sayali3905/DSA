//by reversing the string
class Solution {
public:
    bool isPalindrome(string s) {
        string result;
        string original;
        for(char ch:s) {
            if(isalnum(ch)) {
                result += tolower(ch);
            }
        }
        original = result;
        reverse(result.begin(), result.end());
        return original==result;

    }
};

//by two pointer approach
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;
        while(left<right) {
            if(isalnum(s[left])==0) {
                left++;
                continue;
            }
            if(isalnum(s[right])==0) {
                right--;
                continue;
            }
            if(tolower(s[left])!=tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};