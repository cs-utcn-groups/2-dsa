#include "head.h"
#include "instructions.c"

int main() {
    FILE * fptrin;
    fptrin = fopen("D:\\Facultate\\SEM2\\DSA\\Assignment2\\input.dat", "r");
    if(fptrin == NULL){
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }

    fptrout = fopen("D:\\Facultate\\SEM2\\DSA\\Assignment2\\output.dat", "w");
    if(fptrout == NULL){
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }

    initializeDll();

    char *c;
    int n;
    c = (char*)malloc(sizeof(char));
    for(int i=1;i<=21;i++){
        fscanf(fptrin, "%s", c);
        if(strcmp("AF",c)==0){
            fscanf(fptrin, "%d", &n);
            addFirst(n);
        }
        else if(strcmp("AL",c)==0){
            fscanf(fptrin, "%d", &n);
            addLast(n);
        }
        else if(strcmp("PRINT_ALL",c)==0){
            printDllData();
        }
        else if(strcmp("DF",c)==0){
            deleteFirst();
        }
        else if(strcmp("DL",c)==0){
            deleteLast();
        }
        else if(strcmp("DE",c)==0){
            fscanf(fptrin, "%d", &n);
            deleteX(n);
        }
        else if(strcmp("PRINT_F",c)==0){
            fscanf(fptrin, "%d", &n);
            printFirstXElements(n);
        }
        else if(strcmp("PRINT_L",c)==0){
            fscanf(fptrin, "%d", &n);
            printLastXElements(n);
        }
        else if(strcmp("DOOM_THE_LIST",c)==0){
            deleteAll();
        }
    }
    fclose(fptrin);
    fclose(fptrout);
    return 0;
}