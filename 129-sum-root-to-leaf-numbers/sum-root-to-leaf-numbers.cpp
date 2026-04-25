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
private:
    void solve(TreeNode* root,int& sum,int n){
        if(root == NULL) return;
        n = n*10 + root->val;
        if(root->right == NULL && root->left == NULL){
            sum += n;
            return;
        }
        solve(root->right,sum,n);
        solve(root->left,sum,n);
    }
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        solve(root,sum,0);
        return sum;
    }
};