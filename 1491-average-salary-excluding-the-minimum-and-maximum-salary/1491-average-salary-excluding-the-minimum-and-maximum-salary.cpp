class Solution {
public:
    double average(vector<int>& salary) {
        
        int mini = INT_MAX , maxi = INT_MIN;
        
        for(auto a : salary) {
            mini = min(mini , a);
            maxi = max(maxi , a);
        }
        
        double ans = 0.0;
        for(auto a : salary) 
            if(a != mini && a != maxi)
                ans += a;
        
        double n = salary.size() - 2.0;
        
        return (ans / n);
    }
};