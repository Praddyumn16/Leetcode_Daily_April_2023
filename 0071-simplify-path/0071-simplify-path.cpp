class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string> st;
        string curr = "";
        int i = 1 , n = path.size();
        
        while(i < n) {
            while(i < n && path[i] != '/')
                curr += path[i++];
            while(i < n && path[i] == '/')
                i++;
            
            if(curr == "." || curr == ""){
                curr = "";
                continue;
            }
            else if(curr == ".."){
                if(!st.empty())
                    st.pop();
            }
            else 
                st.push(curr);
            curr = "";
        }
        
        
        if(curr != "")
            st.push(curr);
        
        string ans = "";

        while(!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        return (ans == "" ? "/" : ans);
    }
};