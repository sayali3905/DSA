class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> subset;
        int total = 0;
        dfs(candidates, result, subset, target, total, 0);
        return result;
    }
    void dfs(vector<int>& candidates, vector<vector<int>>& result, vector<int> subset, int target, int total, int i=0) {
        if(i>=candidates.size() || total>target) {
            return;
        }
        if(total == target) {
            result.push_back(subset);
            return;
        }
        subset.push_back(candidates[i]);
        dfs(candidates, result, subset, target, total+candidates[i], i+1);
        subset.pop_back();
        dfs(candidates, result, subset, target, total, i+1);
    }
};