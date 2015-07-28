#include <iostream>
#include <vector>

class Node {
public:
    Node(char v):val(v),left(NULL),right(NULL) {}
    char val;
    Node* left;
    Node* right;
};


//Depth first search for binary tree
void dfs(Node* root) {
    if (root==NULL) return;
    dfs(root->left);
    std::cout<<root->val<<" ";
    dfs(root->right);
}

int main() {
    Node* n0 = new Node('F');
    Node* n1 = new Node('B');
    Node* n2 = new Node('G');
    Node* n3 = new Node('A');
    Node* n4 = new Node('D');
    Node* n5 = new Node('I');
    Node* n6 = new Node('C');
    Node* n7 = new Node('E');
    Node* n8 = new Node('H');
    
    n0->left = n1;
    n0->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->right = n5;
    n4->left = n6;
    n4->right = n7;
    n5->left = n8;
    
    dfs(n0);
    std::cout<<"\n";
    
    return 0;
}
