class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ones = 0, zeroes = 0, ans = INT_MIN;
        int i = 0, n = (int) nums.size();
        for(int j = 0; j < n; ) {
            if(nums[j] == 1) {
                ones += 1;
            } else {
                zeroes += 1;
            }

            while(zeroes > k) {
                if(nums[i] == 0) {
                    zeroes--;
                }
                i++;
            }
            if(zeroes <= k)
                ans = max(ans, j - i + 1);

            j++;
        }
        return ans;
    }
};
