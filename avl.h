#ifndef AVL_H
#define AVL_H

typedef struct avl_ avl;
typedef struct no_ no;

avl *arvore_criar();
void arvore_apagar(avl **T);

no *no_criar(site *reg);
no *roda_esq(no *A);
no *roda_dir(no *A);
no *roda_esq_dir(no *A);
no *roda_dir_esq(no *A);
no *no_busca_chave(char *chave);
no *no_busca_codigo(int codigo);

void chave_inserir(no *noh,char *nova_chave);
void relevancia_atualizar(no *noh,int nova_relevancia);

#endif
