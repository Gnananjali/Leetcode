
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<long long> low, high;
        long long sumLow = 0, sumHigh = 0;

        auto balance = [&]() {
            while (low.size() > (x + 1) / 2) {
                long long v = *low.rbegin();
                low.erase(prev(low.end()));
                sumLow -= v;
                high.insert(v);
                sumHigh += v;
            }

            while (low.size() < (x + 1) / 2 && !high.empty()) {
                long long v = *high.begin();
                high.erase(high.begin());
                sumHigh -= v;
                low.insert(v);
                sumLow += v;
            }

            while (!low.empty() && !high.empty() &&
                   *low.rbegin() > *high.begin()) {
                long long a = *low.rbegin();
                long long b = *high.begin();

                low.erase(prev(low.end()));
                high.erase(high.begin());

                sumLow += b - a;
                sumHigh += a - b;

                low.insert(b);
                high.insert(a);
            }
        };

        auto add = [&](long long v) {
            if (low.empty() || v <= *low.rbegin()) {
                low.insert(v);
                sumLow += v;
            } else {
                high.insert(v);
                sumHigh += v;
            }
            balance();
        };

        auto remove = [&](long long v) {
            auto it = low.find(v);

            if (it != low.end()) {
                low.erase(it);
                sumLow -= v;
            } else {
                it = high.find(v);
                high.erase(it);
                sumHigh -= v;
            }

            balance();
        };

        vector<long long> cost(n - x + 1);

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                long long median = *low.rbegin();

                cost[i - x + 1] =
                    median * low.size() - sumLow +
                    sumHigh - median * high.size();
            }
        }

        const long long INF = 4e18;

        vector<long long> prev(n + 1, 0), curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {
                curr[i] = curr[i - 1];

                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            swap(prev, curr);
        }

        return prev[n];
    }
};
