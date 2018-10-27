#include <stdio.h>
#include <stdlib.h>

typedef struct _tree_{
  void* data;
  struct _tree_ *l;
  struct _tree_ *r;
} TNode;

// CMP retorna 1 se o primeiro argumento é maior, 0 se forem iguais, -1 se o segundo for maior
TNode *inserirNaArvore(TNode *t, void *data, int (*cmp)(void *, void *)){
  TNode *novoNo;
  if(t!=NULL){
    if(cmp(t->data,data)==-1){
        t->r = inserirNaArvore(t->r,data,cmp);
    }else { // Tu pode ctolocar aqui só como senão
        t->l = inserirNaArvore(t->l,data,cmp);
    }
    return t; // Reafirmando o filho que ja tem  ---- esse return aqui que eu não to entendeendo
  } else {
  	novoNo = (TNode*) malloc(sizeof(TNode));
    novoNo->l = NULL;
    novoNo->r = NULL;
    novoNo->data = data;
    return novoNo;
  }
}


int cmp (void* va, void* vb){
    int *a,*b;
    a = (int*)va;
    b = (int*)vb;

    if(*a>*b){
        return 1;
    }else if(*b>*a){
        return -1;
    }else{
        return 0;
    }
}

void imprime(void * valor){
	int *numero;
  numero = (int *) valor;

  printf("%d\n", *numero);
}

void printSim (TNode *t, void imprime(void *)){
  if (t!=NULL){
    printSim(t->l,imprime);
    imprime(t->data);
    printSim(t->r,imprime);
  }
}

int arvoreH (TNode *t){
  int hl=0,hr=0;
  if(t!=NULL){
    hl = arvoreH (t->l);
    hr = arvoreH (t->r);
  	if (hl>hr){
      return hl+1;
    }else{
      return hr+1;
    }
  }
  return 0;
}

int contaNos (TNode *t){
  int cont=0;
	if(t!=NULL){
		cont = contaNos(t->l) + contaNos(t->r) + 1;
		return cont;
	}
  return 0;
}

int contaNosDe1Filho (TNode *t){
  int cont=0;
  if(t!=NULL){
    if(t->l==NULL && t->r!=NULL){
      cont += 1;
    }else if (t->r==NULL && t->l!=NULL){
    	cont += 1;
    }
    cont = contaNosDe1Filho(t->l) + contaNosDe1Filho(t->r) + cont;
  }
  return cont;
}

int contaFolhas (TNode *t){
    int cont=0;
    if(t!=NULL){
        if(t->l==NULL && t->r==NULL){
            cont+=1;
        }
        else{
            cont = contaFolhas(t->l)+contaFolhas(t->r)+cont;
        }
    }
    return cont;
}


int main(){
    int *dado1, *dado2, *dado3, *dado4, *dado6;
    TNode *arv;

    dado6 = (int *) malloc(sizeof(int));
    dado1 = (int *) malloc(sizeof(int));
    dado2 = (int *) malloc(sizeof(int));
    dado3 = (int *) malloc(sizeof(int));
    dado4 = (int *) malloc(sizeof(int));

    *dado1 = 2;
    *dado2 = 1;
    *dado3 = 3;
    *dado4 = 4;
    *dado6 = 5;

    arv = inserirNaArvore(arv, (void *) dado1, cmp);
    arv = inserirNaArvore(arv, (void *) dado2, cmp);
    arv = inserirNaArvore(arv, (void *) dado3, cmp);
    arv = inserirNaArvore(arv, (void *) dado4, cmp);
    arv = inserirNaArvore(arv, (void *) dado6, cmp);

    printSim(arv, imprime);

    //cout << arvoreH(arv) << endl;

    //printf("%d\n", contaNosDe1Filho(arv));

    //printf("%d\n", contaFolhas(arv));

    free(dado1);
    free(dado2);
    free(dado3);
    free(dado4);
    free(dado6);

}
