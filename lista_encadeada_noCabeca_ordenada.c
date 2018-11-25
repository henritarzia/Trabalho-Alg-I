#include <stdio.h>
#include <stdlib.h>

#include "lista_encadeada_noCabeca_ordenada.h"

/* 	
	Structs: 
		Node: Nós;
		Cabeca_lista: A lista em si;
*/

struct Node {
	int item;
	int priority;
	struct Node *previous;
};
struct Cabeca_lista {
	struct Node *topo;
	int tam;
};

lista_e *le_criar () {
	//aloca as estruturas
	lista_e *aux = (lista_e *) malloc (sizeof(lista_e));
	if (aux == NULL)
		return NULL;
	node *nodeAux = (node *) malloc (sizeof(node));
	if (nodeAux == NULL){
		free(aux);
		return NULL;
	}
	//setas os valores para o padrão
	nodeAux->item = INT_MIN;
	nodeAux->priority = INT_MIN;
	nodeAux->previous = NULL;
	aux->topo = nodeAux;
	aux->tam = 0;
	return aux;
}

void le_clear_no (node *no) {
	if (no == NULL)
		return;
	le_clear_no(no->previous);
	free(no);
	return;
}

void le_clear (lista_e *l) {
	if (l == NULL)
		return;
	le_clear_no (l->topo);
	free(l);
	return;
}

int le_adicionar_no (node *topo, node *no, int codigo, int priority) {
	//Caso tenha chegado no final da lista, insere
	if (no->previous == NULL) {
		node *aux = (node *) malloc (sizeof(node));
		if (aux == NULL)
			return 0;
		aux->item = codigo;
		aux->priority = priority;
		aux->previous = NULL;
		no->previous = aux;
		return 1;
	}
	if (no->previous->item == codigo){
		node *aux = no->previous;
		no->previous = no->previous->previous;
		le_adicionar_no(topo, topo, aux->item, aux->priority + 1);
		return 0;
	}
	//Caso o item seja tenha prioridade menor que o atual, vai seguindo até chegar num item com prioridade maior que ele
	if (no->previous->priority < priority) {
		node *aux = (node *) malloc (sizeof(node));
		if (aux == NULL)
			return 0;
		aux->item = codigo;
		aux->priority = priority;
		aux->previous = no->previous;
		no->previous = aux;
		return 1;
	}
	else
		return le_adicionar_no (topo, no->previous, codigo, priority);
}

int le_adicionar (lista_e *l, int codigo, int priority) {
	if (l == NULL)
		return 0;
	if (le_adicionar_no (l->topo, l->topo, codigo, priority)){
		l->tam++;
		return 1;
	}
	return 0;
}

void le_printf_no(node *no) {
	if (no->previous == NULL)
		return;
	le_printf_no(no->previous);
	printf("%d/%d ", no->previous->item, no->previous->priority);
	return;
}

void le_printf (lista_e *l) {
	if (l == NULL)
		return;
	le_printf_no(l->topo);
	printf("\n");
	return;
}

int le_remover_ultimo (lista_e *l) {
	if (l == NULL || l->tam == 0)
		return 0;
	//aux aponta para o primeiro termo
	node *aux = l->topo->previous;
	//primeiro termo vira o segundo (é removido)
	l->topo->previous = l->topo->previous->previous;
	int aux2 = aux->item;
	free(aux);
	l->tam--;
	return aux2;
}

int le_size (lista_e *l) {
	return l->tam;
}

int le_priority_last_item (lista_e *l) {
	return l->topo->previous->priority;
}

int le_indice_no (node *no, int i) {
	if (i == 0)
		return no->previous->item;
	return le_indice_no (no->previous, i - 1);
}

int le_indice (lista_e *l, int i) {
	if (i >= l->tam)
		return INT_MIN;
	return le_indice_no (l->topo, i);
}