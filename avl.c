#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "site.h"
#include "avl.h"

struct avl_{
	site *reg;
	avl *filho_esq;
	avl *filho_dir;
	int altura;
};

avl *avl_criar(site *reg){
	avl *novo = (avl*)malloc(sizeof(avl));
	novo->reg = reg;
	novo->filho_esq = NULL;
	novo->filho_dir = NULL;
	novo->altura = 0; 
	return novo;
}

void avl_apagar(avl *T){
	avl_apagar((T)->filho_esq);
	avl_apagar((T)->filho_dir);
	free((T)->reg);
	free(T);
	(T) = NULL;
}

void avl_remover(avl **remove){
	return;
}

int maior(int a,int b){
	return (a > b) ? a : b;
}

int altura(avl *no){
	if(no == NULL)
		return 0;
	return maior(altura(no->filho_esq),altura(no->filho_dir)) + 1;
}

avl *roda_esq(avl *A){
	avl *B = A->filho_dir;
	A->filho_esq = B->filho_dir;
	B->filho_dir = A;
	A->altura = maior(altura(A->filho_esq),altura(A->filho_dir)) + 1;
	B->altura = maior(altura(B->filho_esq),altura(B->filho_dir)) + 1;
	return B;
}

avl *roda_dir(avl *A){
	avl *B = A->filho_esq;
	A->filho_dir = B->filho_esq;
	B->filho_esq = A;
	A->altura = maior(altura(A->filho_esq),altura(A->filho_dir));
	B->altura = maior(altura(B->filho_esq),altura(B->filho_dir));
	return B;
}

avl *roda_esq_dir(avl *A){
	A->filho_dir = roda_esq(A->filho_dir);
	return roda_dir(A);
}

avl *roda_dir_esq(avl *A){
	A->filho_esq = roda_dir(A->filho_esq);
	return roda_esq(A);
}

avl *avl_busca_codigo(int codigo){
	
	return NULL;
}

avl *avl_busca_chave(char *chave){
	
	return NULL;
}

void chave_inserir(avl *noh,char *nova_chave){
	
	return;
}

void relevancia_atualizar(avl *noh,int nova_relevancia){
	
	return;
}
