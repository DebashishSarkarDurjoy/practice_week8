#include <iostream>
#include <vector>

using namespace std;

// bottom up
int minCoinChange(vector<int> &denoms, int change) {
    vector<int> dp(change+1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= change; i++) {
        for (int c: denoms) {
            if (i - c >= 0 && dp[i-c] != INT_MAX) {
                dp[i] = min(dp[i-c]+1, dp[i]);
            }
        }
    }
    
    return dp[change] != INT_MAX ? dp[change] : -1;
}

int main(void) {
    vector<int> denoms = {1,5,7,10};
    cout << minCoinChange(denoms, 16) << endl;

    return 0;
}