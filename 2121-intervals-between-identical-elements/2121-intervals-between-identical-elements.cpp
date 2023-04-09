class Solution {
public:
    vector<long long> getDistances(vector<int>& nums) {
        unordered_map<int , vector<int>> mp;        
        unordered_map<int , long long> mp1;

        int n = nums.size();
        
        vector<long long> ans(n , 0);
        
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]].push_back(i);            
            mp1[nums[i]] += i;
        }
        
        for(auto a : mp)
        {
            long long n1 = a.second.size();
            if(n1 == 1)
                continue;
            long long rem = mp1[a.first] , curr = 0 , i = 1;
            
            for(auto idx : a.second) {
                rem -= idx;
                long long left = (((i - 1) * idx) - curr);
                long long right = (rem - ((n1 - i) * idx));
                ans[idx] = left + right;
                curr += idx;
                i++;
            }
        }
        
        return ans;
    }
};