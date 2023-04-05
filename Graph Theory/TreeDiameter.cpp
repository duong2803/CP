class Solution {
public:
    
    int res = 0;
    int dfs(TreeNode* root){
        if(!root) return -1;
        int left = dfs(root->left);
        int right = dfs(root->right);
        res = max(res, left + right + 2);
        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;
    }
};
