class Solution1 {
  public:
    int rec(string& s, int i, int j, vector<vector<int>>& dp) {
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int length = 0;
        if(s[i] == s[j]) {
            length = 2 + rec(s, i + 1, j - 1, dp); 
        } else {
            length = max(rec(s, i, j - 1, dp), rec(s, i + 1, j, dp));
        }
        return dp[i][j] = length;
    }
    int longestPalinSubseq(string &s) {
        int n = (int) s.size();
        vector dp(n + 1, vector<int> (n + 1, -1));
        return rec(s, 0, n, dp);
    }
};
class Solution2 {
  public:
    int lcsLength(string s1, string s2) {
        int n = s1.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][n];
    }
    int longestPalinSubseq(string &s2) {
        int n = (int) s2.size();
        string s1 = s2;
        reverse(s2.begin(), s2.end());
        return lcsLength(s1, s2);
    }
};
