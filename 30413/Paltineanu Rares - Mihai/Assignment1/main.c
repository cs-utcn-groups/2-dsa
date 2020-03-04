#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define command1 "AF"
#define command2 "AL"
#define command3 "DF"
#define command4 "DL"
#define command5 "DOOM_THE_LIST"
#define command6 "DE"
#define command7 "PRINT_ALL"
#define command8 "PRINT_F"
#define command9 "PRINT_L"


int ct = 0;

typedef struct array {

    int element;
    struct array* next;

} arrayT;

arrayT* first,* last;

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

void addElement(int number, int firstOrLast) {

    if(firstOrLast == 1) {  ///first

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
    } else { ///last

        arrayT* current = (arrayT*)malloc(sizeof(arrayT));
        last->next = current;
        current->element = number;
        current->next = NULL;
        last = current;

    }
}

void deleteElement(int firstOrLast) {

    if(first == NULL) {

        return;

    }

    if(firstOrLast == 1) { ///first

        arrayT* current = first;
        first = first->next;
        free(current);

    } else { ///last

        arrayT* current = first;

        while(current->next != last)
            current = current->next;

        last = current;
        current = last->next;
        free(current);
        last->next = NULL;

    }

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

        if(stricmp(command, command1) == 0) { ///first

            number = takingTheNumber(input);
            addElement(number, 1);
            ct++;

        } else if(stricmp(command, command2) == 0) { /// last

            number = takingTheNumber(input);
            addElement(number, 0);
            ct++;

        } else if(strncmp(command, command3, 2) == 0) { /// first remove

            deleteElement(1);

            if(ct > 0)
                ct--;

        } else if(strncmp(command, command4, 2) == 0) { ///last remove

            deleteElement(0);

            if(ct > 0)
                ct--;

        } else if(strncmp(command, command5, 13) == 0) { ///remove all

            while(first != NULL) {

                deleteElement(1);
                ct = 0;

            }

        } else if(strncmp(command, command6, 2) == 0) { ///remove x

            number = takingTheNumber(input);
            removeX(number);

        } else if(strncmp(command, command7, 9) == 0) { ///printall

            printall();

        } else if(strncmp(command, command8, 7) == 0) { ///printfirstX

            number = takingTheNumber(input);

            if(number > ct)
                printall();
            else
                printFirstX(number);


        } else if(strncmp(command, command9, 7) == 0) { ///printlast

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
    readingCommand(in);

    return 0;
}
