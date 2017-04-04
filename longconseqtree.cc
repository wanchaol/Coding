#include "utils.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   private:
    int maxLen = INT_MIN;

    void dfs(TreeNode *root, int cur, int val) {
        if (root == nullptr) return;
        if (root->val == val)
            cur++;
        else
            cur = 1;
        maxLen = max(maxLen, cur);

        dfs(root->left, cur, root->val + 1);
        dfs(root->right, cur, root->val + 1);
    }

   public:
    int longestConsecutive(TreeNode *root) {
        if (root == nullptr) return 0;
        dfs(root, 0, root->val);
        return maxLen;
    }
};

int main(int argc, char *argv[]) { return 0; }
