#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "site.h"

struct site_{
	int codigo;
	char nome[50];
	int relevancia;
	char link[100];
	char chave[10][50];
	int qtd_chaves;
};

site *site_criar(int codigo, char *nome, int relevancia, char *link, char **chave, int qtd_chaves){
	site *novo = (site*)malloc(sizeof(site));
	
	novo->codigo = codigo;
	strcpy(novo->nome,nome);
	strcpy(novo->link,link);
	novo->relevancia = relevancia;
	novo->qtd_chaves = qtd_chaves;
	
	for(int i = 0; i < qtd_chaves; ++i)
		strcpy(novo->chave[i],chave[i]);
		
	return novo;	
}

void site_apagar(site **s){
	free(*s);	
}

int site_codigo(site *s) {
	return s->codigo;
}

void site_printf(site *s) {
	printf("%d, %s, %d, %s", s->codigo, s->nome, s->relevancia, s->link);
	for (int i = 0; i < s->qtd_chaves; ++i)
		printf(", %s", s->chave[i]);
	printf("\n");
	return;
}
