class Solution {
public:
    string removeStars(string s) {
        
        stack<char> st;
        string ans = "";
        
        int i = 0 , n = s.size();
        
        while(i < n) {
            if(s[i] == '*') {
                int len = 0;
                while(i < n && s[i] == '*')
                    i++ , len++;
                while(len--)
                    st.pop();
            }
            else
                st.push(s[i++]);
        }
        
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin() , ans.end());
        return ans;
    }
};