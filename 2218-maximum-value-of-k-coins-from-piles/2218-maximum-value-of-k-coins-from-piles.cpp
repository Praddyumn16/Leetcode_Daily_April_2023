class Solution {
public:
    
    int solve(vector<vector<int>>& piles, int i , int rem , vector<vector<int>>& dp) {
        if(i == piles.size() || rem <= 0)
            return 0;
        
        if(dp[i][rem] != -1)
            return dp[i][rem];
        
        int ans = INT_MIN , n = piles[i].size() ,curr = 0;
        
        for(int j = 0 ; j <= min(rem , n) ; j++) {
            int temp = solve(piles , i + 1 , rem - j , dp);
            if(j > 0)
                curr += piles[i][j - 1];
            ans = max(ans , curr + temp);
        }
        
        return dp[i][rem] = ans;
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> dp(piles.size() , vector<int>(k + 1 , -1));
        return solve(piles , 0 , k , dp);
    }
};