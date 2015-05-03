/*
  Unbalanced Binary Search Tree (BST).

  The left subtree of a node contains only nodes with keys less than the node's
  key.
  The right subtree of a node contains only nodes with keys greater than the 
  node's key.
  Both the left and right subtrees must also be binary search trees.
  There must be no duplicate nodes.

                 6
         2             7
      1     4             8
           3                 15
                       12        18
                          13   19  22


  (c) 2015 Josef Ziegler
  
*/

#include <cstdio>
#include <iostream>
using namespace std;

class node{
public:
  int key;
  node* right;
  node* left;
};

node* search(int key, node* tnode){
  if (tnode == NULL) 
    return NULL;
  if (tnode->key == key) 
    return tnode;
  else if (key < tnode->key) 
    return search(key, tnode->left);
  else 
    return search(key, tnode->right);
}

node* insert(int key, node* tnode){
  if (tnode == NULL){
    tnode = new node;
    tnode->key = key;
    return tnode;
  }
  if (key < tnode->key) 
    tnode->left=insert(key, tnode->left);
  else         
    tnode->right=insert(key, tnode->right);
  return tnode;
}

// returns node with smallest key in subtree with root tnode
// needed for "remove" function
node* get_smallest(node* tnode){
  if (tnode->left != NULL) 
    return get_smallest(tnode->left);
  else
    return tnode;
}
// unlinks node with smallest key in subtree with root tnode
// return value: root of modified subtree
// needed for "remove" function
node* unlink_smallest(node* tnode){
  if (tnode->left == NULL && tnode->right == NULL)
    return NULL;
  if (tnode->left != NULL){
    tnode->left = unlink_smallest(tnode->left);
    return tnode;
  }
  else {
    // tnode->left == NULL && tnode->right != NULL
    return tnode->right;
  }
}

void BST_print(node*);
// returns the root of the newly created BST
// doesn't check whether element is atcually in BST
node* remove(int key, node* tnode){
  if (tnode == NULL) return NULL;
  if (key == tnode->key) {
    // if tnode is leaf
    if (tnode->right == NULL && tnode->left == NULL){
      delete tnode;
      return NULL;
    }
    // tnode has one child
    if (tnode->left == NULL) {
      node* tmp=tnode->right;
      delete tnode;
      return tmp;
    }
    if (tnode->right == NULL){
      node* tmp=tnode->left;
      delete tnode;
      return tmp;
    }
    // tnode has two children
    node* smallest=get_smallest(tnode->right);
    tnode->right=unlink_smallest(tnode->right);
    tnode->key=smallest->key;
    delete smallest;
    return tnode;
  }
  else {
    if (key < tnode->key)
      tnode->left=remove(key,tnode->left);
    else 
      tnode->right=remove(key,tnode->right);
    return tnode;
  }
}

// dfs
void BST_print(node* tree){
  if (tree==NULL) return;
  if (tree->left!=NULL){
    printf("%d (l)-> %d\n",tree->key, (tree->left)->key);  
    BST_print(tree->left);
  }
  if (tree->right!=NULL){
    printf("%d (r)-> %d\n",tree->key, (tree->right)->key);
    BST_print(tree->right);
  }
}
  
int main(){
  int x;
  node* ptr = new node;
  ptr->key=-1;

  printf("if x positive: insert x\n");
  printf("if x negative: delete x\n");
  while (1){
    scanf("%d",&x);
    if (x==0) {printf("x must be negative or positive\n"); continue;}
    if (x>0) insert(x,ptr);
    if (x<0) ptr=remove(-x,ptr);
    BST_print(ptr);
    printf("\n");
  }
}
