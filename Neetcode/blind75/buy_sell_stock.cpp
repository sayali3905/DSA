class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int sell = 0;
        int result = 0;
        int profit = 0;
        int n = prices.size();
        for(int i=1; i<n; i++) {
            sell = i;
            if(prices[sell]<prices[buy]) {
                buy = i;
            }
            else {
                profit = prices[sell] - prices[buy];
            }
            result = max(result, profit);
        }
        return result;
    }
};