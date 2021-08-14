#include "AVLTree.h"
#include <stdio.h>
#define DEBUG 1
void AVL_CASE_1(TNo** pt, char* h){
  TNo* ptu = (*pt)->left;
  if (ptu->bal==-1){
    (*pt)->left=ptu->right; ptu->right=*pt;
    (*pt)->bal=0; *pt=ptu;
  }else{
    
    TNo* ptv=ptu->right;
    ptu->right=ptv->left; ptv->left=ptu;
    (*pt)->left=ptv->right; ptv->right=*pt;
    (*pt)->bal=(ptv->bal==-1) ? 1 : 0;
    ptu->bal=(ptv->bal==1) ? -1: 0;
    (*pt)=ptv;
  }
  (*pt)->bal=0;
  *h=0;
}
void AVL_CASE_2(TNo** pt, char* h){
  TNo* ptu = (*pt)->right;
  if (ptu->bal==1){
    (*pt)->right=ptu->left; ptu->left=*pt;
    (*pt)->bal=0; *pt=ptu;
  }else{
    TNo* ptv=ptu->left;
    ptu->left=ptv->right; ptv->right=ptu;
    (*pt)->right=ptv->left; ptv->left=*pt;
    (*pt)->bal=(ptv->bal==1) ? -1: 0;
    ptu->bal=(ptv->bal==-1) ? 1: 0;
    *pt=ptv;
  }
  (*pt)->bal=0; *h=0;
}
void AVL_insert(int x, TNo** pt, char* h){
  if (*pt==NULL){
    *pt=TNo_createNFill(x);
    *h=1;
  }else{
    if( x < (*pt)->key){
      AVL_insert(x, &(*pt)->left, h);
      if (*h){
        switch ((*pt)->bal)
        {
          case 1: (*pt)->bal=0; *h=0; break;
          case 0: (*pt)->bal=-1; break;
          case -1: AVL_CASE_1(pt, h); break;
        }
      }
    }else{
      AVL_insert(x, &(*pt)->right, h);
      if (*h){
        switch ((*pt)->bal)
        {
          case -1: (*pt)->bal=0; *h=0; break;
          case 0: (*pt)->bal=1; break;
          case 1: AVL_CASE_2(pt, h); break;
        }
      }
    }
  }
}