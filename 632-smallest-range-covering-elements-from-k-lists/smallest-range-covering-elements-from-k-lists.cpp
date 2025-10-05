class Solution {
public:
    typedef pair<int, pair<int, int>> Node;  // {value, {listIndex, elementIndex}}

    vector<int> smallestRange(vector<vector<int>>& lists) {
        int k = lists.size();
        if (k == 0) return {};

        priority_queue<Node, vector<Node>, greater<Node>> minHeap;
        int currentMax = INT_MIN;

        // Step 1: Initialize heap with the first element from each list
        for (int i = 0; i < k; i++) {
            if (lists[i].empty()) return {};
            minHeap.push({lists[i][0], {i, 0}});
            currentMax = max(currentMax, lists[i][0]);
        }

        int bestStart = -1, bestEnd = INT_MAX;
        int smallestRange = INT_MAX;

        // Step 2: Process the heap
        while (true) {
            auto [currentMin, indices] = minHeap.top();
            minHeap.pop();
            int listIndex = indices.first;
            int elementIndex = indices.second;

            // Update best range if smaller found
            if (currentMax - currentMin < smallestRange) {
                smallestRange = currentMax - currentMin;
                bestStart = currentMin;
                bestEnd = currentMax;
            }

            // Stop if we've reached the end of one list
            if (elementIndex + 1 == lists[listIndex].size()) break;

            int nextValue = lists[listIndex][elementIndex + 1];
            minHeap.push({nextValue, {listIndex, elementIndex + 1}});
            currentMax = max(currentMax, nextValue);
        }

        return {bestStart, bestEnd};
    }
};
