/*
    Author: rudxkush
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

vector<int> dp;
int countWaysToConstructSum(int currSum, int n) {
  if(currSum > n) 
    return 0;
  
  if(currSum == n) 
    return 1;
  
  if(dp[currSum] != -1) 
    return dp[currSum];
  
  
  int count = 0;
  for(int i = 1; i <= 6; i++) {
    count = (count + countWaysToConstructSum(currSum + i, n)) % MOD;
  }
  
  return dp[currSum] = count;
}

int main() {
  int n;
  cin >> n;
  dp.resize(n + 1, -1);
  cout << countWaysToConstructSum(0, n) << endl;
  return 0;
}
