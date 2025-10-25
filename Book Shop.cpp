#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<vector<int>> dp;

int maximumNumberOfPages(vector<int>& prices, vector<int>& number_of_pages, int i, int x) {
    // Base Condition
    if (x == 0) return 0;
    if (i >= prices.size()) return 0;

    // if already computed
    if (dp[i][x] != -1) return dp[i][x];

    // Inclusion
    int include = 0;
    if (x >= prices[i])
        include = number_of_pages[i] + maximumNumberOfPages(prices, number_of_pages, i + 1,  x - prices[i]);

    // Exclusion
    int exclude = maximumNumberOfPages(prices, number_of_pages, i + 1,  x);

    // Return
    return dp[i][x] = max(include, exclude);
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> prices(n), number_of_pages(n);
    for (int i = 0; i < n; i++)
        cin >> prices[i];

    for (int i = 0; i < n; i++)
        cin >> number_of_pages[i];

    // Ask: Return the maximum number of pages you were able to purchase with 'x' amount by purchasing some books
    // Note: You can buy each book at most once
    dp.clear();
    dp.resize(n, vector<int>(x + 1, -1));
    cout << maximumNumberOfPages(prices, number_of_pages, 0, x);
    return 0;
}
