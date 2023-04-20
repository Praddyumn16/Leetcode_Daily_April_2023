/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode* , int>> q;
        q.push({root , 1});
        
        long long ans = 0;
        
        while(!q.empty()) {
            
            int size = q.size();
            long long mini , maxi;
            
            for(int i = 0 ; i < size ; i++) {
                
                auto curr = q.front();
                q.pop();
                
                long long idx = curr.second;
                
                if(curr.first->left)
                    q.push({curr.first->left , 2 * idx + 1});
                if(curr.first->right)
                    q.push({curr.first->right , 2 * idx + 2});
                
                if(i == 0)
                    mini = curr.second;
                if(i == size - 1)
                    maxi = curr.second;
            }
            
            ans = max(ans , maxi - mini);
        }
        
        return ans + 1;
    }
};
