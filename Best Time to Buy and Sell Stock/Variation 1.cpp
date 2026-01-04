class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestBuy = INT_MAX;
        int maxProfit = INT_MIN;
        int n = (int) prices.size();
        for(int i = 0; i < n; i++) {
            if(bestBuy > prices[i]) {
                bestBuy = prices[i];
            } else {
                maxProfit = max(prices[i] - bestBuy, maxProfit);
            }
        }
        return maxProfit == INT_MIN ? 0 : maxProfit; 
    }
};
