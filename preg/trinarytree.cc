#include "../utils.h"
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

class TrinaryTree {
   private:
    struct TriNode {
        int val;
        TriNode *left;
        TriNode *middle;
        TriNode *right;

        TriNode(int x)
            : val(x), left(nullptr), middle(nullptr), right(nullptr) {}
    };

    TriNode *root;

    TriNode *insertNode(int val, TriNode *root) {
        if (root == nullptr) {
            root = new TriNode(val);
        } else if (val < root->val) {
            root->left = insertNode(val, root->left);
        } else if (val > root->val) {
            root->right = insertNode(val, root->right);
        } else {
            root->middle = insertNode(val, root->middle);
        }

        return root;
    }

    TriNode *deleteNode(int val, TriNode *root) {
        if (root == nullptr) {
            return root;
        } else if (val < root->val) {
            root->left = deleteNode(val, root->left);
        } else if (val > root->val) {
            root->right = deleteNode(val, root->right);
        } else {
            // val equal to node
            if (!root->left && !root->right && !root->middle) {
                delete root;
                return nullptr;
            }

            if (root->middle) {
                root->middle = deleteNode(val, root->middle);
            } else if (root->left && root->right) {
                TriNode *nextNode = root->right;

                while (nextNode->left) {
                    nextNode = nextNode->left;
                }

                root->val = nextNode->val;
                root->right = deleteNode(nextNode->val, root->right);

            } else if (root->left) {
                TriNode *left = root->left;
                delete root;
                return left;
            } else if (root->right) {
                TriNode *right = root->right;
                delete root;
                return right;
            }
        }

        return root;
    }

    string tranverse(TriNode *root) {
        if (root == nullptr) {
            return "";
        }

        string res = to_string(root->val);
        res += tranverse(root->left);
        res += tranverse(root->middle);
        res += tranverse(root->right);

        return res;
    }

   public:
    TrinaryTree() : root(nullptr) {}

    void insertNode(int val) { root = insertNode(val, root); }
    void deleteNode(int val) { root = deleteNode(val, root); }

    string tranverse() { return tranverse(root); }
};

TEST_CASE("normal insert", "[TrinaryTree]") {
    TrinaryTree tree;
    tree.insertNode(5);
    tree.insertNode(4);
    tree.insertNode(9);
    tree.insertNode(5);
    tree.insertNode(7);
    tree.insertNode(2);
    tree.insertNode(2);
}

TEST_CASE("normal delete", "[TrinaryTree]") {
    TrinaryTree tree;
    tree.insertNode(5);
    tree.insertNode(4);
    tree.insertNode(9);
    tree.insertNode(5);
    tree.deleteNode(5);
    string teststr = tree.tranverse();
    REQUIRE(teststr == "549");
}
