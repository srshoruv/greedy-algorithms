#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Job{
public:
    int idx;
    int deadline;
    int profit;

    Job(int idx, int deadline, int profit){
        this->idx = idx;
        this->deadline = deadline;
        this->profit = profit;
    }

};

int maxProf(vector<pair<int, int>> pairs) {
    vector<Job> jobs;

    for (int i=0; i<pairs.size(); i++) {
        jobs.emplace_back(i, pairs[i].first, pairs[i].second);
    }

    sort(jobs.begin(), jobs.end(), [](Job &a, Job &b) {
        return a.profit > b.profit;
    });

    cout << "Done Job" << jobs[0].idx<< endl;
    int profit = jobs[0].profit;
    int deadline = 2;

    for (int i=1; i<pairs.size(); i++) {
        if (jobs[i].deadline >= deadline) {
            cout << "Done Job" << jobs[i].idx << endl;
            profit += jobs[i].profit;
            deadline++;
        }
    }
    cout << "Total profit: " << profit << endl;
}

int main(){
    int n = 4;
    vector<pair<int, int>> jobs(n, make_pair(0,0));
    jobs[0] = make_pair(4,20);
    jobs[1] = make_pair(1,10);
    jobs[2] = make_pair(1,40);
    jobs[3] = make_pair(1,30);

    maxProf(jobs);
}