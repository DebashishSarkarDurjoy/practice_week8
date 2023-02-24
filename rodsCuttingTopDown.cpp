#include <iostream>
#include <vector>
using namespace std;

int maxProfit(int *prices, int n, vector<int> &dp) {
    
    return 10;
}

int main(void) {
    int prices[] = {1,5,8,9,10,17,17,20};
    int n = sizeof(prices) / sizeof(int);

    vector<int> dp(n+1, 0);
    cout << maxProfit(prices, n, dp) << endl;

    return 0;
}