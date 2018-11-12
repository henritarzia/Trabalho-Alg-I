#ifndef SITE_H
#define SITE_H

typedef struct site_ site;

site *site_criar(int codigo,char *nome,int relevancia,char **chave,int qtd_chaves);
void site_apagar(site **s);

#endif
