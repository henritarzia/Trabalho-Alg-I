#ifndef AVL_H
#define AVL_H

typedef struct _avl avl;

void avl_apagar(avl *);
avl *avl_criar(site *);
avl *roda_esq(avl *);
avl *roda_dir(avl *);
avl *roda_esq_dir(avl *);
avl *roda_dir_esq(avl *);
avl *avl_busca_chave(char *);
avl *avl_busca_codigo(int);
avl *avl_inserir (avl *, site *);
int maior(int, int);
void avl_printf(avl *arv);

void chave_inserir(avl *,char *);
void relevancia_atualizar(avl *, int);

#endif
