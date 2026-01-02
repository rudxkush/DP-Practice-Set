int Solution::lis(const vector<int> &nums) {
    int n = (int) nums.size();
    vector<int> dp(n, 1);
    int lisLength = 1;
    
    for(int i = 0; i < n; i++) {
        for(int prev = 0; prev < i; prev++) {
            if(nums[i] > nums[prev] && dp[prev] + 1 > dp[i]) {
                dp[i] = dp[prev] + 1;  
            }
        }
        lisLength = max(dp[i], lisLength);
    }
    
    
    return lisLength;
}
