#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp;
int countWaysToConstructSum(int number_of_faces, int number_of_dice, int sum) {
    if (sum < 0) return 0;
    if (number_of_dice < 0) return 0;
    if (sum == 0 && number_of_dice == 0) return 1;
    if (dp[number_of_dice][sum] != -1) return dp[number_of_dice][sum];
    int count = 0;
    for (int face = 1; face <= number_of_faces; face++) {
        count += countWaysToConstructSum(number_of_faces, number_of_dice - 1, sum - face);
    }
    return dp[number_of_dice][sum] = count;
}

int main() {
    int number_of_dice, number_of_faces, sum;
    cin >> number_of_faces >> number_of_dice >> sum;
    dp.clear();
    dp.resize(number_of_dice + 1, vector<int>(sum + 1, -1));
    cout << countWaysToConstructSum(number_of_faces, number_of_dice, sum) << endl;
    return 0;
}
