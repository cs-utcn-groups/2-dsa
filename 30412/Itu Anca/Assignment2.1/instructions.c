#include "head.h"

void initializeDll(){
    head = NULL;
    last = NULL;
}

void addFirst(int data){
    NodeT *newElement = (NodeT*)malloc(sizeof(NodeT));
    newElement->data = data;

    if(head == NULL){
        head = last = newElement;
        newElement->prev = newElement->next = NULL;
    }
    else{
        head->prev = newElement;
        newElement->prev = NULL;
        newElement->next = head;
        head = newElement;
    }
}

void addLast(int data){
    NodeT *newElement = (NodeT*)malloc(sizeof(NodeT));
    newElement->data = data;

    if(head == NULL){
        head = last = newElement;
        newElement->prev = newElement->next = NULL;
    }
    else{
        last->next = newElement;
        newElement->prev = last;
        newElement->next = NULL;
        last = newElement;
    }
}

void deleteFirst(){
    NodeT *p;
    p = head;
    head = head->next;
    free(p);
    if(head == NULL){
        last = NULL;
    }
    else{
        head->prev = NULL;
    }
}

void deleteLast(){
    NodeT *p;
    p = last;
    if(head != NULL && last != NULL){
        if(p==head && p==last){
            head = NULL;
            last = NULL;
            free(p);
        }
        else{
            last = last->prev;
            last->next = NULL;
            free(p);
        }
    }
}

void deleteX(int x){
    NodeT *p;
    for(p=head; p!=NULL; p=p->next){
        if(p->data == x){
            if(p==head && p==last){  //there is only one element => the list becomes empty
                head = NULL;
                last = NULL;
                free(p);
            }
            else if(p == head){
                head = head->next;
                head->prev = NULL;
                free(p);
            }
            else if(p == last) {
                last = last->prev;
                last->next = NULL;
                free(p);
            }
            else{
                p->next->prev = p->prev;
                p->prev->next = p->next;
                free(p);
            }
        }
    }
}

void printFirstXElements(int x){
    if(head == NULL){
        fprintf(fptrout, "The list is empty!");
    }
    else{
        NodeT * ptr;
        ptr = head;
        int i=1;
        while(i <= x && ptr != NULL){
            fprintf(fptrout, "%d ", ptr->data);
            ptr = ptr->next;
            i++;
        }
    }
    fprintf(fptrout, "\n");
}

void printLastXElements(int x){
    if(head == NULL){
        fprintf(fptrout, "The list is empty!");
    }
    else{
        NodeT *p = head;
        int length=0;
        while(p != NULL){
            p = p->next;
            length++;
        }
        p = head;
        for( int nr = 1 ; nr <= length ; nr ++ ){
            if(nr < length - x + 1){
                p = p->next;
            }
            else{
                fprintf(fptrout, "%d ", p->data);
                p = p->next;
            }
        }
    }
    fprintf(fptrout, "\n");
}

void printDllData(){
    NodeT * ptr;
    ptr = head;
    if(head == NULL){
        fprintf(fptrout, "The list is empty!");
    }
    while(ptr!=NULL){
        fprintf(fptrout, "%d ", ptr->data);
        ptr = ptr->next;
    }
    fprintf(fptrout, "\n");
}

void deleteAll(){
    NodeT *p = head;
    while(p != NULL){
        head = head->next;
        free(p);
        p = head;
    }
    last = NULL;
}

//
// Created by Anca on 3/8/2020.
//

