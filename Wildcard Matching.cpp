class Solution {
public:
    vector<vector<int>> dp;
    int n = 0, m = 0; 
    bool rec(string& str, string& pattern, int i, int j) {
        // base condition
        if(i >= n && j >= m) return true;
        if(i >= n && j < m) {
            if(pattern[j] == '*') {
                return rec(str, pattern, i, j + 1);
            }
        }
        if(i < n && j >= m) return false;
        if(dp[i][j] != -1) return dp[i][j];


        // single character matching
        if(str[i] == pattern[j] || pattern[j] == '?') {
            return dp[i][j] = rec(str, pattern, i + 1, j + 1);
        }

        // multi character matching
        if(pattern[j] == '*') {
            return dp[i][j] = rec(str, pattern, i + 1, j) || rec(str, pattern, i, j + 1);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string str, string pattern) {
        n = str.size();
        m = pattern.size();
        dp.resize(n + 1, vector<int> (m + 1, -1));
        return rec(str, pattern, 0, 0);
    }
};
