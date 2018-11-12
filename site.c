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

site *site_criar(int codigo,char *nome,int relevancia,char **chave,int qtd_chaves){
	site *novo = (site*)malloc(sizeof(site));
	
	novo->codigo = codigo;
	strcpy(novo->nome,nome);
	novo->relevancia = relevancia;
	novo->qtd_chaves = qtd_chaves;
	
	for(int i = 0; i < qtd_chaves; ++i)
		strcpy(novo->chave[i],cahve[i]);
		
	return novo;	
}

void site_apagar(site **s){
	free(*s);	
}
