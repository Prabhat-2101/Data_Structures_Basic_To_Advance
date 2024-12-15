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

Node* create_binary_search_tree(Node* root) {
    int data;
    do {
        cin>>data; 
        if (data == -1) break;
        if(root == NULL) {
            root = new Node(data);
            continue;
        }
        Node* temp = root;
        while(true){
            if(data < temp->data){
                if(temp->left == NULL){
                    temp->left = new Node(data);
                    break;
                }
                temp = temp->left;
            }else{
                if(temp->right == NULL){
                    temp->right = new Node(data);
                    break;
                }
                temp = temp->right;
            }
        }
        cout<<data<<" ";
    }while(data != -1);
    return root;
}

void preorder(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void level_order(Node* root){
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
    }
}

void vertical_order(Node* root){
    if(!root) return;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    map<int, vector<int>> mp;
    while(!q.empty()){
        auto temp = q.front();q.pop();
        Node* node = temp.first;
        int line = temp.second;
        mp[line].push_back(node->data);
        if(node->left) q.push({node->left, line-1});
        if(node->right) q.push({node->right, line+1});
    }
    for(const auto &hdist: mp){
        for(const auto &node: hdist.second){
            cout<<node<<" ";
        }
    }
}

void boundary_traversal(Node* root) {
    if (!root) return;

    vector<int> nodes;

    auto leaf = [&](Node* node) {
        return !node->left && !node->right;
    };

    if (!leaf(root)) nodes.push_back(root->data);

    /* Left Boundary Traversal */
    Node* current = root->left;
    while (current) {
        if (!leaf(current)) nodes.push_back(current->data);
        if (current->left) current = current->left;
        else current = current->right;
    }

    /* Leaf Node Traversal */
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* tmp = q.front(); q.pop();
        if (leaf(tmp)) nodes.push_back(tmp->data);
        if (tmp->left) q.push(tmp->left);
        if (tmp->right) q.push(tmp->right);
    }

    /* Right Boundary Traversal */
    vector<int> rightBoundary;
    current = root->right;
    while (current) {
        if (!leaf(current)) rightBoundary.push_back(current->data);
        if (current->right) current = current->right;
        else current = current->left; 
    }

    for (int i = rightBoundary.size() - 1; i >= 0; --i) {
        nodes.push_back(rightBoundary[i]);
    }

    for (const int node : nodes) {
        cout << node << " ";
    }
}

void print_2d_view(Node* root,int space){
    if(!root) return;
    space += 5;
    print_2d_view(root->right,space);
    cout<<endl;
    for(int i=0;i<space;i++) cout<<" ";
    cout<<root->data<<endl;
    print_2d_view(root->left,space);
}

int main(){
    Node* root = create_binary_search_tree(NULL);
    cout<<"Preorder Traversal: "<<endl; preorder(root); cout<<endl;
    cout<<"Postorder Traversal: "<<endl;postorder(root); cout<<endl;
    cout<<"Inorder Traversal: "<<endl;inorder(root); cout<<endl;
    cout<<"Level Order Traversal: "<<endl; level_order(root); cout<<endl;
    cout<<"Vertical Order Traversal: "<<endl;vertical_order(root); cout<<endl;
    cout<<"Boundary Traversal: "<<endl;boundary_traversal(root); cout<<endl;
    cout<<"2d view of binary tree: "<<endl;print_2d_view(root,0); cout<<endl;
    return 0;
}