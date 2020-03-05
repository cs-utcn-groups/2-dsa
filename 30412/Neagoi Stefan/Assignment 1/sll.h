
#ifndef DUMMY_REPO_SLL_H
#define DUMMY_REPO_SLL_H

typedef struct node {

int data;
struct node * next;

} NodeT;

NodeT * first, * last;

void initializeList();
void AF(int data);
void AL(int data);
void DF();
void DL();
void PRINT_ALL();
void DE(int data);
void PRINT_L(int data,int ct);
void PRINT_F(int data);
void DOOM_LIST();
int getListLength();

#endif //DUMMY_REPO_SLL_H
