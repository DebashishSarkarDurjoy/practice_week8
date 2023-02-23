#include <iostream>
#include <vector>

using namespace std;

// top down
int minCoinChange(vector<int> &denoms, int change, vector<int> &dp) {
    // base case
    if (change == 0) return 0;
    if (change < 0) return 0;
    if (dp[change] != INT_MAX) return dp[change];

    int ans = INT_MAX;
    for (int c: denoms) {
        if (change - c >= 0) {
            ans = min( ans, minCoinChange(denoms, change-c, dp) + 1 );
        }
    }
   
    dp[change] = ans;
    return dp[change];
}

int main(void) {
    vector<int> denoms = {1,5,7,10};
    vector<int> dp(16+1, INT_MAX);
    dp[0] = 0;
    cout << minCoinChange(denoms, 16, dp) << endl;

    return 0;
}