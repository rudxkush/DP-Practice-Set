/*
    Author: rudxkush
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
const int MOD = 1e9 + 7;
int countAllSuchArrays(vector<int>& arr, int n, int m) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // Base condition
    if (arr[0] == 0) {
        for (int val = 1; val <= m; val++) {
            dp[0][val] = 1;
        }
    } else {
        dp[0][arr[0]] = 1;
    }

    for (int i = 0; i <= n-2; i++) {
        for (int val = 1; val <= m; val++) {
            // dp[i][val] : dp[i + 1][val + -1], while deciding for a[i + 1]
            for (int y : {val - 1, val, val + 1}) { // all could be the possible values of a[i + 1] after knowing for a[i]
                if (y >= 1 && y <= m) {
                    if (arr[i + 1] != 0 && arr[i + 1] != y) continue;
                    dp[i + 1][y] = (dp[i + 1][y] + dp[i][val]) % MOD;
                }
            }
        }
    }

    int answer = 0;
    for (int val = 1; val <= m; val++) {
        answer = (answer + dp[n - 1][val]) % MOD;
    }
    return answer;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    /*
            Given: the difference between adjacent number in an array is at most 1 that it is either 0 or 1 in case of non decimals.
            Intuition:
            0 1 2 3 4 5 6 7 8 9 10 11
            2 ? ? ? ? 3 ? 5 ? ?  ?  ?
              3 4 5 4
              3 3 2 3
              ... exponential possibilities

           arr[6]: you can choose greedily be looking at the previous and the next element and so you can put 4

           dp[i][value]: number of ways to fill from 0....i such that a[i] = value

           Crucial Steps:
           1st : think of the definition of the dp state
           2nd : figure out the transition!
    */
    cout << countAllSuchArrays(arr, n, m) << endl;
    return 0;
}
