#include "queue.h"
#include <stdio.h>

int queue_size(queue_t *queue) {
    if (queue == NULL) {
        return 0;
    }

    int count = 0;
    queue_t *current = queue;
    do {
        count++;
        current = current->next;
    } while (current != queue);

    return count;
}


// problema ao passar uma queue NULL a função
void queue_print(char *name, queue_t *queue, void print_elem (void*) ){
    
    if (queue == NULL) {
        printf("### Error: Invalid queue.\n");
        return;
    }
    printf("%s", name);
    queue_t *current = queue->next;
    do
    {
        print_elem(current);
        current = current->next;
    } while (current != queue);
}



int queue_append(queue_t **queue, queue_t *elem){
    if (queue == NULL){
        printf("### Error: Queue not exist.\n");
        return -1;
    }

    if (elem == NULL){
        printf("### Error: elem not exist.\n");
        return -2;
    }

    // o elemento nao deve estar em outra fila
    if (elem->next != NULL || elem->prev != NULL){
        printf("%p, %p\n", (void*)elem->next, (void *)elem->prev);
        printf("### Error: elem is already in another queue.\n");
        return -3;
    }

    if(*queue == NULL){
        // Não existe nenhum elemento na fila
        *queue = elem;
        (*queue)->next = elem;
        (*queue)->prev = elem;
        return 0;
    }else{
        // A fila possui elementos, logo adiciono no final fila
        queue_t* last = (*queue)->prev;
        last->next = elem;
        elem->prev = last;
        elem->next = *queue;
        (*queue)->prev = elem;
    }
    return 0;
}



int queue_remove(queue_t **queue, queue_t *elem){
    if (queue == NULL){
        printf("### Error: Queue not exist.\n");
        return -1;
    }

    if (*queue == NULL){
        printf("### Error: Queue is empty.\n");
        return -2;
    }

    if (elem == NULL){
        printf("### Error: elem not exist.\n");
        return -3;
    }

    queue_t* current = *queue;

    do
    {
        if (current == elem) {
            // Atualiza os ponteiros dos elementos adjacentes
            elem->prev->next = elem->next;
            elem->next->prev = elem->prev;

            // Se o elemento a ser removido for o primeiro da fila
            if (*queue == elem) {
                // Se for o único elemento na fila
                if (elem->next == elem) {
                    *queue = NULL;
                } else {
                    *queue = elem->next;
                }
            }

            // Remove as referências do elemento
            elem->next = NULL;
            elem->prev = NULL;

            return 0;
        }
        current = current->next;
    } while (current != *queue);

    return -4;
    
}