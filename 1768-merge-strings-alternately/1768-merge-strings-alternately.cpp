class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int i = 0 , j = 0 , n1 = word1.size() , n2 = word2.size();
        bool flag = 1;
        
        string ans = "";
        
        while(i < n1 && j < n2) {
            ans += (flag ? word1[i++] : word2[j++]);
            flag = !flag;
        }
        
        if(i < n1)
            ans.append(word1.substr(i));
        else if(j < n2)
            ans.append(word2.substr(j));
        
        return ans;
    }
};