#include <iostream>
#include <vector>
#include <climits>
using namespace std;
const int MOD = 1e9+7;
vector<vector<int>> dp;

int countAllSuchPathsThatReachLowerRightCell(vector<vector<char>> grid, int n, int currRow, int currCol) {
    // Base condition
    if (currRow >= n || currCol >= n || grid[currCol][currRow] == '*')
        return 0;
    if (currRow == n-1 && currCol == n-1)
        return 1;

    // if already pre-computed
    if (dp[currRow][currCol] != -1)
        return dp[currRow][currCol];

    // Explore right
    int right = countAllSuchPathsThatReachLowerRightCell(grid, n, currRow, currCol + 1);

    // Explore bottom
    int bottom = countAllSuchPathsThatReachLowerRightCell(grid, n, currRow + 1, currCol);

    // Return
    return dp[currRow][currCol] = (right + bottom) % MOD;
}

int main() {
    int n;
    cin >> n;
    vector grid(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    // print the given grid
    // cout << "Grid preview: " << endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << grid[i][j];
    //     }
    //     cout << endl;
    // }
    dp.clear();
    dp.resize(n + 1, vector<int>(n + 1, -1));
    cout << countAllSuchPathsThatReachLowerRightCell(grid, n, 0, 0) << endl;
    return 0;
}

/*
    Input: 4
    ....
    .*..
    ...*
    *...

    Output: 3
    Task is to go from (0,0) to (n-1, n-1) by going either right (or) down
    . -> empty cell
    * -> confined cell (trap)
 */
