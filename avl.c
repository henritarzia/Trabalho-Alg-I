#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "site.h"
#include "avl.h"

struct _avl{
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
	if (T == NULL)
		return;
	avl_apagar(T->filho_esq);
	avl_apagar(T->filho_dir);
	free(T->reg);
	free(T);
	T = NULL;
	return;
}

void avl_remover(avl **remove){
	return;
}

int maior(int a,int b){
	return (a > b) ? a : b;
}

int altura(avl *no){
	if(no == NULL)
		return -1;
	return maior(altura(no->filho_esq),altura(no->filho_dir)) + 1;
}

avl *roda_esq(avl *A){
	avl *B = A->filho_dir;
	A->filho_dir = B->filho_esq;
	B->filho_esq = A;
	A->altura = maior(altura(A->filho_esq),altura(A->filho_dir)) + 1;
	B->altura = maior(altura(B->filho_esq),altura(B->filho_dir)) + 1;
	return B;
}

avl *roda_dir(avl *A){
	avl *B = A->filho_esq;
	A->filho_esq = B->filho_dir;
	B->filho_dir = A;
	A->altura = maior(altura(A->filho_esq),altura(A->filho_dir)) + 1;
	B->altura = maior(altura(B->filho_esq),altura(B->filho_dir)) + 1;
	return B;
}

avl *roda_esq_dir(avl *A){
	A->filho_esq = roda_esq(A->filho_esq);
	return roda_dir(A);
}

avl *roda_dir_esq(avl *A){
	A->filho_dir = roda_dir(A->filho_dir);
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

void avl_printf(avl *arv) {
	if (arv == NULL)
		return;
	site_printf(arv->reg);
	avl_printf(arv->filho_esq);
	avl_printf(arv->filho_dir);
	return;
}

avl *avl_inserir (avl *arv, site *s) {
	if (s == NULL)
		return NULL;
	if (arv == NULL)
		arv = avl_criar(s);
	else if (site_codigo(s) > site_codigo(arv->reg)){
		arv->filho_dir = avl_inserir (arv->filho_dir, s);
		if (altura(arv->filho_esq) - altura(arv->filho_dir) == -2) {
			if (site_codigo(s) > site_codigo(arv->filho_dir->reg))
				arv = roda_esq(arv);
			else 
				arv = roda_dir_esq(arv);
		}
	}
	else if (site_codigo(s) < site_codigo(arv->reg)) {
		arv->filho_esq = avl_inserir (arv->filho_esq, s);
		if (altura(arv->filho_esq) - altura(arv->filho_dir) == 2) {
			if (site_codigo(arv->reg) < site_codigo(arv->filho_esq->reg))
				arv = roda_dir(arv);
			else
				arv = roda_esq_dir(arv);
		}
	}

	arv->altura = altura(arv);

	return arv;
}