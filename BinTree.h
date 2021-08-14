
#ifndef BINTREE_H
#define BINTREE_H

typedef struct no {
  int key;
  struct no *p, *left, *right;
  int bal;
}TNo;

typedef struct {
  TNo* root;
} BinTree;

BinTree* BinTree_create();
TNo* TNo_createNFill(int);
int BinTree_insert(BinTree*, TNo*, int);
TNo* BinTree_search(TNo*, int);
void BinTree_posorder(TNo*);
void BinTree_preorder(TNo*);
void BinTree_inorder(TNo*);
TNo* BinTree_destroy(TNo*);
int verify_Trees(TNo*, TNo*);

#endif