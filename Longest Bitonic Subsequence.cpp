int Solution::longestSubsequenceLength(const vector<int> &nums) {
    int n = (int) nums.size();
    if (n == 0) return 0;
    vector<int> Inc(n, 1);
    vector<int> Dec(n, 1);
    
    for(int i = 0; i < n; i++) {
        for(int prev = 0; prev < i; prev++) {
            if(nums[i] > nums[prev] && Inc[prev] + 1 > Inc[i]) {
                Inc[i] = Inc[prev] + 1;  
            }
        }
    }
    
    for(int i = n - 1; i >= 0; i++) {
        for(int next = n - 1; next > i; next++) {
            if(nums[i] > nums[next] && Dec[next] + 1 > Dec[i]) {
                Dec[i] = Dec[next] + 1;  
            }
        }
    }
    
    int longestMountain = 1;
    for(int i = 0; i < n; i++) {
        if(Inc[i] + Dec[i] - 1 > longestMountain) {
            longestMountain = Inc[i] + Dec[i] - 1;
        }
    }
  
    return longestMountain;
}
