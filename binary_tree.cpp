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
void preorder(tree *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left_child);
    preorder(root->right_child);
}
void inorder(tree *root)
{
    if (root == NULL)
        return;
    inorder(root->left_child);
    cout << root->data << " ";
    inorder(root->right_child);
}
void postorder(tree *root)
{
    if (root == NULL)
        return;
    postorder(root->left_child);
    postorder(root->right_child);
    cout << root->data << " ";
}
int search(int inorder[], int start, int end, int curr)
{
    for (int i = 0; i <= end; i++)
    {
        if (inorder[i] == curr)
            return i;
    }
    return -1;
}
// build tree postorder and inorder
//  tree* buildtree(int preorder[],int inorder[],int start,int end){
//      static int idx=0;
//      if(start>end) return NULL;
//      int curr=preorder[idx];
//      idx++;
//      tree *node=new tree(curr);
//      if(start==end) return node;
//      int pos=search(inorder,start,end,curr);
//      node->left_child=buildtree(preorder,inorder,start,pos-1);
//      node->right_child=buildtree(preorder,inorder,pos+1,end);
//      return node;
//  }

// build tree postorder and inorder
tree *buildtree(int postorder[], int inorder[], int start, int end)
{
    static int idx = 4;
    if (start > end)
        return NULL;
    int curr = postorder[idx];
    idx--;
    tree *node = new tree(curr);
    if (start == end)
        return node;
    int pos = search(inorder, start, end, curr);
    node->right_child = buildtree(postorder, inorder, pos + 1, end);
    node->left_child = buildtree(postorder, inorder, start, pos - 1);
    return node;
}
void inorderprint(tree *root)
{
    if (root == NULL)
        return;
    inorderprint(root->left_child);
    cout << root->data;
    inorderprint(root->right_child);
}
int sumatK(tree *root, int k)
{
    if (root == NULL)
    {
        return 0;
    }
    int count = 0;
    int sum = 0;
    queue<tree *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        tree *node = q.front();
        q.pop();
        if (node != NULL)
        {
            if (count == k)
            {
                sum += node->data;
            }
            if (node->left_child != NULL)
            {
                q.push(node->left_child);
            }
            if (node->right_child != NULL)
            {
                q.push(node->right_child);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
            count++;
        }
    }
    return sum;
}
int countnode(tree *root)
{
    if (root == NULL)
        return 0;
    return countnode(root->left_child) + countnode(root->right_child) + 1;
}

int sumofnode(tree *root)
{
    if (root == NULL)
        return 0;
    return sumofnode(root->left_child) + sumofnode(root->right_child) + root->data;
}

int height(tree *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left_child), height(root->right_child)) + 1;
}

int diametercalculator(tree *root)
{
    if (root == NULL)
        return 0;
    int curr_diameter = height(root->left_child) + height(root->right_child) + 1;
    int left_diameter = diametercalculator(root->left_child);
    int right_diameter = diametercalculator(root->right_child);
    return max(curr_diameter, max(left_diameter, right_diameter));
}
int newdiametercalculator(tree *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int left_diameter = newdiametercalculator(root->left_child, &lh);
    int right_diameter = newdiametercalculator(root->right_child, &rh);
    int curr_diameter = lh + rh + 1;
    *height = max(lh, rh) + 1;
    return max(curr_diameter, max(left_diameter, right_diameter));
}

