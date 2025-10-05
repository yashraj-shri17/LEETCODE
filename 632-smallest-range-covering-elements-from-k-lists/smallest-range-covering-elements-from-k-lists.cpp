class Solution {
public:
    typedef pair<int, pair<int, int>> Node; 

    vector<int> smallestRange(vector<vector<int>>& lists) {
        int k = lists.size();
        if (k == 0) return {};

        priority_queue<Node, vector<Node>, greater<Node>> pq;
        int currMax = INT_MIN;
        for (int i = 0; i < k; i++) {
            if (lists[i].empty()) return {};
            pq.push({lists[i][0], {i, 0}});
            currMax = max(currMax, lists[i][0]);
        }

        int bestStart = -1, bestEnd = INT_MAX;
        int smallestRange = INT_MAX;
        while (true) {
            auto [currMin, indices] = pq.top();
            pq.pop();
            int row = indices.first;
            int col = indices.second;
            if (currMax - currMin < smallestRange) {
                smallestRange = currMax - currMin;
                bestStart = currMin;
                bestEnd = currMax;
            }

            if (col + 1 == lists[row].size()) break;

            int nextValue = lists[row][col + 1];
            pq.push({nextValue, {row, col + 1}});
            currMax = max(currMax, nextValue);
        }

        return {bestStart, bestEnd};
    }
};
