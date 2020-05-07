//
// Created by diana on 07/05/2020.
//

#include "parseData.h"

void readQueue(FILE *inputFile, Queue *queue) {
    char *readValue = (char *) malloc(sizeof(char) * MAX_CHAR_LENGTH);
    while (inputFile != NULL) {
        fscanf(inputFile, "%s", readValue);
        QueueNode* node = createNewQueueNode(readValue);
        enqueue(node, queue);
        if (feof(inputFile) != 0)
            break;
    }
}
