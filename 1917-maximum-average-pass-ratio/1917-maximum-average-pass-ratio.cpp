#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Max-Heap to prioritize the class with the maximum potential gain in average
        auto cmp = [](tuple<double, double, double>& a, tuple<double, double, double>& b) {
            double gainA = (get<1>(a) + 1) / (get<2>(a) + 1) - get<1>(a) / get<2>(a);
            double gainB = (get<1>(b) + 1) / (get<2>(b) + 1) - get<1>(b) / get<2>(b);
            return gainA < gainB; // Max-Heap
        };

        priority_queue<tuple<double, double, double>, vector<tuple<double, double, double>>, decltype(cmp)> maxHeap(cmp);

        for (auto& cl : classes) {
            double pass = cl[0];
            double total = cl[1];
            maxHeap.emplace(pass / total, pass, total);
        }

        while (extraStudents--) {
            auto [avg, pass, total] = maxHeap.top();
            maxHeap.pop();
            pass += 1;
            total += 1;
            avg = pass / total;
            maxHeap.emplace(avg, pass, total);
        }

        double ans = 0.0;
        while (!maxHeap.empty()) {
            auto [avg, pass, total] = maxHeap.top();
            maxHeap.pop();
            ans += avg;
        }
        return ans / classes.size();
    }
};
