#ifndef AVL_H
#define AVL_H

typedef struct _avl avl;

avl *arquivo_ler();
avl *avl_criar(site *);
avl *avl_remover(avl *,int);
avl *avl_busca_chave(char *);
avl *avl_inserir (avl *, site *);
avl *avl_busca_codigo(avl *, int);
void avl_apagar(avl *);
void avl_printf(avl *arv);
void avl_busca (avl *, char *);
void chave_inserir(avl *,char *);
void chave_nova_inserir(avl *,int ,char *);
void avl_relevancia_atualizar(avl *, int, int);
void arquivo_salvar(avl *);
void avl_fprintf(avl *,FILE *);

#endif
