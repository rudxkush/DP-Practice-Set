#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<int> dp;
int minimumStepsToReachZero(int n) {
    if (n == 0)
        return 0;
 
    if (dp[n] != -1) return dp[n];
 
    int original = n;
    int minSteps = INT_MAX;
    while (n) {
        int unitDigit = n % 10;
        if (unitDigit != 0) minSteps = min(1 + minimumStepsToReachZero(original - unitDigit), minSteps);
        n = n / 10;
    }
 
    return dp[original] = minSteps;
}
 
int main() {
    int n;
    cin >> n;
    dp.clear();
    dp.resize(n + 1, -1);
    cout << minimumStepsToReachZero(n) << endl;
    return 0;
}
