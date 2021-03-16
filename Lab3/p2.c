#include <stdio.h>
#include "lista.h"
#include <stdlib.h>

int main(){
    TList *list;
    node *aux;
    //Test impar
    int p=1, i=2, j=3, k=4, l=5;
    init(&list);
    add(list, 0, &p);
    add(list, 0, &i);
    add(list, 0, &j);
    add(list, 0, &k);
    add(list, 0, &l);
    aux = mid_list(list);
    printf("Pentru lista 5 4 3 2 1, mijlocul este:%d\n", *(int*)aux->data);
    free_list(&list);
    //Test par
    init(&list);
    add(list, 0, &p);
    add(list, 0, &i);
    add(list, 0, &j);
    add(list, 0, &k);
    aux = mid_list(list);
    printf("Pentru lista 4 3 2 1, mijlocul este:%d\n", *(int*)aux->data);
    free_list(&list);
    return 0;
}

node* mid_list(TList *list){
    node *p, *q;
    p = list->head;
    q = list->head;
    while(1){
        p = p->next;
        if(p == NULL){
            break;
        }
        p = p->next;
        if(p == NULL){
            break;
        }
        q  = q->next;
    }
    return q;
}

void init(TList **list){
    (*list) = malloc(sizeof(node));
    (*list)->head = NULL;
    (*list)->len = 0;
}

int add(TList *list, int n, void* data){
    if(n<0 || n > list->len){
        return -1;
    }
    node *q = malloc(sizeof(node));
    q->data = data;
    //Caz I: inseram in capat
    if(n == 0){
        q->next = list->head;
        list->head = q;
        list->len++;
        return 1;
    }
    //Caz II: inseram la final
    if(n == list->len){
        node* aux = list->head;
        q->next = NULL;
        while(aux->next!=NULL){
            aux = aux->next;
        }
        aux->next = q;
        list->len++;
        return 1;
    }
    //Caz III: inseram pe o pozitie anume
    else{
        int cursor=0;
        node* aux = list->head;
        while(cursor<n){
            aux = aux->next;
            cursor++;
        }
        q->next = aux->next;
        aux->next = q;
        list->len++;
        return 1;
    }
}

void print_int_list(TList *list){
    if(list->len == 0){
        printf("Nu exista elemente in lista!\n");
        return;
    } 
    int i;
    for(i=0;i<list->len;i++){
        printf("%d\n", *(int*)list->head->data);
        list->head = list->head->next;
    }
}

void print_string_list(TList *list){
    if(list->len == 0){
        printf("Nu exista elemente in lista!\n");
        return;
    } 
    int i;
    for(i=0;i<list->len;i++){
        printf("%s\n", (char*)list->head->data);
        list->head = list->head->next;
    }
}

int length(TList *list){
    return list->len;
}

//Am schimbat numele functiei pentru ca imi dadea "Conficting types for remove"
//din cauza unei functii din <stdio.h>
node* remove_node(TList *list, int n){
    //Intoarce NULL daca n e prea mare sau negativ.
    if(n<0 || n > list->len){
        return NULL;
    }
    //Caz I: scoatem primul element.
    node* aux = list->head;
    if(aux == NULL){
        return aux;
    }
    if(n == 0){
        list->head = aux->next;
        return aux;
    }
    if(n == list->len){
        while(aux->next!=NULL){
            aux = aux->next;
        }
        list->head = aux->next;
        return aux;
    }
    else{
        int cursor=0;
        while(cursor<n){
            aux = aux->next;
            cursor++;
        }
        list->head = aux->next;
        return aux;
    }
}

void free_list(TList **list){
    int len=length(*list);
    node* aux;
    while(len>0){
        aux = remove_node(*list, 0);
        if(aux == NULL){
            break;
        }
        free(aux);
        (*list)->len--;
        len = length(*list);
    }
    free(*list);
}