#include <stdio.h>
#include "header.h"
#include <stdlib.h>
#include <string.h>

int main() {


    FILE *f=fopen("../input.dat","r");
    FILE *g=fopen("../output.dat","w");

    doublyLinked time;
    time=getTime(f);
    printAll(&time, g);

    doublyLinked customerData= getCustomerData(f);
    printCustomerData(&customerData, g);

    int currentTime=0;
    int currentRubles=0;

    NodeT *dummyCustomer = customerData.sentinel->next;
    NodeT *timeCheck = time.sentinel->next;

    while(dummyCustomer != customerData.sentinel){
        if (currentTime + dummyCustomer->time < timeCheck->data){
            currentTime = currentTime + dummyCustomer->time;
            currentRubles = currentRubles + dummyCustomer->rubles;
        }
        else if (currentTime + dummyCustomer->time >= timeCheck->data){
            fprintf (g, "After %d: %d rubles\n", timeCheck->data, currentRubles);
            timeCheck = timeCheck->next;
        }
        dummyCustomer = dummyCustomer->next;
    }
    return 0;
}