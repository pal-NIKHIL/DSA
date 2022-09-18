#include <bits/stdc++.h>
using namespace std;
class tree{
    public:
    int data;
    int h_distance;
    tree* left_child;
    tree*right_child;
    tree(int val){
        data=val;
        left_child=NULL;
        right_child=NULL;
    }
};
tree* LCA(tree* root,int n1,int n2){
    if(root==NULL) return root;
    if(root->data == n1 || root->data==n2) return root;
    tree* left=LCA(root->left_child,n1,n2);
    tree * right=LCA(root->right_child,n1,n2);
    if(left!=NULL && right!=NULL){
        return root;
    }
    if(left==NULL && right==NULL){
        return NULL;
    }
    if(left!=NULL) return LCA(root->left_child,n1,n2);
    return LCA(root->right_child,n1,n2);
}
int find_level(tree *root,int k,int level){
    if(root==NULL) return -1;
    if(root->data==k) return level;
    int left=find_level(root->left_child,k,level+1);
    if(left==-1) return find_level(root->right_child,k,level+1);
    return left;
}
int find_distance(tree *root,int n1,int n2){
    tree *lca=LCA(root,n1,n2);
    return find_level(lca,n1,0)+find_level(lca,n2,0);
}
int main(){
    //              1
    //            /   \
    //           2      3
    //         /  \      \
    //        4    5      7
   
tree *root = new tree(1);
    root->left_child = new tree(2);
    root->right_child = new tree(3);
    root->left_child->left_child = new tree(4);
    root->left_child->right_child = new tree(5);
    root->right_child->right_child = new tree(7);
    cout<<find_distance(root,3,7);

}