class Solution {
public:
    vector<vector<int>> heights;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->heights = heights;
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        vector<vector<int>> result;
        for(int r=0; r<rows; r++) {
            dfs(r, 0, pacific, heights[r][0]);
            dfs(r, cols-1, atlantic, heights[r][cols-1]);
        }
        for(int c=0; c<cols; c++) {
            dfs(0, c, pacific, heights[0][c]);
            dfs(rows-1, c, atlantic, heights[rows-1][c]);
        }
        for(int r=0; r<rows; r++) {
            for(int c=0; c<cols; c++) {
                if(pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r,c});
                }
            }
        }
        return result;
    }

    void dfs(int r, int c, vector<vector<bool>>& ocean, int prevHeight) {
        int rows = heights.size();
        int cols = heights[0].size();
        if(r<0 || c<0 || r>=rows || c>=cols || heights[r][c]<prevHeight || ocean[r][c]==true) {
            return;
        }
        ocean[r][c] = true;
        dfs(r+1, c, ocean, heights[r][c]);
        dfs(r-1, c, ocean, heights[r][c]);
        dfs(r, c+1, ocean, heights[r][c]);
        dfs(r, c-1, ocean, heights[r][c]);
    }
};