#ifndef lista_encadeada_noCabeca_ordenada_h
#define lista_encadeada_noCabeca_ordenada_h
typedef struct Node node;
typedef struct Cabeca_lista lista_e;

#ifndef INT_MIN
#define INT_MIN -2147483648
#endif

lista_e *le_criar ();
int le_priority_last_item (lista_e *);
int le_adicionar(lista_e *, int, int);
int le_remover_ultimo (lista_e *);
int le_indice (lista_e *, int);
int le_size (lista_e *);
void le_clear(lista_e *);
void le_printf(lista_e *);
#endif