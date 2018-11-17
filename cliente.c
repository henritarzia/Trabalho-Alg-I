#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "site.h"
#include "avl.h"

void menu(avl *T);
void menu_imprimir();
avl *menu_site_criar(avl *T);
void menu_site_remover(avl *T);
void menu_relevancia_atualizar(avl *T);

void menu_imprimir(){
	printf("Menu\n");
	printf("1)Inserir site\n");
	printf("2)Remover site\n");
	printf("3)Inserir chave\n");
	printf("4)Atualizar relevancia\n");
	printf("5)Imprimir sites\n");
	printf("6)Sair\n");
	printf(">> ");
}

avl *menu_site_criar(avl *T){
	int codigo;
	char nome[50];
	int relevancia;
	char link[100];
	char palavraschaves[500];
	char **chaves = (char **) malloc (sizeof(char *) * 10);
	int qtd_chaves;

	for (int i = 0; i < 10; ++i)
		chaves[i] = NULL;

	scanf("%d%*c%[^,]%*c%d%*c%[^,]%*c%s", &codigo, nome, &relevancia, link, palavraschaves);
	chaves[0] = strtok (palavraschaves, ",\n ");
	int i = 0;
	while (chaves[i] != NULL && i < 10)
		chaves[++i] = strtok(NULL, ",\n ");
	avl *aux = avl_inserir(T, site_criar(codigo, nome, relevancia, link, chaves, i));
	free(chaves);
	return aux;
}

void menu_relevancia_atualizar (avl *T) {
	if (T == NULL)
		return;
	int codigo, nova_relevancia;
	scanf ("%d %d", &codigo, &nova_relevancia);
	avl_relevancia_atualizar(T, codigo, nova_relevancia);
	return;
}

int main(){
	avl *T = NULL;
	int flag = 1;
	char opcao;
	
	
	while(flag) {
		do{
			//menu_imprimir();
			scanf("%c",&opcao);
		}while(opcao < 49 && opcao > 53);

		switch(opcao){
			case '1':
			T = menu_site_criar(T);
			break;	
			case '2':
			//menu_site_remover(T);
			break;	
			case '3':
			//menu_chave_inserir(T);
			break;	
			case '4':
			menu_relevancia_atualizar(T);
			break;
			case '5':
			avl_printf(T);
			printf("\n");
			break;
			case '6':
			avl_apagar(T);
			flag = 0;
			break;
		}
		getchar();
	}
	return 0;
}
