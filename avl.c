#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "site.h"
#include "avl.h"

struct avl_{
	no *raiz;
	int profundidade;
};

struct no_{
	no *filho_esq;
	no *filho_dir;
	int altura;
	site *reg;
};

avl *arvore_criar(){
	avl *T = (avl*)malloc(sizeof(avl));
	T->raiz = NULL;
	T->profundidade = 0; 
	return T;
}

no *no_criar(site *reg){
	no *novo = (no*)malloc(sizeof(no));
	novo->reg = reg;
	novo->filho_esq = NULL;
	novo->filho_dir = NULL;
	novo->altura = 0; 
	return novo;
}

void arvore_apagar(avl **T){
	no_remover((*T)->raiz);
	free(*T);
	(*T) = NULL;
}

void no_remover(no **remove){

}

no *roda_esq(no *A){
	no *B = A->filho_dir;
	A->filho_esq = B->filho_dir;
	B->filho_dir = A;
	return B;
}

no *roda_dir(no *A){
	no *B = A->filho_esq;
	A->filho_dir = B->filho_esq;
	B->filho_esq = A;
	return B;
}

no *roda_esq_dir(no *A){
	A->filho_dir = roda_esq(A->filho_dir);
	return roda_dir(A);
}

no *roda_dir_esq(no *A){
	A->filho_esq = roda_dir(A->filho_esq);
	return roda_esq(A);
}

no *no_busca_codigo(int codigo){
	
}

no *no_busca_chave(char *chave){
	
}

void chave_inserir(no *noh,char *nova_chave){
	
}

void relevancia_atualizar(no *noh,int nova_relevancia){
	
}
