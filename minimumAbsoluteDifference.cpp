#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> A = {1,2,3,4};
    vector<int> B = {4,3,2,1};

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int ans = 0;

    for (int i=0; i<A.size(); i++) {
        ans += abs(A[i] - B[i]);
    }

    cout << ans;
}