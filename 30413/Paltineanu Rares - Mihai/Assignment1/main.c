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

    int element;
    struct array* next;

} arrayT;

arrayT* first,* last;

void initialize() {

    first = last = NULL;

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


    if(first == NULL) {

        first = (arrayT*)malloc(sizeof(arrayT));
        first->element = number;
        first->next = last;
        last = first;

    } else {

        arrayT* current = (arrayT*)malloc(sizeof(arrayT));
        current->element = number;
        current->next = first;
        first = current;

    }
}

void addLast(int number) {

    if(last == NULL) {

        first = (arrayT*)malloc(sizeof(arrayT));
        first->element = number;
        first->next = last;
        last = first;

    } else {

        arrayT* current = (arrayT*)malloc(sizeof(arrayT));
        current->element = number;
        last->next = current;
        current->next = NULL;
        last = current;

    }
}

void deleteFirst() {

    if(first == NULL)
        return;

    arrayT* current = first;
    first = first->next;
    free(current);

}

void deleteLast() {

    if(last == NULL)
        return;

    arrayT* current = first;

    while(current->next != last)
        current = current->next;

    last = current;
    current = last->next;
    free(current);
    last->next = NULL;

}

void deleteAll() {

    arrayT* current = first;

    while(current != NULL) {

        first = first->next;
        free(current);
        current = first;

    }
    first = last = NULL;
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


    if(first == NULL)
        return;

    arrayT* current = first;
    int i = 0;

    while(i < number) {

        printf("%d ", current->element);
        current = current->next;
        i++;

    }
    printf("\n");

}

void printLastX(int number) {

    if(first == NULL)
        return;

    arrayT* current = first;
    int i = 0;

    while(i < ct - number) {

        current = current->next;
        i++;
    }

    while(current != NULL) {

        printf("%d ", current->element);
        current = current->next;

    }

    printf("\n");

}

void printall() {


    if(first == NULL) {

        printf("There are no elements in the list.\n");

    } else {


        arrayT* current = first;

        while(current != NULL) {

            printf("%d ", current->element);
            current = current->next;

        }
    }

    printf("\n");

}

void removeX(int number) {

    if(first != NULL) {

        arrayT* previous = (arrayT*)malloc(sizeof(arrayT));
        arrayT* current = first;

        while(current != NULL) {

            if(current->element == number) {

                ct--;

                if(current == first) {

                    first = first->next;

                } else if(current == last) {

                    last = previous;
                    last->next = NULL;

                } else {

                    previous->next = current->next;

                }

                previous = current;
                current = current->next;
                free(previous);
                previous = current;

            } else {

                previous = current;
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

        if(stricmp(command, ADD_FIRST) == 0) {

            number = takingTheNumber(input);
            addFirst(number);
            ct++;

        } else if(stricmp(command, ADD_LAST) == 0) {

            number = takingTheNumber(input);
            addLast(number);
            ct++;

        } else if(strncmp(command, DELETE_FIRST, 2) == 0) {

            deleteFirst();

            if(ct > 0)
                ct--;

        } else if(strncmp(command, DELETE_LAST, 2) == 0) {

            deleteLast();

            if(ct > 0)
                ct--;

        } else if(strncmp(command, DELETE_ALL, 13) == 0) {

                deleteAll();
                ct = 0;

        } else if(strncmp(command, DELETE_ELEMENT, 2) == 0) {

            number = takingTheNumber(input);
            removeX(number);

        } else if(strncmp(command, PRINT_ALL, 9) == 0) {

            printall();

        } else if(strncmp(command, PRINT_FIRST, 7) == 0) {

            number = takingTheNumber(input);

            if(number > ct)
                printall();
            else
                printFirstX(number);


        } else if(strncmp(command, PRINT_LAST, 7) == 0) {

            number = takingTheNumber(input);

            if(number > ct)
                printall();
            else
                printLastX(number);

        }
    }
}

int main() {

    FILE* in = fopen("input.data", "r");

    if(in == NULL) {

        return -1;

    }

    initialize();
    readingCommand(in);

    return 0;
}
