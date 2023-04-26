class Solution {
public:
    int addDigits(int num) {
        
        string s = to_string(num);
        
        int curr = 0;
        
        for(int i = s.size() - 1 ; i >= 0 ; i--) {
            curr += (s[i] - '0');
            if(curr >= 10)
                curr = (curr % 10) + (curr / 10);
        }
        
        return curr;
    }
};