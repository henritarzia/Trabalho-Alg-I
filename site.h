#ifndef SITE_H
#define SITE_H

typedef struct site_ site;

site *site_criar(int codigo, char *nome, int relevancia, char *link, char **chave, int qtd_chaves);
void site_apagar(site **s);
void site_printf(site *s);
int site_codigo(site *s);

#endif
