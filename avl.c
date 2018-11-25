#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "site.h"
#include "avl.h"
#include "lista_encadeada_noCabeca_ordenada.h"

struct _avl{
	site *reg;
	avl *filho_esq;
	avl *filho_dir;
	int altura;
};

avl *avl_criar(site *reg){
	avl *novo = (avl*)malloc(sizeof(avl));
	novo->reg = reg;
	novo->filho_esq = NULL;
	novo->filho_dir = NULL;
	novo->altura = 0; 
	return novo;
}

void avl_apagar(avl *T){
	if (T == NULL)
		return;
	avl_apagar(T->filho_esq);
	avl_apagar(T->filho_dir);
	free(T->reg);
	free(T);
	T = NULL;
	return;
}

int maior(int a,int b){
	return (a > b) ? a : b;
}

int altura(avl *no){
	if(no == NULL)
		return -1;
	return maior(altura(no->filho_esq),altura(no->filho_dir)) + 1;
}

avl *roda_esq(avl *A){
	avl *B = A->filho_dir;
	A->filho_dir = B->filho_esq;
	B->filho_esq = A;
	A->altura = maior(altura(A->filho_esq),altura(A->filho_dir)) + 1;
	B->altura = maior(altura(B->filho_esq),altura(B->filho_dir)) + 1;
	return B;
}

avl *roda_dir(avl *A){
	avl *B = A->filho_esq;
	A->filho_esq = B->filho_dir;
	B->filho_dir = A;
	A->altura = maior(altura(A->filho_esq),altura(A->filho_dir)) + 1;
	B->altura = maior(altura(B->filho_esq),altura(B->filho_dir)) + 1;
	return B;
}

avl *roda_esq_dir(avl *A){
	A->filho_esq = roda_esq(A->filho_esq);
	return roda_dir(A);
}

avl *roda_dir_esq(avl *A){
	A->filho_dir = roda_dir(A->filho_dir);
	return roda_esq(A);
}

avl *avl_busca_codigo(avl *a, int codigo){
	if (a == NULL)
		return NULL;
	if (site_codigo(a->reg) == codigo)
		return a;
	else if (codigo > site_codigo(a->reg))
		return avl_busca_codigo (a->filho_dir, codigo);
	else
		return avl_busca_codigo (a->filho_esq, codigo);
}

void chave_nova_inserir(avl *noh,int codigo,char *nova_chave){
	if(noh == NULL){
		printf("<Erro> Codigo %d nao encontrado.\n",codigo);
		return;
	}
	if(codigo > site_codigo(noh->reg))
		chave_nova_inserir(noh->filho_dir,codigo,nova_chave);
	else if(codigo < site_codigo(noh->reg))
		chave_nova_inserir(noh->filho_esq,codigo,nova_chave);
	else{
		if(site_qtd_chaves(noh->reg) < 10)
			site_chave_inserir(noh->reg,nova_chave);	
		else 
			printf("<Erro> Limite de chaves atingido.\n");
	}
	return;
}

void avl_relevancia_atualizar(avl *a, int codigo, int nova_relevancia){
	if (codigo < 0 || nova_relevancia < 0 || nova_relevancia > 1000){
		printf("<Erro> Parametro declarado fora do intervalo permitido.\n\n");
		return;
	}
	avl *aux = avl_busca_codigo (a, codigo);
	site_atualizar_relevancia (aux->reg, nova_relevancia);
	printf("Relevancia atualizada.\n\n");
	return;
}

void avl_printf(avl *arv) {
	if (arv == NULL)
		return;
	avl_printf(arv->filho_esq);
	site_printf(arv->reg);
	avl_printf(arv->filho_dir);
	return;
}

/*
	avl_inserir:
	Função: insere um site na árvore
*/

avl *avl_inserir (avl *arv, site *s){
	//checa se o site existe
	if (s == NULL)
		return NULL;
	//checa se a árvore existe
	if (arv == NULL)
		arv = avl_criar(s);
	//checa se o codigo a ser inserido é maior que o codigo do no atual
	else if (site_codigo(s) > site_codigo(arv->reg)){
		//se sim, executa o algoritmo pro lado direito da árvore
		arv->filho_dir = avl_inserir (arv->filho_dir, s);
		//faz o balanceamento da árvore
		if (altura(arv->filho_esq) - altura(arv->filho_dir) == -2) {
			if (site_codigo(s) > site_codigo(arv->filho_dir->reg))
				arv = roda_esq(arv);
			else 
				arv = roda_dir_esq(arv);
		}
	}
	else if (site_codigo(s) < site_codigo(arv->reg)) {
		//se nao, executa o algoritmo pro lado esquerdo da árvore
		arv->filho_esq = avl_inserir (arv->filho_esq, s);
		//faz o balanceamento da árvore
		if (altura(arv->filho_esq) - altura(arv->filho_dir) == 2) {
			if (site_codigo(arv->reg) < site_codigo(arv->filho_esq->reg))
				arv = roda_dir(arv);
			else
				arv = roda_esq_dir(arv);
		}
	}
	//atualiza a altura
	arv->altura = altura(arv);

	return arv;
}

avl* menor_no(avl* raiz){
	avl* menor = raiz;
	while(menor->filho_esq != NULL)
		menor = menor->filho_esq;	
	return menor;
}

void balance(avl* arv){
	if (altura(arv->filho_esq) - altura(arv->filho_dir) == -2){
			if (site_codigo(arv->reg) > site_codigo(arv->filho_dir->reg))
				arv = roda_esq(arv);
			else 
				arv = roda_dir_esq(arv);
	}
	if (altura(arv->filho_esq) - altura(arv->filho_dir) == 2) {
			if (site_codigo(arv->reg) < site_codigo(arv->filho_esq->reg))
				arv = roda_dir(arv);
			else
				arv = roda_esq_dir(arv);
	}
}

