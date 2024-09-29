#ifndef __QUEUE__
#define __QUEUE__

#ifndef NULL
#define NULL ((void *) 0)
#endif

// estrutura de uma fila genérica, sem conteúdo definido.
typedef struct queue_t
{
   struct queue_t *prev ;  // aponta para o elemento anterior na fila
   struct queue_t *next ;  // aponta para o elemento seguinte na fila
} queue_t ;

// Retorna o numero de elementos na fila
int queue_size (queue_t *queue) ;

// Percorre a fila e imprime na tela seu conteúdo. A impressão de cada
// elemento é feita por uma função externa, definida pelo programa que
// usa a biblioteca. Essa função deve ter o seguinte protótipo:
// void print_elem (void *ptr) ; // ptr aponta para o elemento a imprimir
void queue_print (char *name, queue_t *queue, void print_elem (void*) ) ;

// Insere um elemento no final da fila.
// Condiçoes a verificar, gerando msgs de erro:
// - a fila deve existir
// - o elemento deve existir
// - o elemento nao deve estar em outra fila
// retornos: 
//   0 Sucesso
//  -1 Erro, a fila não existe
//  -2 Erro, o elemento a ser adicionado na fila não existe
//  -3 Erro, o elemento já está em outra fila
int queue_append (queue_t **queue, queue_t *elem) ;

// Remove o elemento indicado da fila, sem o destruir.
// Condicoes a verificar, gerando msgs de erro:
// - a fila deve existir
// - a fila nao deve estar vazia
// - o elemento deve existir
// - o elemento deve pertencer a fila indicada
// retornos: 
//   0 Sucesso
//  -1 Erro, a fila não existe
//  -2 A fila está vazia
//  -3 Erro, o elemento a ser removido da fila não existe
//  -4 Elemento a ser removido não encontrado na fila
int queue_remove (queue_t **queue, queue_t *elem) ;

#endif
