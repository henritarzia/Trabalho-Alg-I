#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "site.h"
#include "avl.h"

void menu(avl *T);
void menu_imprimir();
void menu_site_criar(avl *T);
void menu_site_remover(avl *T);
void menu_relevancia_atualizar(avl *T);

void menu_imprimir(){
	printf("Menu\n");
	printf("1)Inserir site\n");
	printf("2)Remover site\n");
	printf("3)Inserir chave\n");
	printf("4)Atualizar relevancia\n");
	printf("5)Sair\n");
	printf(">> ");
}

void menu_site_criar(avl *T){
	int codigo;
	char nome[50];
	int relevancia;
	char link[100];
	char chave[10][50];
	int qtd_chaves;
}

void menu(avl *T){
	char opcao = 0;
	
	while(opcao >= 49 && opcao <= 53){
		menu_imprimir();
		scanf("%c",&opcao);
	}
		
	switch(opcao){
		case '1':
		menu_site_criar(T);
		menu(T);
		break;	
		case '2':
		menu_site_remover(T);
		menu(T);
		break;	
		case '3':
		menu_chave_inserir(T);
		menu(T);
		break;	
		case '4':
		menu_relevancia_atualizar(T);
		menu(T);
		break;	
		case '5':
		arvore_apagar(&T);
		break;	
	}
}

int main(){
	avl *T = arvore_criar();
	menu(T);
}
