#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> dp;
const int MOD = 1e9+7;
int countAllSuchPaths(vector<int>& availableCoins, int desiredSum, int i) {
    // Base Condition
    if (desiredSum == 0) return 1;
    if (desiredSum < 0) return 0;
    if (dp[desiredSum][i] != -1) return dp[desiredSum][i];

    int count = 0;
    for (int i = 0; i < availableCoins.size(); i++) {
        count = (count + countAllSuchPaths(availableCoins, desiredSum - availableCoins[i], i)) % MOD;
    }
    return dp[desiredSum][i] = count;
}

int main() {
    int n;
    int desiredSum;
    cin >> n >> desiredSum;
    vector<int> availableCoins(n);
    for (int i = 0; i < n; i++) cin >> availableCoins[i];

    dp.clear();
    dp.resize(desiredSum + 1, vector<int>(n + 1, -1));

    cout << countAllSuchPaths(availableCoins, desiredSum,0) << endl;
    return 0;
}
