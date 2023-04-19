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
    void solve(TreeNode* curr , bool prev_dir , int nodes , int& ans) {
        if(!curr){
            ans = max(ans , nodes - 1);
            return;
        }
        
        if(prev_dir) { // go left
            solve(curr->left , 0 , nodes + 1 , ans);
            solve(curr->right , 1 , 1 , ans);
        }
        else { // go right
            solve(curr->right , 1 , nodes + 1 , ans);
            solve(curr->left , 0 , 1 , ans);
        }
    }
    
    
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        solve(root->left , 0 , 1 , ans);
        solve(root->right , 1 , 1 , ans);
        return ans;
    }
};