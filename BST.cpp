// When we delete a node from a Binary Search Tree(BST), the BST properties should remain the same.
// Hence, we have 3 cases for deleting a node from a BST :

// case 1:The node is a leaf node - In this cases, we can just delete the node and return the root, since deleting any elaf node doesn't affect the remainig tree.

// case 2: The node has one child - In this case, replace the node with the child node and return the root.

// case 3:The node has 2 children - In this case, in order to conserve the BST properties, we need to replace the node with it's inorder successor (The next node that comes in the inorder traversal) i.e; we need to replace it with either :
// 1. The greatest value node in it's left subtree (or)
// 2. The smallest value node in it's right subtree
// and return the root.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
class tree
{
public:
    int data;
    tree *left_child;
    tree *right_child;
    tree(int val)
    {
        data = val;
        left_child = NULL;
        right_child = NULL;
    }
};
void inorder(tree *root)
{
    if (root == NULL)
        return;
    inorder(root->left_child);
    cout << root->data << " ";
    inorder(root->right_child);
}
tree * deletenode(tree* root,int target){
    if(root==NULL){
        return root;
    }
    if(root->data>target){
        root->left_child=deletenode(root->left_child,target);
    }
    else if(root->data<target){
        root->right_child=deletenode(root->right_child,target);
    }
    else{
        if(root->left_child==NULL) return root->right_child;
        else if(root->right_child==NULL) return root->left_child;
        tree *temp=root->right_child;
        while(temp->left_child!=NULL){
            temp=temp->left_child;
        }
        root->data=temp->data;
        root->right_child=deletenode(root->right_child,root->data);
    }
    return root;
}
int main()
{
    //              8
    //            /   \
    //           5     10
    //         /  \   /  \
    //        4    6  9   12

    tree *root = new tree(8);
    root->left_child = new tree(5);
    root->right_child = new tree(10);
    root->left_child->left_child = new tree(4);
    root->left_child->right_child = new tree(6);
    root->right_child->left_child = new tree(9);
    root->right_child->right_child = new tree(12);
    inorder(root);
    cout<<endl;
    inorder(deletenode(root,10));
}