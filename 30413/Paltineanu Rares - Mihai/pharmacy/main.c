#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct information {

    char* name;
    float price;
    int amount;
    int dateOfManufacturing;
    int dateOfExpiration;

} inf;

typedef struct tree {

    inf* info;
    struct tree* left,* right;

} treeT;

treeT* root;

typedef struct treeExp {

    inf* info;
    struct treeExp* left,* right;

} treeExpT;

treeExpT* rootExp;

treeT* initialize(treeT* current) {

    current = (treeT*)malloc(sizeof(treeT));
    current->info = (inf*)malloc(sizeof(inf));
    current->info->name = (char*)malloc(40);
    current->left = current->right = NULL;
    return current;

}

treeExpT* initializeExp(treeExpT* current) {

    current = (treeExpT*)malloc(sizeof(treeExpT));
    current->info = (inf*)malloc(sizeof(inf));
    current->info->name = (char*)malloc(40);
    current->left = current->right = NULL;
    return current;

}

float convertCharToFloat(char* array) {

    int i = 0;
    float price = 0.0;
    int sumAfterPoint = 0;
    int point = 1;

    while(array[i] != '.' && array[i] != '\0') {

        price = price * 10.0 + (float)(array[i] - '0');
        i++;

    }
    if(array[i] != '\0')
        i++;

    while(array[i] != '\0') {


        sumAfterPoint = sumAfterPoint * 10 + (array[i] - '0');
        point *= 10;
        i++;

    }

    price = price + (float)sumAfterPoint / point;
    return price;

}

char* takingTheName(char* array) {

    char* name = (char*)malloc(40);
    int i = 0;

    while(array[i] != ',') {

        name[i] = array[i];
        i++;

    }
    name[i] = '\0';

    return name;

}

treeT* insert(treeT* current, char* name, float price, int amount, int dateOfManufacturing, int dateOfExpiration) {

    if(current == NULL) {

        current = initialize(current);
        strcpy(current->info->name, name);
        current->info->price = price;
        current->info->amount = amount;
        current->info->dateOfManufacturing = dateOfManufacturing;
        current->info->dateOfExpiration = dateOfExpiration;

    } else if(strcmp(current->info->name, name) > 0)
        current->left = insert(current->left, name, price, amount, dateOfManufacturing, dateOfExpiration);
    else if(strcmp(current->info->name, name) < 0)
        current->right = insert(current->right, name, price, amount, dateOfManufacturing, dateOfExpiration);

    return current;

}

void find(treeT* current, char* name, float* price, int* amount, int* dateOfManufacturing, int* dateOfExpiration) {

    if(strcmp(current->info->name, name) > 0)
        find(current->left, name, price, amount, dateOfManufacturing, dateOfExpiration);
    else if(strcmp(current->info->name, name) < 0)
        find(current->right, name, price, amount, dateOfManufacturing, dateOfExpiration);
    else {

        (*price) = current->info->price;
        (*amount) = current->info->amount;
        (*dateOfManufacturing) = current->info->dateOfManufacturing;
        (*dateOfExpiration) = current->info->dateOfExpiration;

    }

}

treeT* findSmallestMedicie(treeT* current) {

    if(current->left == NULL)
        return current;

    return findSmallestMedicie(current->left);

}

treeT* deleteMedicine(treeT* current, char* array) {

    if(current == NULL)
        return NULL;

    if(strcmp(current->info->name, array) > 0)
        current->left = deleteMedicine(current->left, array);
    else if(strcmp(current->info->name, array) < 0)
        current->right = deleteMedicine(current->right, array);
    else {

        if(current->left == NULL) {

            treeT* node = current->right;
            free(current);
            return node;

        } else if(current->right == NULL) {

            treeT* node = current->left;
            free(current);
            return node;

        } else {

            treeT* node = findSmallestMedicie(current->right);
            strcpy(current->info->name, node->info->name);
            current->info->price = node->info->price;
            current->info->amount = node->info->amount;
            current->info->dateOfManufacturing = node->info->dateOfManufacturing;
            current->info->dateOfExpiration = node->info->dateOfExpiration;
            current->right = deleteMedicine(current->right, node->info->name);

        }
    }
    return current;
}

