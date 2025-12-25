class Solution {
  public:
    int editDistance(string& s1, string& s2) {
        int n = (int) s1.length(), m = (int) s2.length();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        for(int i = 0; i <= n; i++) {
            dp[i][0] = i;
        } 
        for(int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min({dp[i][j - 1], 
                                        dp[i - 1][j - 1],
                                        dp[i - 1][j]});
                }
            }
        }
        return dp[n][m];
    }
};
//     if(matched) 
//         pick(diagonal_count);
//     else
//         pick(min_out_three_sides);
        
//       g e e k
//     0 1 2 3 4 
//   g 1 0 
//   e 2
//   s 3 
//   e 4 
//   k 5
