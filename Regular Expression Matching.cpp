class Solution {
public:
    vector<vector<int>> dp;
    bool matchChecker(string& s, string& p, int i, int j) {
        // base case
        if (i < 0 && j < 0) return true;
        if (i < 0 && j >= 0) {
            if (p[j] == '*') {
                return matchChecker(s, p, i, j - 2); 
            }
            return false;
        }
        if (i >= 0 && j < 0) return false;

        // if already computed !
        if(dp[i][j] != -1) return dp[i][j];

        // single character matching
        if (s[i] == p[j] || p[j] == '.')
            return dp[i][j] = matchChecker(s, p, i - 1, j - 1);

        // repetitive character matching
        if (p[j] == '*') {
            if (j == 0) return false;

            if (s[i] == p[j - 1] || p[j - 1] == '.')
                return dp[i][j] = matchChecker(s, p, i - 1, j) || matchChecker(s, p, i, j - 2);

            else 
                return matchChecker(s, p, i, j - 2);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        dp.assign(n, vector<int>(m, - 1));
        return matchChecker(s, p, n - 1, m - 1);
    }
};
