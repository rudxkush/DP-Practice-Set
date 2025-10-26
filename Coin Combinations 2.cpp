/*
    Author: rudxkush
*/
#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9+7;
vector<vector<int> > dp;
int countAllSuchPossibilities(vector<int>& availableCoins, int desiredSum, int i) {
    // Base Condition
    if (desiredSum == 0) return 1;
    if (i >= availableCoins.size()) return 0;

    // If already precomputed
    if (dp[desiredSum][i] != -1) return dp[desiredSum][i];

    // Inclusion
    int include = 0;
    if (availableCoins[i] <= desiredSum)
         include = countAllSuchPossibilities(availableCoins, desiredSum - availableCoins[i], i);

    // Exclusion
    int exclude = countAllSuchPossibilities(availableCoins, desiredSum, i + 1);

    // Return
    return dp[desiredSum][i] = (include + exclude) % MOD;
}

int main() {
    int n;
    int desiredSum;
    cin >> n >> desiredSum;
    vector<int> availableCoins(n);
    for (int i = 0; i < n; i++) cin >> availableCoins[i];

    dp.clear();
    dp.resize(desiredSum + 1, vector<int>(n + 1, -1));
    cout << countAllSuchPossibilities(availableCoins, desiredSum,0) << endl;
    return 0;
}
