class Solution {
public:
    bool isSimilar(string a , string b) {
        int count = 0;
        for(int i = 0 ; i < a.size() ; i++)
            if(a[i] != b[i])
                count++;
        return count <= 2;
    }
    
    void dfs(string curr ,vector<string>& v , unordered_map<string , bool>& visited) {

        visited[curr] = 1;

        for(auto temp : v) {
            if(isSimilar(temp , curr)){
                if(!visited[temp]) {
                    dfs(temp , v , visited);
                }
            }
        }

    }

    int numSimilarGroups(vector<string>& strs) {

        int ans = 0 , n = strs.size(); 
        
        unordered_map<string , bool> visited;

        for(auto curr : strs) {
            if(!visited[curr]) {
                dfs(curr , strs , visited);
                ans++;
            }
        }

        return ans;
    }
};