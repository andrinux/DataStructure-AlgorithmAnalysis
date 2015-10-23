#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//This is recursion based method.
class Solution_1 {
public:
	void do_InOrder(TreeNode* root, vector<int>& res){
		if (root == NULL) return;
		if (root->left)
			do_InOrder(root->left, res);
		res.push_back(root->val);
		if (root->right)
			do_InOrder(root->right, res);
	}
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == NULL) return res;
		do_InOrder(root, res);
		return res;
	}
};

//Iterative Method.
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {

	}
};


int main()
{
	Solution so;
	TreeNode *r = new TreeNode(1);
	r->left = new TreeNode(2); r->right = new TreeNode(3);
	r->left->left = new TreeNode(4); r->left->right = new TreeNode(5);
	r->right->left = new TreeNode(6); r->right->right = new TreeNode(7);
	vector<int> ret = so.inorderTraversal(r);
	for (auto x : ret)
		cout << x << " ";
	cout << endl;
	return 0;
}