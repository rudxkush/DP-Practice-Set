#include <iostream>
#include <vector>
using namespace std;

int countAllSuchPaths(vector<int>& availableCoins, int desiredSum, int i) {
    // Base Condition
    if (desiredSum == 0) return 1;
    if (desiredSum < 0) return 0;

    int count = 0;
    for (int i = 0; i < availableCoins.size(); i++) {
        count += countAllSuchPaths(availableCoins, desiredSum - availableCoins[i], i);
    }
    return count;
}

int main() {
    int n;
    int desiredSum;
    cin >> n >> desiredSum; 
    vector<int> availableCoins(n);
    for (int i = 0; i < n; i++) cin >> availableCoins[i];
    cout << countAllSuchPaths(availableCoins, desiredSum,0) << endl;
    return 0;
}