int verifyIfExp(treeT* current) {

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int year;
    int month;
    int day;
    day = current->info->dateOfExpiration % 100;
    month = current->info->dateOfExpiration / 100 % 100;
    year = current->info->dateOfExpiration / 10000;

    if(tm.tm_year + 1900 > year)
        return 1;

    if(tm.tm_year + 1900 == year && tm.tm_mon + 1 > month)
        return 1;

    if(tm.tm_year + 1900 == year && tm.tm_mon + 1 == month && tm.tm_mday > day)
        return 1;

    return 0;

}

treeExpT* insertExp(treeExpT* currentExp, treeT* current) {

    if(currentExp == NULL) {

        currentExp = initializeExp(currentExp);
        strcpy(currentExp->info->name, current->info->name);
        currentExp->info->price = current->info->price;
        currentExp->info->amount = current->info->amount;
        currentExp->info->dateOfExpiration = current->info->dateOfExpiration;
        currentExp->info->dateOfManufacturing = current->info->dateOfManufacturing;

    } else {

        if(strcmp(currentExp->info->name, current->info->name) < 0)
            insertExp(currentExp->right, current);
        else if(strcmp(currentExp->info->name, current->info->name) > 0)
            insertExp(currentExp->left, current);


    }
    return currentExp;
}

void goThroughBst(treeT* current) {

    if(current != NULL) {

        if(verifyIfExp(current) == 1)
            rootExp = insertExp(rootExp, current);

        goThroughBst(current->left);
        goThroughBst(current->right);


    }
}

void readCommand(FILE* in) {

    char* command = (char*)malloc(100);
    char* aux = (char*)malloc(40);
    char* tok = (char*)malloc(40);
    char* name = (char*)malloc(40);
    float price;
    int amount;
    int dateOfManufacturing;
    int dateOfExpiration;

    while(fgets(command, 100, in) != NULL) {

        switch(command[0]) {

        case 'i':

            name = strtok(command + 1, ",");
            price = convertCharToFloat(strtok(NULL, ","));
            amount = atoi(strtok(NULL, ","));
            dateOfManufacturing = atoi(strtok(NULL, ","));
            dateOfExpiration = atoi(strtok(NULL, "\n\0"));
            root = insert(root, name, price, amount, dateOfManufacturing, dateOfExpiration);
            break;

        case 'u':

            strcpy(aux, command);
            tok = strtok(aux + 1, ","); ///first name
            find(root, tok, &price, &amount, &dateOfManufacturing, &dateOfExpiration);

            tok = strtok(NULL, ","); ///second name
            tok = strtok(NULL, ","); ///price
            if(strcmp(tok, "~") != 0)
                price = convertCharToFloat(tok);

            tok = strtok(NULL, ","); ///amount
            if(strcmp(tok, "~") != 0)
                amount = atoi(tok);

            tok = strtok(NULL, ","); ///dateOfManuf
            if(strcmp(tok, "~") != 0)
                dateOfManufacturing = atoi(tok);

            tok = strtok(NULL, "\n\0"); ///dateOfExp
            if(strcmp(tok, "~") != 0)
                dateOfExpiration = atoi(tok);

            name = strtok(command + 1, ",");
            root = deleteMedicine(root, name);
            name = strtok(NULL, ",");
            root = insert(root, name, price, amount, dateOfManufacturing, dateOfExpiration);

            break;

        case 'd':

            command[strlen(command) - 1] = '\0';
            root = deleteMedicine(root, command + 1);

            break;

        case 'c':
            if(command[1] != 'e')
                break;
            else {

                goThroughBst(root);

            }
        }
    }
}

void print(treeT* current) {

    if(current != NULL) {

        printf("%s %f %d %d %d\n\n", current->info->name, current->info->price, current->info->amount, current->info->dateOfExpiration, current->info->dateOfManufacturing);

    } else
        return;

    print(current->left);
    print(current->right);

}

void printExp(treeExpT* current) {

    if(current != NULL) {

        printf("%s %f %d %d %d\n\n", current->info->name, current->info->price, current->info->amount, current->info->dateOfExpiration, current->info->dateOfManufacturing);

    } else
        return;

    printExp(current->left);
    printExp(current->right);

}
int main(int argc, char* argv[]) {
    root = NULL;
    rootExp = NULL;

    FILE* in = fopen(argv[1], "r");
    FILE* out = fopen(argv[2], "w");

    //if(in == NULL || out == NULL)
    //return -1;

    readCommand(in);

    print(root);
    printf("\n\n\nThe expired medicines are:\n");
    printExp(rootExp);

    return 0;
}
