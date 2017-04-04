#include "utils.h"

class Solution {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        // string res = nullptr;
        ostringstream osm;
        streehelper(root, osm);
        return osm.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        istringstream istm(data);
        return buildtree(istm);
    }

   private:
    /* data */

    void streehelper(TreeNode *root, ostringstream &s) {
        if (root == nullptr) {
            s << "# ";
        } else {
            s << root->val << " ";
            streehelper(root->left, s);
            streehelper(root->right, s);
        }
    }

    TreeNode *buildtree(istringstream &ss) {
        string val;
        ss >> val;

        if (val == "#") {
            return nullptr;

        } else {
            TreeNode *root = new TreeNode(stoi(val));
            root->left = buildtree(ss);
            root->right = buildtree(ss);

            return root;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution sol;

    string str = "1,2,3,null,null,4,5";

    TreeNode *root = deserialize(str);

    // cout<<sol.serialize(root);

    sol.deserialize(sol.serialize(root));

    return 0;
}
