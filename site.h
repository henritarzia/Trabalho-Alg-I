#ifndef SITE_H
#define SITE_H

typedef struct site_ site;

site *site_criar(int, char *, int, char *, char **, int);
void site_atualizar_relevancia (site *, int);
void site_apagar(site **);
void site_printf(site *);
void site_chave_inserir(site *,char *);
int site_codigo(site *);
int site_qtd_chaves(site *);
int site_relevancia (site *);
int site_procurar_chave (site *, char *);
int site_analisar(int , char *, int, char *, char **, int);
char *site_nome(site *);
char *site_chave (site *, int);
void site_fprintf(site *,FILE *);

#endif
