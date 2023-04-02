class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        vector<int> ans;
        sort(potions.begin() , potions.end());
        
        for(auto spell : spells) {
            long long req = (ceil)(success * 1.0 / spell);
            auto pos = lower_bound(potions.begin() , potions.end() , req);
            ans.push_back(potions.end() - pos);
        } 
        
        return ans;
    }
};