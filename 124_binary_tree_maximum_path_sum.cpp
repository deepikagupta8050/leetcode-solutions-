class Solution {
public:

    int ans = INT_MIN;

    int solve(TreeNode* root) {

        if (root == NULL) {
            return 0;
        }

        int left = max(0, solve(root->left));
        int right = max(0, solve(root->right));

        ans = max(ans, left + right + root->val);

        return max(left, right) + root->val;
    }

    int maxPathSum(TreeNode* root) {

        solve(root);

        return ans;
    }
};