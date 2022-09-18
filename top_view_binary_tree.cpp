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
void top_view(tree*root){
    if(root==NULL) return;
    queue<tree*> q;
    map<int,int> m;
    int distance=0;
    root->h_distance=distance;   
    q.push(root);
    while(!q.empty()){
        distance=root->h_distance;
        if(m.count(distance)==0){
            m[distance]=root->data;
        }
        if(root->left_child!=NULL){
            root->left_child->h_distance=distance-1;
            q.push(root->left_child);
        }
        if(root->right_child!=NULL){
            root->right_child->h_distance=distance+1;
            q.push(root->right_child);
        }
        q.pop();
        root=q.front();
    }
    for(auto i=m.begin();i!=m.end();i++){
        cout<<i->second<<" ";
    }
    
}
void bottom_view(tree*root){
    if(root==NULL) return;
    queue<tree*> q;
    map<int,int> m;
    int distance=0;
    root->h_distance=distance;   
    q.push(root);
    while(!q.empty()){
        distance=root->h_distance;
        m[distance]=root->data;
        if(root->left_child!=NULL){
            root->left_child->h_distance=distance-1;
            q.push(root->left_child);
        }
        if(root->right_child!=NULL){
            root->right_child->h_distance=distance+1;
            q.push(root->right_child);
        }
        q.pop();
        root=q.front();
    }
    for(auto i=m.begin();i!=m.end();i++){
        cout<<i->second<<" ";
    }
    
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
    bottom_view(root);

}