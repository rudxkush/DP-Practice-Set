int LongestRepeatingSubsequenceHelper(int n, int m,string &s1, string &s2){
    vector<vector<int>> lcs(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i-1] == s2[j-1] && i != j) {
                lcs[i][j] = lcs[i-1][j-1] + 1;
            } else {    
                lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);             
            }
        }
    }   
    return lcs[n][m];
}
int Solution::anytwo(string s) {
    return LongestRepeatingSubsequenceHelper(s.length(), s.length(),s, s) < 2 ? 0 : 1;
}