avl* remover_avl(avl* raiz, int ID){
	if(raiz == NULL){
		printf("<Erro> Site com ID %d nao encontrado.\n\n",ID);
		return raiz;
	 }
	//caso ir pra esquerda
	if(ID < site_codigo(raiz->reg))
	  raiz->filho_esq = remover_avl(raiz->filho_esq, ID);
	//caso ir pra direita  
	else if(ID > site_codigo(raiz->reg))
      raiz->filho_dir = remover_avl(raiz->filho_dir, ID);
	  
	//caso estamos aonde queremos mudar  
	else{
		printf("Site com ID %d removido com sucesso.\n\n",ID);
		//Caso 1 filho ou nenhum
		if((raiz->filho_esq == NULL) || (raiz->filho_dir == NULL)){
			avl* aux = raiz->filho_esq ? raiz->filho_esq: raiz->filho_dir;
			//sem filhos
			if(aux == NULL){
				aux = raiz;
				raiz = NULL;
			}
			else 
				*raiz = *aux;	 
			free(aux);
		}
	 	//Caso dois filhos
	    else
	    {
		   avl* aux = menor_no(raiz->filho_dir); //menor da direita;
		   raiz->reg = aux->reg;
		   raiz->filho_dir = remover_avl(raiz->filho_dir,site_codigo(aux->reg));
		}		
	}
	//se só tivesse um nó na arvore
	if(raiz == NULL)
     return raiz;
	//Atualizar a altura
	raiz->altura = altura(raiz);
	//Balancear a arvore;
	balance(raiz);
	raiz->altura = altura(raiz);
	return raiz;
}

avl *arquivo_ler(){
	FILE *fr = fopen("googlebot.txt","r");
	avl *T = NULL;
	int flag = 0;
	
	char aux[650];
	int codigo;
	char nome[50];
	int relevancia;
	char link[100];
	char palavraschaves[500];

	char **chaves = (char**) malloc (sizeof(char*) * 10);
	int qtd_chaves;

	if(fr == NULL)
		printf("<Erro> Leitura do arquivo falhou.\n");

	while(fgets(aux, 650, fr) != NULL){
		sscanf(aux,"%d%*c%[^,]%*c%d%*c%[^,]%*c%[^\n]", &codigo, nome, &relevancia, link, palavraschaves);
		chaves[0] = strtok (palavraschaves, ",\n ");
		int i = 0;
		while (chaves[i] != NULL && i < 10)
			chaves[++i] = strtok(NULL, ",\n ");
				
		T = avl_inserir(T, site_criar(codigo, nome, relevancia, link, chaves, i));
		flag++;
	}
	fclose(fr);

	if (flag > 0){
		printf("Arquivo lido com sucesso.\n");
		printf("Pressione Enter para continuar.\n");
		getchar();
	}

	free(chaves);
	return T;
}

void avl_fprintf(avl *T,FILE *fp){
	if (T == NULL)
		return;
	avl_fprintf(T->filho_esq,fp);
	site_fprintf(T->reg,fp);
	avl_fprintf(T->filho_dir,fp);
	return;
}

void arquivo_salvar(avl *T){
	if (T == NULL){
		printf("Nada para gravar\n");
		return;
	}
	
	FILE *fp = fopen("googlebot.txt", "w");
	if (fp == NULL){
		printf("Falha na gravação do arquivo\n");
		return;
	}
	
	avl_fprintf(T,fp);

	printf("Gravado com sucesso.\n");
	printf("Pressione Enter para continuar\n");
	getchar();
	
	fclose(fp);
	return;
}

/*
	avl_procurar:
	Função: armazena na lista_e **l todos os códigos que tenham a chave "string" dando prioridade "priority" para eles
*/


void avl_procurar(avl *T, lista_e **l, char *string, int priority) {
	//Se chegar no final da árvore retorna
	if (T == NULL)
		return;
	//Sub-árvore esquerda
	avl_procurar(T->filho_esq, l, string, priority);
	//caso o nó atual tenha a palavra, armazena seu código
	if (site_procurar_chave (T->reg, string))
		le_adicionar(*l, site_codigo(T->reg), priority);
	//Sub-árvore direita
	avl_procurar(T->filho_dir, l, string, priority);

	return;
}

/*
	avl_busca:
	Função: Procura e imprime todas os sites que possuam a palavra string jutamente com as sugestões
*/

void avl_busca (avl *T, char *string) {
	if (T == NULL)
		return;
	lista_e *contemPalavra = le_criar();
	//encontra todas os sites que possuam a palavra pesquisada
	avl_procurar (T, &contemPalavra, string, 1000);
	//encontra todos os sites que possuam palavras relacionadas com os sites encontrados acima
	for (int i = 0, j = le_size(contemPalavra); i < j; ++i){
		//retorna o no do código pesquisado
		avl *no = avl_busca_codigo(T, le_indice(contemPalavra, i));
		//pesquisa todas as palavras dos novos sites encontrados, com exceção da palavra "string"
		for (int k = 0; k < site_qtd_chaves(no->reg); ++k) 
			if (strcmp(site_chave(no->reg, k), string) != 0)
				avl_procurar (T, &contemPalavra, site_chave(no->reg, k), 1);
				
	}
	//enquanto houver um item na lista, imprime
	while (le_size (contemPalavra))
		site_printf(avl_busca_codigo(T, le_remover_ultimo(contemPalavra))->reg);
	le_clear(contemPalavra);
	return;
}