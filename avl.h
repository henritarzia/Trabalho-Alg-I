#ifndef AVL_H
#define AVL_H

typedef struct _avl avl;

avl *arquivo_ler();
avl *menor_no(avl *);
avl *roda_esq(avl *);
avl *roda_dir(avl *);
avl *avl_criar(site *);
avl *roda_esq_dir(avl *);
avl *roda_dir_esq(avl *);
avl *remover_avl(avl *,int);
avl *avl_busca_chave(char *);
avl *avl_inserir (avl *, site *);
avl *avl_busca_codigo(avl *, int);
int maior(int, int);
void balance(avl *);
void avl_apagar(avl *);
void avl_printf(avl *arv);
void avl_busca (avl *, char *);
void chave_inserir(avl *,char *);
void chave_nova_inserir(avl *,int ,char *);
void avl_relevancia_atualizar(avl *, int, int);


/*------------------------------------------------*/
void arquivo_salvar(avl *);
void avl_fprintf(avl *,FILE *);

#endif