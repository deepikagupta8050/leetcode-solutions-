class Solution {
public:
    vector<TreeNode*> solve(int n) {
        vector<TreeNode*> ans;

        if (n == 1) {
            ans.push_back(new TreeNode(0));
            return ans;
        }

        for (int left = 1; left < n; left += 2) {
            int right = n - 1 - left;

            vector<TreeNode*> leftTrees = solve(left);
            vector<TreeNode*> rightTrees = solve(right);

            for (TreeNode* l : leftTrees) {
                for (TreeNode* r : rightTrees) {
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }

        return ans;
    }

    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0)
            return {};

        return solve(n);
    }
};