//
// Created by Diana on 3/9/2020.
//
#include <stdio.h>
#include "stdlib.h"
#include "dll.h"
void initializeDll() {
    dll_node * node;
    node = (dll_node *) malloc (sizeof(dll_node));
    node->next = node;
    node->prev = node;
    sentinel = node;
    current = sentinel;
}
void addFirst(int data) {
    dll_node * new_node;
    new_node = (dll_node *) malloc (sizeof(dll_node));
    new_node->data = data;
    current = sentinel->next;
    sentinel->next = new_node;
    new_node->prev = sentinel;
    new_node->next = current;
    current->prev = new_node;
}
void addLast(int data) {
    dll_node * new_node;
    new_node = (dll_node *) malloc (sizeof(dll_node));
    new_node->data = data;
    current = sentinel->prev;
    current->next = new_node;
    new_node->prev = current;
    new_node->next = sentinel;
    sentinel->prev = new_node;
}
void deleteFirst() {
    current = sentinel->next;
    if (current == sentinel) {
        return;
    }
    sentinel->next = current->next;
    current->next->prev = sentinel;
    free(current);
}
void deleteLast() {
    current = sentinel->prev;
    if (current == sentinel) {
        return;
    }
    sentinel->prev = current->prev;
    current->prev->next = sentinel;
    free(current);
}
void doomTheList() {
    dll_node * prev;
    current = sentinel->next;
    if(current == sentinel) {
        return;
    }
    else {
        while (current != sentinel) {
            prev = current;
            current = current->next;
            free(prev);
        }
        sentinel->next = sentinel;
        sentinel->prev = sentinel;
    }
}
void deleteElement(int data) {
    current = sentinel->next;
    if (current == sentinel) {
        return;
    }
    while (current != sentinel) {
        if(current->data == data) {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            free(current);
            return;
        }
        current = current->next;
    }
}
void printAll(FILE * output) {
    current = sentinel->next;
    if (current == sentinel) {
        fprintf(output,"list is empty\n");
        return;
    }
    while (current != sentinel) {
        fprintf(output, "%d ", current->data);
        current = current->next;
    }
    fprintf(output, "\n");
}
void printFirstElements(FILE * output,int tillValue) {
    current = sentinel->next;
    if (current == sentinel) {
        fprintf(output,"list is empty\n");
        return;
    }
    int nr = 0;
    while(nr != tillValue && current != sentinel) {
        fprintf(output,"%d ",current->data);
        current = current->next;
        nr++;
    }
    fprintf(output, "\n");
}
void printLastElements(FILE * output,int tillValue) {
    current = sentinel->prev;
    if (current == sentinel) {
        fprintf(output,"list is empty\n");
        return;
    }
    int nr = 1;
    reverse(nr,tillValue,output);
    fprintf(output, "\n");
}
void reverse(int nr,int tillValue,FILE * output) {
    if(nr < tillValue && current != sentinel) {
        current = current->prev;
        reverse(++nr,tillValue,output);
    }
    fprintf(output,"%d ",current->data);
    current = current->next;
}