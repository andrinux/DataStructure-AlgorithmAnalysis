/*
* Given a sorted (increasing order) array, write an algorithm to create a binary tree with minimal height.
*/

#include <iostream>
#include <time.h>
#include "BinarySearchTree.h"

//Minimal height should be log(N)
void ArrayToBST(std::vector<int> &data, BinarySearchTree &BST){
	//Find the power of 2
	int M = data.size()-1;
	int N = 0;
	while (M >= 1){
		M = M / 2;
		N++;
	}
	M = data.size() - 1;
	std::cout << "layer Number N = " << N << std::endl;
	int step = 1 << (N - 2);
	int i = (1 << (N-1) )-1;
	i = M / 2;
	std::queue<int> cur, next;
	cur.push(i); BST.insert(data[i]);
	while (step > 0){
		while (!cur.empty()){
			int idx1 = cur.front() + step;
			int idx2 = cur.front() - step;
			std::cout << "Insert: " << idx1 << ", " << idx2 << std::endl;
			if (idx1 >= 0 && idx1 <= M){
				BST.insert(data[idx1]); next.push(idx1);
			}
			if (idx2 >= 0 && idx2 <= M){
				BST.insert(data[idx2]); next.push(idx2);
			}
			cur.pop();
		}
		cur.swap(next); //next will be empty
		step = step / 2;
	}
}

Node* ArrayToBST_R(std::vector<int> &data){
	BinarySearchTree *BST=new BinarySearchTree();
	int mid = (data.size() - 1) / 2;
	//base case
	if (data.size() == 0)
		return NULL;
	//This base case can be skipped.
	//if (data.size() == 1){
	//	BST->insert(data[0]);
	//	return BST->root;
	//}
	//general case
	std::vector<int> lData, rData;
	for (int i = 0; i != mid; i++)
		lData.push_back(data[i]);
	for (int i = mid + 1; i != data.size(); i++)
		rData.push_back(data[i]);
	BST->insert(data[mid]);
	BST->root->left = ArrayToBST_R(lData);
	BST->root->right = ArrayToBST_R(rData);
	return BST->root;
}

int main()
{
	srand((unsigned) time(NULL));
	std::vector<int> data;
	//data.push_back(0);
	for (int i = 0; i != 17; i++){
		//data.push_back(data[i] + rand() % 10);
		data.push_back(i);
	}
	BinarySearchTree BST;
	ArrayToBST(data, BST);
	BST.print_as_sideways_tree();
	BST.getHeight(BST.root);

	BinarySearchTree *p =new BinarySearchTree();
	p->root = ArrayToBST_R(data);
	p->print_as_sideways_tree();
	p->getHeight(p->root);
	return EXIT_SUCCESS;
}