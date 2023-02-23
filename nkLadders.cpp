#include <iostream>

using namespace std;

// top down
int findWays(int steps, int jumps, int dp[]) {
    if (steps == 0) return 1;
    if (steps < 0) return 0;
    if (dp[steps] != 0) return dp[steps];

    int ans = 0;
    for (int i = 1; i <= jumps; i++) {
        if (steps-i >= 0) {
            ans += findWays(steps-i, jumps, dp);
        }
    }

    dp[steps] = ans;
    return dp[steps];
}

int main(void) {
    int N, S;
    cin >> N >> S;

    int dp[100] = {0};

    cout << findWays(N, S, dp) << endl;


    return 0;
}