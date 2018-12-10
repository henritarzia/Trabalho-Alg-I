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

/*
	Aloca dinamicamente uma struct site cujo conteúdo são as informações passadas por argumento pelo usuário.
	Retorno: struct resultante da alocação e inicialização.
*/
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

int site_qtd_chaves(site *s){
	return s->qtd_chaves;
}

void site_atualizar_relevancia (site *s, int nova_relevancia) {
	if (s == NULL)
		return;
	s->relevancia = nova_relevancia;
	return;
}

/*
	Imprime o site 's' no formato "<código>,<nome>,<relevância>,<link>,<palavras chave>"
*/
void site_printf(site *s) {
	printf("%04d, %s, %04d, %s", s->codigo, s->nome, s->relevancia, s->link);
	for (int i = 0; i < s->qtd_chaves; ++i)
		printf(", %s", s->chave[i]);
	printf("\n");
	return;
}

/*
	Verifica os dados referentes a um site para determinar se eles estão dentro dos parâmetros estabelecidos.
	imprimindo mensagens de erro para cada valor diferente do esperado.
	Retorno:
	- 1: todas as informações estão em conformidade com os limites;
	- 0: alguma das informções está incorreta.
*/
int site_analisar(int codigo, char *nome, int relevancia, char *link, char **chave, int qtd_chaves){
	int flag = 1;
	if(codigo < 0 || codigo > 9999){
		printf("<Erro/%s> Codigo %d nao esta intervalo permitido (0 - 9999).\n",nome,codigo);
		printf("Pressione Enter para continuar.\n");
		getchar();
		flag = 0;
	}
	if(qtd_chaves > 10){
		printf("<Erro/%s> Numero de chaves excedeu o limite.\n",nome);
		printf("Pressione Enter para continuar.\n");
		getchar();
		flag = 0;
	}
	if(relevancia < 0 || relevancia > 1000){
		printf("<Erro/%s> Relevancia %d nao esta intervalo permitido (0 - 9999).\n",nome,relevancia);
		printf("Pressione Enter para continuar.\n");
		getchar();
		flag = 0;
	}
	return flag;
}

/*
	Adiciona uma palavra chave ao site 's'.
*/
void site_chave_inserir(site *s,char *chave){
	strcpy(s->chave[s->qtd_chaves],chave);
	s->qtd_chaves++;
	printf("Chave %s adicionada em %s.\n",chave,s->nome);
}

int site_procurar_chave (site *s, char *chave) {
	if (s == NULL)
		return 0;
	for (int i = 0; i < s->qtd_chaves; ++i)
		if (strcmp(chave, s->chave[i]) == 0)
			return 1;
	return 0;
}

/*
	Grava o conteúdo de um site no arquivo apontado por 'fp' no formato "<código>,<nome>,<relevância>,<link>,<palavras chave>".
*/
void site_fprintf(site *s,FILE *fp){
	fprintf(fp,"%04d, %s, %04d, %s", s->codigo, s->nome, s->relevancia, s->link);
	for (int i = 0; i < s->qtd_chaves; ++i)
		fprintf(fp,", %s", s->chave[i]);
	fprintf(fp,"\n");
	return;
}

char *site_nome(site *s){
	return s->nome;
}

char *site_chave (site *s, int i) {
	if (i > s->qtd_chaves)
		return NULL;
	return s->chave[i];
}

int site_relevancia (site *s) {
	return s->relevancia;
}