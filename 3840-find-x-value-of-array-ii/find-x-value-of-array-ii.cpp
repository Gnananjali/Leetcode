class Solution {
public:
    struct Node {
        int prod = 0;
        long long cnt[5] = {0, 0, 0, 0, 0};
    };

    int n, k, size;
    vector<Node> seg;

    Node mergeNode(const Node& A, const Node& B) {
        Node res;

        res.prod = (A.prod * B.prod) % k;

        for (int r = 0; r < k; r++) {
            res.cnt[r] += A.cnt[r];
        }

        for (int r = 0; r < k; r++) {
            int nr = (A.prod * r) % k;
            res.cnt[nr] += B.cnt[r];
        }

        return res;
    }

    Node makeNode(int val) {
        Node res;
        int r = val % k;
        res.prod = r;
        res.cnt[r] = 1;
        return res;
    }

    void update(int pos, int val) {
        pos += size;
        seg[pos] = makeNode(val);

        pos /= 2;

        while (pos >= 1) {
            seg[pos] = mergeNode(seg[pos * 2], seg[pos * 2 + 1]);
            pos /= 2;
        }
    }

    Node rangeQuery(int l, int r) {
        Node leftRes, rightRes;
        bool hasLeft = false, hasRight = false;

        l += size;
        r += size;

        while (l < r) {
            if (l & 1) {
                if (!hasLeft) {
                    leftRes = seg[l];
                    hasLeft = true;
                } else {
                    leftRes = mergeNode(leftRes, seg[l]);
                }
                l++;
            }

            if (r & 1) {
                --r;

                if (!hasRight) {
                    rightRes = seg[r];
                    hasRight = true;
                } else {
                    rightRes = mergeNode(seg[r], rightRes);
                }
            }

            l /= 2;
            r /= 2;
        }

        if (!hasLeft)
            return rightRes;

        if (!hasRight)
            return leftRes;

        return mergeNode(leftRes, rightRes);
    }

    vector<int> resultArray(vector<int>& nums,
                            int k,
                            vector<vector<int>>& queries) {
        this->n = nums.size();
        this->k = k;

        size = 1;
        while (size < n)
            size *= 2;

        seg.resize(2 * size);

        for (int i = 0; i < n; i++) {
            seg[size + i] = makeNode(nums[i]);
        }

        for (int i = size - 1; i >= 1; i--) {
            seg[i] = mergeNode(seg[i * 2], seg[i * 2 + 1]);
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            update(index, value);

            Node res = rangeQuery(start, n);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};