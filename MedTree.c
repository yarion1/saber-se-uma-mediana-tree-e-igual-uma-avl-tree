#include "MedTree.h"
#include <stdio.h>
#include "BinTree.h"

void MedTree_insert(int* vet, BinTree* r, int tam, int med){
  MedTree_reorder(vet, tam);
  putchar('\n');
  MedTree_add(r, TNo_createNFill(vet[med]));
  int i=0;
  while(i<tam){
    if(i==med) i++;
    if(!MedTree_add(r, TNo_createNFill(vet[i]))){
      printf("Erro na inserção: %d", vet[i]);
    }
    i++;
  }

}
void MedTree_reorder(int* vet, int tam){
  int aux = 0; 
  for (int i=0; i<tam; i++){
    for (int j=0; j<tam; j++){
      if (vet[i]<vet[j]){
          aux=vet[i];
          vet[i]=vet[j];
          vet[j]=aux;
      }
    }
  }
}
int MedTree_add(BinTree* T, TNo* z){
  if(T==NULL || z==NULL) return 0;
  TNo *y=NULL, *x=T->root;
  while(x!=NULL){
    y=x;
    x=(z->key <x->key) ? x->left:x->right;
  }
  z->p=y;
  if(y==NULL)
    T->root=z;
  else 
    if(z->key<y->key)
      y->left=z;
    else
      y->right=z;
  return 1;
}
