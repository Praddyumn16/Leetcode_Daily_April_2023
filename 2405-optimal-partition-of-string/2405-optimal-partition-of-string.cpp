class Solution {
public:
    int partitionString(string s) {
        
        int ans = 0;
        vector<int> seen(26 , 0);

        for(auto ch : s) {
            if(seen[ch - 'a']) {
                ans++;
                seen = vector<int>(26 , 0);
            }
            seen[ch - 'a'] = 1;
        }

        for(auto a : seen)
        {
            if(a == 1) {
                ans++;
                break;
            }
        }

        return ans;
    }
};