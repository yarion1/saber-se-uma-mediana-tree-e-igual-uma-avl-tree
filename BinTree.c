#include "BinTree.h"
#include<stdio.h>
#include<stdlib.h>

BinTree* BinTree_create(){
  BinTree* nova=malloc(sizeof(BinTree));
  if(nova){
    nova->root=NULL;
  } return nova;
}
TNo* TNo_createNFill(int key){
  TNo* novo=malloc(sizeof(TNo));
  if (novo){
    novo->key=key;
    novo->left=NULL;
    novo->right=NULL;
    novo->p=NULL;
    novo->bal=0;
  }return novo;
}
TNo* BinTree_search(TNo* x, int k){
  while(x!=NULL && k !=x->key)
    x = (k < x->key) ? x->left : x->right;
  return x;
}
int BinTree_insert(BinTree* T, TNo* z, int r){
  if(T==NULL || z==NULL) return 0;
  z = TNo_createNFill(r);
  TNo *y=NULL, *x=T->root;
  while(x!=NULL){
    y = x;
    x = (z->key < x->key) ? x->left:x->right;
  }
  z->p=y;
  if(y==NULL)
    T->root=z;
  else 
    if(z->key < y->key)
      y->left = z;
    else
      y->right = z;
  return 1;
}
void BinTree_preorder(TNo* root){
  if(root!=NULL){
    printf("%d, ", root->key);
    BinTree_preorder(root->left);
    BinTree_preorder(root->right);
  }
}
void BinTree_posorder(TNo* a)
{
 if (a !=NULL){
    BinTree_posorder(a->left); 
    BinTree_posorder(a->right);
    printf("%d, ",a->key); 
 }
}
void BinTree_inorder(TNo* root){
  if(root!=NULL){
    BinTree_inorder(root->left);
    printf("%d, ", root->key);
    BinTree_inorder(root->right);
  }
}

TNo* BinTree_destroy(TNo* r){
    return r=NULL;
}
 
void printTree(TNo* root){
  printf("PRE: ");
  BinTree_preorder(root);
  putchar('\n');
}
int verify_Trees(TNo* root1, TNo* root2){
  int i=1;
  if(root1!=NULL && root1!=NULL){
    if(root1->key !=root2->key){
       return 0;
    }
    verify_Trees(root1->left, root2->left);
    verify_Trees(root1->right, root2->right);
  }
  return 1; 
}
