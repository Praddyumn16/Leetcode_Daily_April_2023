class Solution {
public:
    vector<int> parent , rank;
    
    int find(int a) {
        return parent[a] = (parent[a] == a ? a : find(parent[a]));
    }
    
    void Union(int a , int b) {
        int parent_a = find(a) , parent_b = find(b);
        if(parent_a != parent_b) {
            (rank[parent_a] < rank[parent_b]) ? (parent[parent_a] = parent_b) : (parent[parent_b] = parent_a);
            rank[parent_a] += (rank[parent_a] == rank[parent_b]);
        }
    }
    
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        
        int m = queries.size();
        vector<bool> ans(m , 0);
        
        for(int i = 0 ; i < m ; i++)
            queries[i].push_back(i);
        
        sort(queries.begin() , queries.end() , [&](auto const &a , auto const &b){
            return a[2] < b[2];
        });
        
        sort(edgeList.begin() , edgeList.end() , [&](auto const &a , auto const &b){
            return a[2] < b[2];
        });
        
        int j = 0;
        
        parent.resize(n , 0);
        
        for(int i = 0 ; i < n ; i++)
            parent[i] = i;
        
        rank.resize(n , 0);
        
        for(auto query : queries) {
            
            while(j < edgeList.size() && edgeList[j][2] < query[2]) {
                Union(edgeList[j][0] , edgeList[j][1]);
                j++;
            }
            
            if(find(query[0]) == find(query[1]))
                ans[query[3]] = 1;
        }
        
        return ans;
    }
};