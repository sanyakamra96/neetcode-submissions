class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int vl;

public:

    KthLargest(int k, vector<int>& nums) {
        vl = k;

        for(int num : nums) {
            pq.push(num);

            if(pq.size() > vl) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);

        if(pq.size() > vl) {
            pq.pop();
        }

        return pq.top();
    }
};