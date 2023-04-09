class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        int n = colors.size();
        vector<vector<int>> adj_list(n);
        vector<int> indegree(n , 0);
        
        for(auto a : edges) {
            indegree[a[1]]++;
            adj_list[a[0]].push_back(a[1]);
        }
        
        queue<int> q;
        
        vector<vector<int>> dp(n , vector<int>(26 , 0));
        
        for(int i = 0 ; i < n ; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                dp[i][colors[i] - 'a'] = 1;
            }
        }
        
        int visited = 0;
        
        int ans = INT_MIN;

        while(!q.empty()) {
            auto u = q.front();
            q.pop();
            visited++;
            for(auto v : adj_list[u]) {
                for(int color = 0 ; color < 26 ; color++)
                    dp[v][color] = max(dp[v][color] , dp[u][color] + (colors[v] - 'a' == color ? 1 : 0));
                indegree[v] -= 1;
                if(indegree[v] == 0)
                    q.push(v);
            }
            ans = max(ans , *max_element(dp[u].begin() , dp[u].end()));
        }
        
        return (visited == n ? ans : -1);
    }
};