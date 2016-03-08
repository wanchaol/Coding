#include <iostream>
#include <fstream>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void readBSTHelper(TreeNode *root, ifstream &fin, int val, int low, int high) {

	if(val > low && val < high) {

		int insertval = val;

		root = new TreeNode(insertval);

		if(fin >> insertval) {
			readBSTHelper(root->left, fin, insertval, low, val);
			readBSTHelper(root->right, fin, insertval,  val, high);
		}
	}

}

void readBST(TreeNode *root, ifstream &fin) {
	int val;
	fin>>val;

	readBSTHelper(root, fin, val, INT_MIN, INT_MAX);

}

void printBST(TreeNode *root) {
	printBST(root->left);
	cout<<root->val;
	printBST(root->right);
}

int main(int argc, char *argv[])
{

	//test
	ifstream fin("bst.txt");

	TreeNode *root = nullptr;
	readBST(root , fin);

	printBST(root);
	
	
	return 0;
}
