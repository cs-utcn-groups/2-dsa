
#include "header.h"
int main( ) {

    initHashTable(100);

   int N = _100;
   writeToFile(N);
   insertElement("aaaa");
   
   char ** content = readFromFile(N);

    for(int i = 0; i < N; i++){
        insertElement(*(content+i));
    }


    printHashTable();

}