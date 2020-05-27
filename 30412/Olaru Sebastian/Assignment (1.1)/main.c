#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_FUNCTION_CALL 128

void AddElementFirst(int x);

void AddElementLast(int x);

void DeleteFirst();

void DeleteLast();

void DeleteWholeList();

void DeleteElement(int x);

void PrintWholeList();

void PrintFirstNElements(int x);

void PrintLastNElements(int x);

typedef struct element {
    int data;
    struct element *next;
} Element;
Element *first = NULL, *last = NULL;

FILE *fin, *fout;

int main() {
    fin = fopen("input.dat", "r");
    fout = fopen("output.dat", "a");

    char *functionCall = (char *) malloc(MAX_FUNCTION_CALL * sizeof(char));
    int x;

    if (fin != NULL) {
        while (!feof(fin)) {
            fscanf(fin, "%s", functionCall);
            getc(fin);
            if (strcmp(functionCall, "AF") == 0) {
                fscanf(fin, "%d", &x);
                getc(fin);
                AddElementFirst(x);
            }
            if (strcmp(functionCall, "AL") == 0) {
                fscanf(fin, "%d", &x);
                getc(fin);
                AddElementLast(x);
            }
            if (strcmp(functionCall, "DF") == 0) {
                DeleteFirst();
            }
            if (strcmp(functionCall, "DL") == 0) {
                DeleteLast();
            }
            if (strcmp(functionCall, "DOOM_THE_LIST") == 0) {
                DeleteWholeList();
            }
            if (strcmp(functionCall, "DE") == 0) {
                fscanf(fin, "%d", &x);
                getc(fin);
                DeleteElement(x);
            }
            if (strcmp(functionCall, "PRINT_F") == 0) {
                fscanf(fin, "%d", &x);
                getc(fin);
                PrintFirstNElements(x);
            }
            if (strcmp(functionCall, "PRINT_L") == 0) {
                fscanf(fin, "%d", &x);
                getc(fin);
                PrintLastNElements(x);
            }
            if (strcmp(functionCall, "PRINT_ALL") == 0) {
                PrintWholeList();
            }
        }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}

void AddElementFirst(int x) {
    if (first == NULL) {
        first = (Element *) malloc(sizeof(Element));
        first->data = x;
        first->next = NULL;
        last = first;
    } else {
        Element *newElement = (Element *) malloc(sizeof(Element));
        newElement->data = x;
        newElement->next = first;
        first = newElement;
    }

}

void AddElementLast(int x) {
    if (last == NULL) {
        last = (Element *) malloc(sizeof(Element));
        last->data = x;
        last->next = NULL;
        first = last;
    } else {
        Element *newElement = (Element *) malloc(sizeof(Element));
        newElement->data = x;
        newElement->next = NULL;
        last->next = newElement;
        last = newElement;
    }

}

void DeleteFirst() {
    Element *currentElement = first;
    if (currentElement == NULL)
        return;
    first = first->next;
    free(currentElement);
}

void DeleteLast() {
    Element *currentElement = first;
    if (currentElement == NULL)
        return;
    if (first == last) {
        free(first);
        first = NULL;
        last = NULL;
        return;
    }
    while (currentElement->next != NULL) {
        last = currentElement;
        currentElement = currentElement->next;
    }
    free(last->next);
    last->next = NULL;
}

void DeleteWholeList() {
    Element *currentElement;
    while (first != NULL) {
        currentElement = first;
        first = first->next;
        free(currentElement);
    }
    last = NULL;
}

void DeleteElement(int x) {
    Element *currentElements = first;
    Element *previousElement = first;
    while (currentElements != NULL) {
        if (currentElements->data == x) {
            if (currentElements == first) {
                first = first->next;
            } else if (currentElements == last) {
                last = previousElement;
                last->next = NULL;
            } else {
                previousElement->next = currentElements->next;
            }
            previousElement = currentElements;
            currentElements = currentElements->next;
            free(previousElement);
            previousElement = currentElements;
        } else {
            previousElement = currentElements;
            currentElements = currentElements->next;
        }
    }
}

void PrintWholeList() {
    Element *currentElement = first;
    while (currentElement) {
        fprintf(fout, "%d ", currentElement->data);
        currentElement = currentElement->next;
    }
    fprintf(fout, "\n");
}

void PrintFirstNElements(int x) {
    Element *currentElement = first;
    while (currentElement && x) {
        fprintf(fout, "%d ", currentElement->data);
        currentElement = currentElement->next;
        x--;
    }
    fprintf(fout, "\n");
}

void PrintLastNElements(int x) {
    int elementsCount = 0;
    Element *currentElement = first;
    while (currentElement) {
        elementsCount++;
        currentElement = currentElement->next;
    }
    if (x < elementsCount) {
        int skippedElementsCount = elementsCount - x;
        currentElement = first;

        for (int i = skippedElementsCount; i > 0; i--)
            currentElement = currentElement->next;

        for (int i = skippedElementsCount + 1; i <= elementsCount; i++) {
            fprintf(fout, "%d ", currentElement->data);
            currentElement = currentElement->next;
        }
        fprintf(fout, "\n");
    } else {
        PrintWholeList();

    }
}