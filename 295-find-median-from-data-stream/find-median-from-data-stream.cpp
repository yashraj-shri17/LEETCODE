class MedianFinder {
public:
    priority_queue<int> pq_max; // left half
    priority_queue<int, vector<int>, greater<int>> pq_min; // right half

    MedianFinder() {}

    void addNum(int num) {
        if (pq_max.empty() || num <= pq_max.top()) {
            pq_max.push(num);
        } else {
            pq_min.push(num);
        }

        // balance the heaps
        if (pq_max.size() > pq_min.size() + 1) {
            pq_min.push(pq_max.top());
            pq_max.pop();
        } else if (pq_min.size() > pq_max.size()) {
            pq_max.push(pq_min.top());
            pq_min.pop();
        }
    }

    double findMedian() {
        if (pq_max.size() == pq_min.size()) {
            return (pq_max.top() + pq_min.top()) / 2.0;
        }
        return pq_max.top();
    }
};
