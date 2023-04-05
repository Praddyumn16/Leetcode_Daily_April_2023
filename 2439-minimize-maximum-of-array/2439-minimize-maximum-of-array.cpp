class Solution {
public:
    bool isPossible(long long x , vector<int>& nums) {
        long long pre_sum = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            pre_sum += nums[i];
            if(pre_sum > (i + 1) * x)
                return false;
        }
        return true;
    }
    
    int minimizeArrayValue(vector<int>& nums) {
        
        int low = 0 , high = *max_element(nums.begin() , nums.end());
        
        while(low <= high) {
            int mid = (low + high) / 2;
            if(isPossible(mid , nums))
                high = mid - 1;
            else
                low = mid + 1;
        }
        
        return low;
    }
};