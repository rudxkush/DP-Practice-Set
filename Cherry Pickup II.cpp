/*
    Author: rudxkush
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int rows = 0, cols = 0;

int pickUpMaximumCherries(vector<vector<int>>& cherries, int currentRow, int currentColumn1, int currentColumn2) {
    // Base condition
    if (currentRow == rows - 1) {
        if (currentColumn1 == currentColumn2) {
            return cherries[currentRow][currentColumn1];
        } else {
            return cherries[currentRow][currentColumn1] + cherries[currentRow][currentColumn2];
        }
    }

    // Movements allowed: Down, Down Right, Down Left
    int maxCherries = INT_MIN;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            int ncol1 = currentColumn1 + i;
            int ncol2 = currentColumn2 + j;
            if (ncol1 >= cols || ncol1 < 0 || ncol2 >= cols || ncol2 < 0)
                continue;
            int next = pickUpMaximumCherries(cherries, currentRow + 1, ncol1, ncol2);
            int curr = (currentColumn1 == currentColumn2) ?
                        cherries[currentRow][currentColumn1] :
                        cherries[currentRow][currentColumn1] + cherries[currentRow][currentColumn2];
            maxCherries = max(maxCherries, curr + next);
        }
    }
    return maxCherries;
}

int main() {
    vector<vector<int>> cherries = {{3,1,1}, {2,5,1}, {1,5,5}, {2,1,1}};
    // Ask: Return the maximum number of unique cherries both can collect by the time they reach the last row
    rows = cherries.size();
    cols = cherries[0].size();
    // Robot1 begins at (0, 0) and Robot2 begins at (0, cols - 1).
    // As each move takes them one row down, their current row is always the same
    cout <<  pickUpMaximumCherries(cherries, 0, 0, cols - 1) << endl;
}
