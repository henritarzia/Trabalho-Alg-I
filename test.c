#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada_noCabeca_ordenada.h"

int main(int argc, char const *argv[])
{
	int aux = 1;
	char aux2;
	lista_e *l = le_criar();
	while (aux) {
		aux2 = getchar();
		if (aux2 == 'a'){
			scanf("%d", &aux);
			le_adicionar(l, aux, 1);
		}
		else if (aux2 == 'r'){
			scanf("%d", &aux);
			printf("%d\n", le_indice (l, aux));
		}
		else if (aux2 == 'p')
			le_printf(l);
	}
	le_printf(l);
	le_clear(l);
	return 0;
}