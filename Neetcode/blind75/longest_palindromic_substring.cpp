class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int longest = 0;
        int index = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i=n-1; i>=0; i--) {
            for(int j=i; j<n; j++) {
                if(s[i]==s[j]) {
                    if(j-i<=2 || dp[i+1][j-1]) {
                        dp[i][j]=true;
                        if(longest<j-i+1) {
                            index = i;
                            longest = j-i+1;
                        }
                    }
                }
            }
        }
        return s.substr(index, longest);
    }
};