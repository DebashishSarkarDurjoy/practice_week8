#include <iostream>

using namespace std;

// bottom up
int findWays(int steps, int jumps) {
    int dp[100] = {0};
    dp[0] = 1;
    for (int i = 1; i <= steps; i++) {
        for (int j = 1; j <= jumps; j++){
             if (i-j >= 0) {
                dp[i] += dp[i-j];
            }
        }
    }

    return dp[steps];
}

int main(void) {
    int N, S;
    cin >> N >> S;

    cout << findWays(N, S) << endl;


    return 0;
}