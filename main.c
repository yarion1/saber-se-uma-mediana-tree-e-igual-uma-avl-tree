#include "BinTree.h"
#include "AVLTree.h"
#include "MedTree.h"
#include<stdio.h>
#include<stdlib.h>

int main(){
  BinTree *abbmed=BinTree_create();
  TNo* root=NULL;
  char h=0;
  int ncasos, tam, aux, *vet; 
  scanf("%d", &ncasos);
  for(int i=0; i<ncasos; i++){
    scanf("%d", &tam);
    int vet[tam];
    for(int j=0; j<tam; j++){
      scanf("%d", &vet[j]);
      AVL_insert(vet[j], &root, &h);
    }
    MedTree_insert(vet, abbmed, tam, (tam/2));
    printf("%d\n\n",verify_Trees(root, abbmed->root));
    root = BinTree_destroy(root);
    abbmed->root = BinTree_destroy(abbmed->root);
  }
  return 0;
}