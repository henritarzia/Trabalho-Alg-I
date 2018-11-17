#ifndef SITE_H
#define SITE_H

typedef struct site_ site;

site *site_criar(int codigo, char *, int, char *, char **, int);
void site_atualizar_relevancia (site *, int);
void site_apagar(site **s);
void site_printf(site *s);
int site_codigo(site *s);

#endif
