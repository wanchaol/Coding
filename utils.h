#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <climits>
#include <numeric>
#include <bitset>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


struct Point {
    int x,y;
    Point(int x, int y) : x(x), y(y) {}
    ~Point() = default;
};



string serialize(TreeNode *root) {
    
    vector<string> nodes;
    queue<TreeNode*> level;
    level.push(root);
    while (!level.empty()) {
        size_t n = level.size();
        for (int i = 0; i < n; i++) {
            TreeNode* node = level.front(); level.pop();
//            if(level.empty()) {
//                nodes.push_back(node ? to_string(node->val) : "null");
//            }
//            else
                nodes.push_back(node ? to_string(node->val) + "," : "null,");
            if (node) {
                level.push(node->left);
                level.push(node->right);
            }
        }
    }
    while (!nodes.empty() && nodes.back() == "null,")
        nodes.pop_back();
    string tree;
    for (string node : nodes) tree += node;
    tree.pop_back();
    return tree;
}


TreeNode* deserialize(string data) {
    if (data.empty()) return NULL;
    stringstream ss(data);
    string vs;
    getline(ss, vs, ',');
    TreeNode* root = new TreeNode(stoi(vs));
    queue<TreeNode*> level;
    level.push(root);
    while (!level.empty()) {
        size_t n = level.size();
        for (int i = 0; i < n; i++) {
            TreeNode* node = level.front(); level.pop();
            if (getline(ss, vs, ',') && vs != "null") {
                node->left = new TreeNode(stoi(vs));
                level.push(node -> left);
            }
            if (getline(ss, vs, ',') && vs != "null") {
                node->right = new TreeNode(stoi(vs));
                level.push(node -> right);
            }
        }
    }
    return root;
}



template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
    if ( !v.empty() ) {
        out << '[';
        std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "\b\b]";
    }
    return out;
}

