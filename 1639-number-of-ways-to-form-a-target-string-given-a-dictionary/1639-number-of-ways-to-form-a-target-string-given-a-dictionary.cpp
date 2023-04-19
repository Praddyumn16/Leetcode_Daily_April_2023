class Solution {
public:
    int mod = 1e9 + 7;
    
    long long solve(vector<vector<int>>& count , vector<string>& words, string& target , int col , int idx , vector<vector<int>>& dp) {
        if(idx == target.size())
            return 1;
        if(col == words[0].size())
            return 0;
        
        if(dp[col][idx] != -1)
            return dp[col][idx];
        
        long long not_pick = solve(count , words , target , col + 1 , idx , dp);
        long long pick = 0 , next = solve(count , words , target , col + 1 , idx + 1 , dp);
        
        pick = (next * count[col][target[idx] - 'a']) % mod;
        
        return dp[col][idx] = (pick + not_pick) % mod;
    }
    
    
    int numWays(vector<string>& words, string target) {
        
        int n = words.size() , m = words[0].size();
        
        vector<vector<int>> count(m , vector<int>(26 , 0));
        vector<vector<int>> dp(m , vector<int>(target.size() , -1));
        
        for(auto word : words)
            for(int i = 0 ; i < m ; i++)
                count[i][word[i] - 'a']++;
        
        return solve(count , words , target , 0 , 0 , dp);
        
    }
};