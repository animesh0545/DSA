#include <stdio.h>
#include "bst.h"

bool search(NODE root, int x){
  if (root == NULL)
    return false;
  else if(root->key == x)
    return true;
  else if(root->key > x)
    return search(root->left, x);
  else
    return search(root->right, x);
}
// Time complexity -> O(h), h is the tree-height

void insert(NODE root, int x){
  if(root == NULL)
    root->key = x;
  else if(root->key < x)
    insert(root->right, x);
  else if(root->key > x)
    insert(root->left, x); 
}

void display(NODE root){
  if (root == NULL)
    return;
  printf("%d\t", root->key);
  display(root->left);
  display(root->right);
}
