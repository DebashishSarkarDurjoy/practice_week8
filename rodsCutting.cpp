#include <iostream>
using namespace std;

int maxProfit(int *prices, int n) {
    int dp[n+1];
    dp[0] = 0;

    for (int len = 1; len <= n; len++) {
        int ans = INT_MIN;
        for (int i = 0; i < len; i++) {
            int cut = i + 1;
            int current_ans = prices[i] + dp[len-cut];
            ans = max(current_ans, ans);
        }
        dp[len] = ans;
    }

    return dp[n];
}

int main(void) {
    int prices[] = {1,5,8,9,10,17,17,20};
    int n = sizeof(prices) / sizeof(int);

    cout << maxProfit(prices, n) << endl;

    return 0;
}