#include <iostream>
#include <vector>
using namespace std;

void minChange(vector<int> coins, int V) {
    int ans = 0;
    int n = coins.size();

    for (int i = n-1; i>=0 && V > 0; i--) {
        if (coins[i]<= V) {
            ans += V / coins[i];
            V = V%coins[i];
        }
    }

    cout << "Minimum change required: " << ans << endl;
}

int main(){
    vector<int> coins = {1,2,5,10,20,50,100,500,2000};
    int V = 590;
    minChange(coins, V);
}