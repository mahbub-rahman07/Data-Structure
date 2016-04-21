#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct BST
{
    int data;
    struct BST *left,*right;
};

int FindMin(struct BST *root)
{
    if(root == NULL){
        return -1;
    }
    struct BST *temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->data;
}
/// Recursive Find minimum :
int FindMinRec(struct BST *root)
{
    if(root == NULL){
        return -1;
    }
    else if(root->left == NULL)return root->data;
    else
        return FindMinRec(root->left);
}

int FindMax(struct BST *root)
{
    struct BST *temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp->data;
}

/// Recursive Find maximum :
int FindMaxRec(struct BST *root)
{
    if(root == NULL)return -1;
    else if(root->right == NULL) return root->data;
    else
        return FindMaxRec(root->right);
}


struct BST* getNode(int data)
{
    struct BST *t;
    t = new (struct BST);
    t->data = data;
    t->left = NULL;
    t->right = NULL;

    return t;

}

struct BST* inset(struct BST *root,int data)
{
    if(root==NULL){
        root = getNode(data);
    }
    else if(data <= root->data){
        root->left = inset(root->left,data);
    }
    else{
        root->right = inset(root->right,data);
    }
    return root;
}

bool Search(struct BST *root,int data)
{
    if(root == NULL)return false;
    else if(root->data==data)return true;
    else if(data<=root->data)return Search(root->left,data);
    else
        return Search(root->right,data);
}


/// traversing PreOrder

void PreOrder(BST *root)
{
    if(root){
        printf("%d\n",root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

/// traversing PreOrder

void PostOrder(struct BST *root)
{
    if(root){
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d\n",root->data);

    }
}

int main()
{
    struct BST *root = NULL;

    int n;

    root = inset(root,10);
    root = inset(root,15);
    root = inset(root,22);
    root = inset(root,44);

    if(Search(root,33))
        cout<<"found"<<endl;
    else
        cout<<"Not found"<<endl;

    cout<<FindMaxRec(root)<<endl;
    cout<<FindMinRec(root)<<endl;

    return 0;
}
