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
    void preorder_sum(TreeNode *root,int &targetSum , int &sum,bool &ans){
        if(root == NULL){
            return ;

        } 
        // arr.push_back(root->val);
        sum = sum +root->val;
        if(root->left == NULL  && root->right == NULL && sum ==targetSum) ans =true;

        preorder_sum(root->left,targetSum,sum, ans );

        preorder_sum(root->right,targetSum ,sum, ans);

        sum -= root->val;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum =0;
        // vector <int> arr; not requied for this 
        bool ans = false;
        preorder_sum(root,targetSum,sum, ans);
        return ans;
    }
};