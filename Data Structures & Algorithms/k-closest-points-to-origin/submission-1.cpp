class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        // max heap: {distance, point}
        priority_queue<pair<int, vector<int>>> pq;

        for (auto &p : points) {

            int dist = p[0]*p[0] + p[1]*p[1];

            pq.push({dist, p});

            if (pq.size() > k) {
                pq.pop(); // remove farthest
            }
        }

        vector<vector<int>> result;

        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};