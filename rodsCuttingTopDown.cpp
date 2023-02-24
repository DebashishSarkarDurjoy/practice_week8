#include <iostream>
#include <vector>
using namespace std;

int maxProfit(int *prices, int n, vector<int> &dp) {
    if (n == 0) return 0;
    if (n < 0) return 0;
    if (dp[n] != 0) return dp[n];

    int ans = INT_MIN;
    for (int i = 1; i <= n; i++) {
        int current = prices[i-1] + maxProfit(prices, n-i, dp);
        ans = max(ans, current);
    }
    dp[n] = ans;
    return dp[n];
}

int main(void) {
    int prices[] = {1,5,8,9,10,17,17,20};
    int n = sizeof(prices) / sizeof(int);

    vector<int> dp(n+1, 0);
    cout << maxProfit(prices, n, dp) << endl;

    return 0;
}