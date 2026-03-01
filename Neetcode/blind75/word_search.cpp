class Solution {
public:
    int rows;
    int cols;
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int len = word.size();
        for(int r=0; r<rows; r++) {
            for(int c=0; c<cols; c++) {
                if(dfs(board, word, r, c, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i, vector<vector<bool>>& visited) {
        if(i==word.size()) {
            return true;
        }
        if(r<0 || c<0 || r>=rows || c>=cols || word[i]!=board[r][c] || visited[r][c]) {
            return false;
        }
        visited[r][c] = true;
        bool res = (dfs(board, word, r-1, c, i+1, visited) || dfs(board, word, r, c+1, i+1, visited) || dfs(board, word, r, c-1, i+1, visited) || dfs(board, word, r+1, c, i+1, visited));
        visited[r][c] = false;
        return res;
    }
};