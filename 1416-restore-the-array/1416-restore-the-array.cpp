class Solution {
public:
    int mod = 1e9 + 7;
    
    int solve(int i , string&s , int k , vector<int>& dp) {
        
        if(i == s.size())
            return 1;
        
        if(dp[i] != -1)
            return dp[i];
        
        if(s[i] == '0')
            return 0;
        else {
            int ans = 0;
            string curr = "";
            for(int j = i ; j < s.size() ; j++) {
                curr += s[j];
                if(stol(curr) > k)
                    break;
                ans += solve(j + 1 , s , k , dp);
                ans %= mod;
            }
            return dp[i] = ans;
        }
    }
    
    int numberOfArrays(string s, int k) {
        
        vector<int> dp(s.size() , -1);
        return solve(0 , s , k , dp);
    }
};