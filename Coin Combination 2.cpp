#include <iostream>
#include <vector>
using namespace std;
int countAllSuchPossibilities(vector<int>& availableCoins, int desiredSum, int i) {
    // Base Condition
    if (desiredSum == 0) return 1;
    if (desiredSum < 0) return 0;
    if (i >= availableCoins.size()) return 0;

    // Inclusion
    int include = countAllSuchPossibilities(availableCoins, desiredSum - availableCoins[i], i);

    // Exclusion
    int exclude = countAllSuchPossibilities(availableCoins, desiredSum, i + 1);

    // Return
    return include + exclude;
}

int main() {
    int n;
    cin >> n; // number of coins
    vector<int> availableCoins(n);
    for (int i = 0; i < n; i++) cin >> availableCoins[i];
    
    int desiredSum;
    cin >> desiredSum;
    sort(availableCoins.begin(), availableCoins.end());
    cout << countAllSuchPossibilities(availableCoins, desiredSum,0) << endl;
    return 0;
}
