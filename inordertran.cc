#include "utils.h"

class Solution {
    void recursiveHelper(TreeNode *root, vector<int> &res) {
        if (root == nullptr) {
            return;
        }

        recursiveHelper(root->left, res);

        res.push_back(root->val);

        recursiveHelper(root->right, res);
    }

   public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        recursiveHelper(root, res);
        return res;
    }

    vector<int> iterativeInorder(TreeNode *root) {
        vector<int> res;

        if (root == nullptr) return res;

        stack<TreeNode *> stk;
        TreeNode *p = root;
        // stk.push(p);
        while (!stk.empty() || p != nullptr) {
            if (p != nullptr) {
                stk.push(p);
                p = p->left;
            } else {
                p = stk.top();
                stk.pop();

                res.push_back(p->val);
                p = p->right;
            }
        }
        return res;
    }

    vector<int> morrisTraversal(TreeNode *root) {}
};
