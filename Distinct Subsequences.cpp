int n, m;
const int mod = 1e9+7;
vector<vector<int>> dp;
int rec(string str, string sub, int i, int j) {
	if(j == m) return 1;
	if(i == n && j < m) return 0;
	if(dp[i][j] != -1) return dp[i][j];

	int count = 0;
	if(str[i] == sub[j]) {
		count = (count + rec(str, sub, i + 1, j + 1)) % mod;
	}

	// we choose to skip str element as 
	// it doesn't match to the seq of chars of str
	count = (count + rec(str, sub, i + 1, j)) % mod;

	return dp[i][j] = count;
}

int distinctSubsequences(string &str, string &sub) {
	n = (int) str.size();
	m = (int) sub.size();
	dp.resize(n + 1, vector<int> (m + 1, -1));
	return rec(str, sub, 0, 0);
}
