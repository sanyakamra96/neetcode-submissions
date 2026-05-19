class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> result(temperatures.size(), 0);
        for(int i = 0; i<temperatures.size(); i++){
            
            while(!st.empty()){
                if(temperatures[i]>temperatures[st.top()]){
                    int prev = st.top();
                    result[prev] = i - prev;
                    
                    st.pop();
                }
                else break;

            }
            st.push(i);
        }
        return result;
    }
    };
