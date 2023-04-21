class Solution {
public:
    int mod = 1e9 + 7 , min_profit;
    int dp[101][101][101];
    
    int solve(int i , int rem_members , int curr_profit , vector<int>& group, vector<int>& profit) {
        
        if(i == profit.size())
            return dp[i][rem_members][curr_profit] = (curr_profit == min_profit);
        

        if(dp[i][rem_members][curr_profit] != -1)
            return dp[i][rem_members][curr_profit];
        
        int pick = 0 , not_pick = 0;

        if(group[i] <= rem_members)
            pick = solve(i + 1 , rem_members - group[i] , min(curr_profit + profit[i] , min_profit) , group , profit);
        
        not_pick = solve(i + 1 , rem_members , curr_profit , group , profit);
        
        return dp[i][rem_members][curr_profit] = (pick + not_pick) % mod;
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
    
        memset(dp , -1 , sizeof(dp));
        min_profit = minProfit;

        return solve(0 , n , 0 , group , profit);
    }
};