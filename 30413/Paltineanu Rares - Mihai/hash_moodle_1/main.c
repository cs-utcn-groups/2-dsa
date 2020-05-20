#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100000
///65 ascii for A
///97 ascii for a

typedef struct hash {

    char* name;
    struct hash* next;

} hashT;

hashT* hashTable[SIZE];

void initialize() {

    for(int i = 0; i < SIZE; i++)
        hashTable[i] = NULL;

}

int upperOrLower(char character) {

    return (character >= 'A') ? 1 : 0;

}

hashT* createElement(char* name) {

    hashT* element = (hashT*)malloc(sizeof(hashT));
    element->name = (char*)malloc(30);
    strcpy(element->name, name);
    element->next = NULL;

    return element;

}

int poww(int power) {

    int value = 1;
    for(int i = 1; i <= power; i++) {

        value = value * 26 % SIZE;

    }

    return value;

}

int hashValue(char* name) {

    int size = strlen(name);
    int hashNumber = 0;
    int power;

    for(int i = 0; i < size; i++) {

        if(name[i] == ' ')
            continue;

        power = poww(i);
        if(upperOrLower(name[i]) == 1) {/// upper

            hashNumber = hashNumber + power * (name[i] - 64);

        } else {

            hashNumber = hashNumber + power * (name[i] - 96);

        }

        hashNumber %= SIZE;

    }

    return hashNumber;
}

void insertName(char* name) {

    int hashVal = hashValue(name);
    hashT* p = createElement(name);

    if(hashTable[hashVal] == NULL) {

        hashTable[hashVal] = p;

    } else {

        hashT* pointer = hashTable[hashVal];
        while(pointer->next != NULL)
            pointer = pointer->next;

        pointer->next = p;

    }
}

int findName(char* name) {

    int hashVal = hashValue(name);

    if(hashTable[hashVal] == NULL)
        return 0;
    else {

        if(strcmp(name, hashTable[hashVal]->name) == 0)
            return 1;
        else {

            hashT* pointer = hashTable[hashVal];
            while(pointer != NULL && strcmp(name, pointer->name) != 0)
                pointer = pointer->next;

            if(pointer == NULL)
                return 0;
            else
                return 1;

        }
    }
}

void deleteElement(char* name) {

    int hashVal = hashValue(name);
    hashT* previous = hashTable[hashVal];
    hashT* current = previous;

    while(strcmp(current->name, name) != 0) {

        previous = current;
        current = current->next;

    }

    if(current->next == NULL) {

        free(current);
        previous->next = NULL;

    } else {

        previous->next = current->next;
        previous = current;
        current = current->next;
        free(previous);

    }
}

void readCommand(FILE* in) {

    char* command = (char*)malloc(30);

    while(fgets(command, 30, in) != NULL) {

        command[strlen(command) - 1] = '\0';
        switch (command[0]) {

        case 'i':

            insertName(command + 1);

            break;

        case 'f':
            if(findName(command + 1) == 1)
                printf("%s exists.\n", command + 1);
            else
                printf("%s does not exist.\n", command + 1);
            break;

        case 'd':
            if(findName(command + 1) == 0)
                printf("Can not delete %s because it does not exist.\n", command + 1);
            else {

                deleteElement(command + 1);

            }
            break;
        }
    }
}

int main(int argc, char* argv[]) {

    FILE* in = fopen(argv[1], "r");
    initialize();
    readCommand(in);

    return 0;

}
