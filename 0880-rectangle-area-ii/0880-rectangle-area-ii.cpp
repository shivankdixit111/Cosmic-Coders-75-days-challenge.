#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class SegmentTree {
public:
    map<int, int> cnts;
    map<int, int> total;
    vector<int> xs;

    SegmentTree(vector<int>& xs) : xs(xs) {}

    int update(int v, int tl, int tr, int l, int r, int h) {
        if (l > r) return 0;
        if (l == tl && r == tr) {
            cnts[v] += h;
        } else {
            int tm = (tl + tr) / 2;
            update(v * 2, tl, tm, l, min(r, tm), h);
            update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, h);
        }

        if (cnts[v] > 0) {
            total[v] = xs[tr + 1] - xs[tl];
        } else {
            total[v] = total[v * 2] + total[v * 2 + 1];
        }
        return total[v];
    }
};

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        set<int> xset;
        for (auto& rect : rectangles) {
            xset.insert(rect[0]);
            xset.insert(rect[2]);
        }

        vector<int> xs(xset.begin(), xset.end());
        map<int, int> xs_i;
        for (int i = 0; i < xs.size(); ++i) {
            xs_i[xs[i]] = i;
        }

        vector<vector<int>> events;
        for (auto& rect : rectangles) {
            events.push_back({rect[1], 1, rect[0], rect[2]});
            events.push_back({rect[3], -1, rect[0], rect[2]});
        }
        sort(events.begin(), events.end());

        SegmentTree STree(xs);
        long long cur_y = 0, cur_x_sum = 0, area = 0;
        const int MOD = 1e9 + 7;

        for (auto& event : events) {
            int y = event[0], op_cl = event[1], x1 = event[2], x2 = event[3];
            area = (area + (y - cur_y) * cur_x_sum) % MOD;
            cur_y = y;
            STree.update(1, 0, xs.size() - 1, xs_i[x1], xs_i[x2] - 1, op_cl);
            cur_x_sum = STree.total[1];
        }

        return area;
    }
};
