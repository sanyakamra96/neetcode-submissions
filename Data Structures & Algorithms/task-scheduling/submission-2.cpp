class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> freq;

        for (char t : tasks) {
            freq[t]++;
        }

        // (frequency, time, task)
        priority_queue<tuple<int,int,char>> pq;
        queue<tuple<int,int,char>> cooling;
        // initially all available at time 0
        for (auto &f : freq) {
            pq.push({f.second, 0, f.first});
        }

        int current_time = 0;

        while (!pq.empty()|| !cooling.empty()) {
            //Moving blocked to ready
            while(!cooling.empty()){
                auto [count, nextTime, task] = cooling.front();
                if(nextTime >current_time) break;
                
                pq.push(cooling.front());
                cooling.pop();
                
            }
            //running high frequency task if run then push to cooldown 
            // This is ready heap according to priority.
            if(!pq.empty()){

                auto [count, nextTime, task] = pq.top();
                pq.pop();

                if(nextTime<=current_time){
                    count--;

                    if(count > 0){
                        cooling.push({count, current_time + n + 1, task});
                    }
                }
            }
            


            current_time++;
        }

        return current_time;
    }
};