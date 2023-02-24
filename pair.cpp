#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<pair<int,int>> findPairs(vector<int> nums, int target) {
    unordered_set<int> bag;
    vector<pair<int,int>> result;
    for (int n: nums) {
        if ( bag.find(abs(n-target)) != bag.end() ) {
            result.push_back({abs(n-target), n});
        }
        else {
            bag.insert(n);
        }
    }
    return result;
}

int main(void) {
    vector<int> numbers = {10,5,2,3,13, 14, -6,9,11};

    for (auto pair: findPairs(numbers, 16)) {
        cout << "(" << pair.first << ", " << pair.second << ")" << endl;
    }
    return 0;
}