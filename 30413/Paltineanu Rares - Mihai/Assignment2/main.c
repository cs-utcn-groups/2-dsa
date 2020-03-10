#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ADD_FIRST "AF"
#define ADD_LAST "AL"
#define DELETE_FIRST "DF"
#define DELETE_LAST "DL"
#define DELETE_ALL "DOOM_THE_LIST"
#define DELETE_ELEMENT "DE"
#define PRINT_ALL "PRINT_ALL"
#define PRINT_FIRST "PRINT_F"
#define PRINT_LAST "PRINT_L"

int ct = 0;

typedef struct array {

    int element;    ///actually, i cant stop puttin empty lines, i'm sorry :))
    struct array* next;
    struct array* previous;

} arrayT;

typedef struct sentinel {

    arrayT* first;
    arrayT* last;

} sentinel;

sentinel* sent;

void initialize() {

    sent = (sentinel*)malloc(sizeof(sentinel));
    sent->first = NULL;
    sent->last = NULL;

}

char* takingTheCommand(char* array) {

    int i = 0;
    char* command = (char*)malloc(30);

    while(array[i] != ' ' && array[i] != '\0') {

        command[i] = array[i];
        i++;

    }

    command[i] = '\0';
    return command;

}

void addFirst(int number) {

    arrayT* current = (arrayT*)malloc(sizeof(arrayT));
    current->element = number;
    current->previous = NULL;

    if(sent->first == NULL) {

        current->next = NULL;
        sent->first = current;
        sent->last = current;

    } else {

        current->next = sent->first;
        sent->first->previous = current;
        sent->first = current;

    }
}

void addLast(int number) {

    arrayT* current = (arrayT*)malloc(sizeof(arrayT));
    current->element = number;
    current->next = NULL;

    if(sent->last == NULL) {

        current->previous = NULL;
        sent->first = current;
        sent->last = current;

    } else {

        current->previous = sent->last;
        sent->last->next = current;
        sent->last = current;

    }
}

void deleteFirst() {

    if(sent->first == NULL)
        return;

    arrayT* current = sent->first;
    sent->first = sent->first->next;
    sent->first->previous = NULL;
    free(current);

}

void deleteLast() {

    arrayT* current = sent->last;

    if(current != NULL) {

        sent->last = sent->last->previous;
        sent->last->next = NULL;
        free(current);

    }
}

void deleteAll() {

    if(sent->first != NULL) {

        arrayT* current = sent->first;
        while(current != NULL) {

            sent->first = sent->first->next;
            free(current);
            current = sent->first;

        }
    }

    sent->first = sent->last = NULL;

}

int takingTheNumber(char* array) {

    int i = 0;
    int number = 0;
    int negativenumber = 0;

    while(!(array[i] >= '0' && array[i] <= '9'))
        i++;

    if(array[i - 1] == '-') {

        negativenumber = -1;

    } else {

        negativenumber = 1;

    }

    while(array[i] >= '0' && array[i] <= '9' && array[i] != '\0') { /// add first

        number = number * 10 + (array[i] - '0');
        i++;

    }

    number*= negativenumber;
    return number;

}

void printFirstX(int number) {

    arrayT* current = sent->first;
    int i = 0;

    while(i < number) {

        printf("%d ", current->element);
        current = current->next;
        i++;

    }

    printf("\n");

}

void printLastX(int number) {

    if(sent->first == NULL)
        return;

    arrayT* current = sent->last;
    int i = 1;

    while(i < number) {

        current = current->previous;
        i++;

    }

    while(current != NULL) {

        printf("%d ", current->element);
        current = current->next;

    }

    printf("\n");
}

void printall() {

    if(sent->first == NULL) {

        printf("There are no elements in the list.\n");

    } else {

        arrayT* current = sent->first;

        while(current != NULL) {

            printf("%d ", current->element);
            current = current->next;

        }
    }

    printf("\n");
}

void removeX(int number) {

    if(sent->first != NULL) {

        arrayT* previousT = sent->first;
        arrayT* current = sent->first;

        while(current != NULL) {
            if(current->element == number) {

                ct--;

                if(current == sent->first) {

                    sent->first = sent->first->next;
                    sent->first->previous = NULL;

                } else if(current == sent->last) {

                    sent->last = previousT;
                    sent->last->next = NULL;

                } else {

                    previousT->next = current->next;

                }

                previousT = current;
                current = current->next;
                current->previous = previousT->previous;
                free(previousT);
                previousT = current;

            } else {

                previousT = current;
                current = current->next;

            }
        }
    }
}

void readingCommand(FILE* in) {

    char* input = (char*)malloc(50);
    char* command = (char*)malloc(30);
    int number;

    while(fgets(input, 50, in) != NULL) {

        command = takingTheCommand(input);

        if(stricmp(command, ADD_FIRST) == 0) { ///first

            number = takingTheNumber(input);
            addFirst(number);
            ct++;

        } else if(stricmp(command, ADD_LAST) == 0) { /// last

            number = takingTheNumber(input);
            addLast(number);
            ct++;

        } else if(strncmp(command, DELETE_FIRST, 2) == 0) { /// first remove

            deleteFirst();

            if(ct > 0) {
                ct--;
            }

        } else if(strncmp(command, DELETE_LAST, 2) == 0) { ///last remove

            deleteLast();

            if(ct > 0) {
                ct--;
            }

        } else if(strncmp(command, DELETE_ALL, 13) == 0) { ///remove all

            deleteAll();
            ct = 0;

        } else if(strncmp(command, DELETE_ELEMENT, 2) == 0) { ///remove x

            number = takingTheNumber(input);
            removeX(number);

        } else if(strncmp(command, PRINT_ALL, 9) == 0) { ///printall

            printall();

        } else if(strncmp(command, PRINT_FIRST, 7) == 0) { ///printfirstX

            number = takingTheNumber(input);

            if(number > ct)
                printall();
            else
                printFirstX(number);

        } else if(strncmp(command, PRINT_LAST, 7) == 0) { ///printlast

            number = takingTheNumber(input);

            if(number > ct)
                printall();
            else
                printLastX(number);

        }
    }
}

int main() {

    FILE* in = fopen("input.dat", "r");

    if(in == NULL)
        return -1;

    initialize();
    readingCommand(in);

    return 0;

}
