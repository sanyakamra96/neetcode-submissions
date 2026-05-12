class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>,
                       vector<pair<int, vector<int>>>,
                       greater<pair<int, vector<int>>>> pq;

        for(vector<int> point:points){
            int val = point[0]*point[0]+point[1]*point[1];
            pq.push({val,point});
            
        }
        vector<vector<int>>  result;
        while(k--){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};