int Solution::solve(vector<vector<int>>& houses) {
    int n = (int) houses.size();
    vector dp(n + 1, vector<int> (3, INT_MAX));
  
    // Intial Phase
    dp[0][0] = houses[0][0]; 
    dp[0][1] = houses[0][1]; 
    dp[0][2] = houses[0][2];
  
    // State transition
    for(int i = 1; i < n; ++i) {
        dp[i][0] = houses[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = houses[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = houses[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }
    return min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
}
