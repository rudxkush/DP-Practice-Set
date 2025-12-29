class Solution {
public:
    vector<vector<int>> dp;
    int rec(vector<int>& logs, int i, int j) {
        // Base Case
        if(i > j) {
            return 0;
        }

        // if already computed!
        if(dp[i][j] != -1) return dp[i][j];

        int res = INT_MAX;
        for(int k = i; k <= j; k++) {
            int logUsed = logs[j + 1] - logs[i - 1];
            // k is the focal here!
            int temp = logUsed + rec(logs, i, k - 1) + rec(logs, k + 1, j);
            res = min(temp, res);
        }
        return dp[i][j] = res;
    }
    int minCost(int stickLen, vector<int>& cuts) {
        vector<int> logs;
        logs.push_back(0);
        for(int cut : cuts) {
            logs.push_back(cut);
        }
        logs.push_back(stickLen);
        sort(logs.begin(), logs.end());
        int len = (int) logs.size();
        dp.resize(len + 1, vector<int>(len + 1, -1));
        return rec(logs, 1,  len - 2); // 1 -> cuts[0], len - 2 -> cuts[n - 1] 
    }
};
