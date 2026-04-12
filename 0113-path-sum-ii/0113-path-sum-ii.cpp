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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        //宣告陣列儲存"路徑陣列"
        vector<vector<int>> result;
        vector<int> currentPath;

        dfs(root, targetSum, currentPath, result);
        return result;
    }
private:
    void dfs(TreeNode* node, int targetSum, vector<int>& currentPath, vector<vector<int>>& result){
        if(!node) return;

        currentPath.push_back(node->val);
        
        if(!node->left && !node->right && targetSum==node->val){
            result.push_back(currentPath);
        }

        dfs(node->left, targetSum-node->val, currentPath, result);
        dfs(node->right, targetSum-node->val, currentPath, result);

        currentPath.pop_back();
    }
};