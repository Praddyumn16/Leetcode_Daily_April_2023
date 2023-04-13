class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int i = 0 , j = 0 , n = popped.size();
        stack<int> st;
        
        while(i < n && j < n) {
            while(j < n && !st.empty() && st.top() == popped[j]){
                st.pop();
                j++;
            }
            while(i < n && popped[j] != pushed[i]) {
                st.push(pushed[i]);
                i++;
            }
            j++;
            i++;
        }
        
        while(j < n) {
            if(st.top() != popped[j])
                return false;
            st.pop();
            j++;
        }
        
        return st.empty();
    }
};