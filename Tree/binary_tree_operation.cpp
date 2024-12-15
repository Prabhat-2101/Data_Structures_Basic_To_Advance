#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
}Node;

/* convert a binary tree to its mirror tree*/
void mirror(Node* node) {
    if(!node or (!node->left && !node->right)) return;
    mirror(node->left);
    mirror(node->right);
    swap(node->left,node->right);
}
/* check a binary tree is balanced or not */
int height(Node* root){
    if(!root) return 0;
    if(!root->left && !root->right) return 1;
    return 1 + max(height(root->left),height(root->right));
}
bool isBalanced(Node* root) {
    if(!root) return true;
    if(!root->left && !root->right) return true;
    int diff = abs(height(root->left) - height(root->right));
    return diff<=1 && isBalanced(root->left) && isBalanced(root->right);
}

/* check a binary tree is symmetric or not */
bool helper(struct Node* root1, struct Node* root2){
    if(!root1 && !root2) return true;
    if((root1 && !root2) or (root2 && !root1)) return false;
    bool flag = root1->data == root2->data;
    return flag && helper(root1->left, root2->right) && helper(root1->right,root2->left);
}
bool isSymmetric(struct Node* root){
    return helper(root,root);
}

/* check two binary trees are identical or not */
bool isIdentical(Node *r1, Node *r2) {
    if(!r1 && r2) return false;
    if(!r2 && r1) return false;
    if(!r1 && !r2) return true;
    bool curr = r1->data == r2->data;
    bool left = isIdentical(r1->left,r2->left);
    bool right = isIdentical(r1->right,r2->right);
    return curr && left && right;
}