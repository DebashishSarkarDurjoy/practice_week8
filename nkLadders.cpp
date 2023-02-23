#include <iostream>

using namespace std;

int findWays(int steps, int jumps) {
    if (steps == 0) return 1;
    if (steps < 0) return 0;

    int ans = 0;
    for (int i = 1; i <= jumps; i++) {
        if (steps-i >= 0) {
            ans += findWays(steps-i, jumps);
        }
    }

    return ans;
}

int main(void) {
    int N, S;
    cin >> N >> S;

    cout << findWays(N, S) << endl;


    return 0;
}