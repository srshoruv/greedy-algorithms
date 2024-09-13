#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<double, int> p1, pair<double, int> p2) {
    return p1.first > p2.first;
}

void fracKnap(vector<int> price, vector<int> weight, int w) {
    int n = price.size();
    int ans = 0;
    vector<pair<double, int>> ratio(n, make_pair(0.0,0));;

    for(int i=0; i<n; i++) {
        double r = price[i] / (double) weight[i];
        ratio[i] = make_pair(r, i); 
    }

    sort(ratio.begin(), ratio.end(), compare);

    for(int i=0; i<n; i++) {
        int idx = ratio[i].second;
        if (weight[idx]  <= w) {
            ans += price[idx];
            w -= weight[idx];
        } else {
            ans += (ratio[i].first * w);
            w = 0;
        }
    }

    cout << ans;

}

int main(){
    vector <int> price = {60,100,120};
    vector<int> weight = {10,20,30};
    int w = 50;

    fracKnap(price,weight,w);
}