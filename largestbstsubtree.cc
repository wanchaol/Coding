#include "utils.h"

class Solution {
   private:
    struct NodeInfo {
        bool is_valid = false;
        int right_most = INT_MIN;
        int left_most = INT_MAX;
        int size = 0;
    };

    NodeInfo bsthelper(TreeNode *root) {
        if (root == nullptr) {
            NodeInfo node;

            node.left_most = INT_MAX;
            node.right_most = INT_MIN;
            node.size = 0;
            node.is_valid = true;

            return node;
        }

        NodeInfo left_sub = bsthelper(root->left);
        NodeInfo right_sub = bsthelper(root->right);

        NodeInfo node;

        node.is_valid = (root->val >= left_sub.right_most) &&
                        (root->val <= right_sub.left_most) &&
                        left_sub.is_valid && right_sub.is_valid;

        if (node.is_valid) {
            node.left_most = min(left_sub.left_most, root->val);
            node.right_most = max(right_sub.right_most, root->val);

            node.size = left_sub.size + right_sub.size + 1;
        } else {
            node.size = max(left_sub.size, right_sub.size);
        }

        return node;
    }

   public:
    int largestBSTSubtree(TreeNode *root) {
        NodeInfo rt = bsthelper(root);

        return rt.size;
    }
};
