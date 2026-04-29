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
        void preorder_sum(TreeNode *root,int &targetSum , int &sum,vector<vector<int>> &ans, vector<int> path){
        if(root == NULL){
            return ;

        } 
        sum = sum +root->val;
        path.push_back(root->val);

        if(root->left == NULL  && root->right == NULL && sum ==targetSum) ans.push_back(path);

        preorder_sum(root->left,targetSum,sum, ans, path );

        preorder_sum(root->right,targetSum ,sum, ans, path);

        sum -= root->val;
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        int sum = 0;

        vector<vector<int>> ans;

        vector<int> path;

        preorder_sum(root, targetSum, sum, ans, path);
        return ans;
    }
};