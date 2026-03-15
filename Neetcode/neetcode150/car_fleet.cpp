class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pos_with_speed;
        for(int i=0; i<position.size(); i++) {
            pos_with_speed.push_back({position[i], speed[i]});
        }
        sort(pos_with_speed.rbegin(), pos_with_speed.rend());
        stack<double> time_stack;
        for(auto& pair: pos_with_speed) {
            double time = (double)(target - pair.first)/pair.second;
            if(time_stack.empty()==0 && time<=time_stack.top()) {
                continue;
            }
            time_stack.push(time);
        }
        return time_stack.size();
    }
};