void levelorder(tree *root)
{
    if (root == NULL)
    {
        cout << "no node in tree";
        return;
    }
    queue<tree *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        tree *node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout << node->data << " ";
            if (node->left_child != NULL)
            {
                q.push(node->left_child);
            }
            if (node->right_child != NULL)
            {
                q.push(node->right_child);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}

void sumreplacement(tree *&root)
{
    if (root == NULL)
        return;
    sumreplacement(root->left_child);
    sumreplacement(root->right_child);
    if (root->left_child != NULL)
        root->data += root->left_child->data;
    if (root->right_child != NULL)
        root->data += root->right_child->data;
}

bool isbalanced(tree *root)
{ // time complexity=0(n)^2
    if (root == NULL)
        return true;
    if (isbalanced(root->left_child) == false)
        return false;
    if (isbalanced(root->right_child) == false)
        return false;
    int lh = height(root->left_child);
    int rh = height(root->right_child);
    if (abs(lh - rh) > 1)
        return false;
    else
        return true;
}
bool isbalanced(tree *root, int *height)
{ // time complexity=0(n)
    if (root == NULL)
        return true;
    int lh = 0, rh = 0;
    if (isbalanced(root->left_child, &lh) == false)
        return false;
    if (isbalanced(root->right_child, &rh) == false)
        return false;
    *height = max(lh, rh) + 1;
    if (abs(lh - rh) > 1)
        return false;
    else
        return true;
}
void right_view(tree *root)
{
    if (root == NULL)
        return;
    queue<tree *> q;
    q.push(root);
    while (!q.empty())
    {
        int number_of_node_at_kth_level = q.size();
        for (int i = 0; i < number_of_node_at_kth_level; i++)
        {
            tree *curr = q.front();
            q.pop();
            if (i == number_of_node_at_kth_level - 1)
            {
                cout << curr->data << endl;
            }
            if (curr->left_child != NULL)
                q.push(curr->left_child);
            if (curr->right_child != NULL)
                q.push(curr->right_child);
        }
    }
}
void left_view(tree *root)
{
    if (root == NULL)
        return;
    queue<tree *> q;
    q.push(root);
    while (!q.empty())
    {
        int number_of_node_at_kth_level = q.size();
        for (int i = 0; i < number_of_node_at_kth_level; i++)
        {
            tree *curr = q.front();
            if (i == 0)
            {
                cout << curr->data << endl;
            }
            q.pop();
            if (curr->left_child != NULL)
            {
                q.push(curr->left_child);
            }
            if (curr->right_child != NULL)
            {
                q.push(curr->right_child);
            }
        }
    }
}
    bool ishelp(tree *left,tree *right){
        if(left==NULL || right==NULL){
            if(right==left) return true;
        }
        if(left->data!=right->data) return false;
        return ishelp(left->left_child,right->right_child) && ishelp(left->right_child,right->left_child);
    }
 bool isSymmetric(tree* root) {
        if(root==NULL) return true;
        return ishelp(root->left_child,root->right_child);
    }

void flatten(tree * root){
    if(root==NULL || (root->left_child==NULL && root->right_child==NULL)) return;
    if(root->left_child!=NULL){
        flatten(root->left_child);
        tree *temp=root->right_child;
        root->right_child=root->left_child;
        root->left_child=NULL;
        tree *t=root->right_child;
        while(t->right_child!=NULL){
            t=t->right_child;
        }
        t->right_child=temp;
        
    }
    flatten(root->right_child);
}
 tree* lowestCommonAncestor(tree* root, tree* p, tree* q) {
        if(root==NULL) return NULL;
        if(p->data==root->data || q->data==root->data) return root;
        tree *left=lowestCommonAncestor(root->left_child,p,q);
        tree *right=lowestCommonAncestor(root->right_child,p,q);
        if(left==NULL) return right;
        if(right==NULL) return left;
        return root;
    }
int main()
{
    //              1
    //            /   \
    //           2      3
    //         /  \    /  \
    //        4    5  6    7

    tree *root = new tree(1);
    root->left_child = new tree(2);
    root->right_child = new tree(3);
    root->left_child->left_child = new tree(4);
    root->left_child->right_child = new tree(5);
    root->right_child->left_child = new tree(6);
    root->right_child->right_child = new tree(7);
    flatten(root);
    levelorder(root);
    //left_view(root);
    // isbalanced(root)?cout<<"BALANCED":cout<<"NOT";
    // sumreplacement(root);
    // levelorder(root);
    // int height=0;
    // cout<<newdiametercalculator(root,&height);
    // cout<<height(root);
    // cout<<countnode(root);
    //  cout<<sumatK(root,2);
    // int preorder[]={4,2,5,3,1};
    // int inorder[]={4,2,1,5,3};
    // inorderprint(buildtree(preorder,inorder,0,4));

    return 0;
}