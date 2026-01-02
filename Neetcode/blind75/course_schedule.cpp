class Solution {
    unordered_map<int, vector<int>> courseMap;
    unordered_set<int> visiting;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0; i<numCourses; i++) {
            courseMap[i] = {};
        }
        for(auto& prereq: prerequisites) {
            courseMap[prereq[0]].push_back(prereq[1]);
        }
        for(int c=0; c<numCourses; c++) {
            if(dfs(c)==0) {
                return false;
            }
        }
        return true;
    }

    bool dfs(int crs) {
        if(visiting.count(crs)) {
            return false;
        }
        if(courseMap[crs].empty()) {
            return true;
        }
        visiting.insert(crs);
        for(int pre:courseMap[crs]) {
            if(dfs(pre)==0) {
                return false;
            }
        }
        visiting.erase(crs);
        courseMap[crs].clear();
        return true;
    }
};