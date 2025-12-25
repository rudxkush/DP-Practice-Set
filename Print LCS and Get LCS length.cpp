#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = (int) text1.size();
        int m = (int) text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[n][m];
    }
};
class printSolution {
public:
    string printLongestCommonSubsequence(string text1, string text2) {
        int n = (int) text1.size();
        int m = (int) text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        string ans;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        while (n && m) {
            if (text1[n - 1] == text2[m - 1]) {
                ans += text1[n - 1];
                n -= 1;
                m -= 1;
            } else {
                if (dp[n - 1][m] > dp[n][m - 1]) {
                    n -= 1;
                } else {
                    m -= 1;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    string text1 = "abcde";
    string text2 = "ace";
    Solution obj1;
    cout << "The longest common subsequence's Length is: ";
    cout << obj1.longestCommonSubsequence(text1, text2) << endl;
    printSolution obj2;
    cout << "The longest common subsequence is:";
    cout << obj2.printLongestCommonSubsequence(text1, text2) << endl;
    return 0;
}
