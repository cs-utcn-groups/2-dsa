#include "extraFunctions.h"

#define FILE_PATH "../output.dat"
#define INPUT_FILE_PATH "../input.dat"
#define ERROR_CODE "sorry, the file could not be opened"

int main() {
    FILE *output = fopen(FILE_PATH, "w+");
    if (output == NULL) {
        perror(ERROR_CODE);
        exit(1);
    }
    FILE *input = fopen(INPUT_FILE_PATH, "r");
    if (input == NULL) {
        perror(ERROR_CODE);
        exit(1);
    }
    initializeSll();
    callingTheFunction(input, output);
    return 0;
}

