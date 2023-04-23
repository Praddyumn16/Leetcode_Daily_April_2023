class Solution {
public:
    int mod = 1e9 + 7;
    
    int solve(int i , string curr , string& s , int k , vector<unordered_map<string , int>>& dp) {
        
        if(i == s.size())
            return (stol(curr) <= k);
        
        if(dp[i].count(curr))
            return dp[i][curr];
        
        int add = 0 , not_add = 0;
        
        if(stol(curr + s[i]) <= k)
            add = solve(i + 1 , curr + s[i] , s , k , dp);
        
        if(curr != "" && s[i] != '0')
            not_add = solve(i + 1 , string(1 , s[i]) , s , k , dp);
        
        return dp[i][curr] = (add + not_add) % mod;
    }
    
    int numberOfArrays(string s, int k) {
        
        vector<unordered_map<string , int>> dp(s.size());
        return solve(1 , string(1 , s[0]) , s , k , dp);
    }
};