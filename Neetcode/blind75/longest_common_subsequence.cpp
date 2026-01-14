class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> OPT(n+1, vector<int>(m+1,0));
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(text1[i-1]==text2[j-1]) {
                    OPT[i][j] = 1+ OPT[i-1][j-1];
                }
                else {
                    OPT[i][j] = max(OPT[i-1][j], OPT[i][j-1]);
                }
            }
        }
        return OPT[n][m];
    }
};