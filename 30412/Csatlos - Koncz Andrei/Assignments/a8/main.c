#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int vector[1000],freqVector[1001], bubble, mergeAct, counting;
int bubbleSort(int *vect);
int mergeSort(int * vect, int left, int right, int *merge);
void merge(int vect[], int left, int m, int right, int *merge);
int countingSort(int *vect);

int main() {
    for(int i=0; i < 1000; i++)
    {
        vector[i] = rand()%1000;
        freqVector[i] = 0;
    }
    int v[1000];

    for(int i=0; i < 1000; i++)
        v[i] = vector[i];
    bubble = bubbleSort(v);

    for(int i=0; i < 1000; i++)
        v[i] = vector[i];
    mergeSort(v,0,999,&mergeAct);

    for(int i=0; i < 1000; i++)
        v[i] = vector[i];
    counting = countingSort(v);

    printf("Bubble Sort = %d\n",bubble);
    printf("Merge Sort = %d\n",mergeAct);
    printf("Counting Sort = %d\n",counting);
    return 0;
}

int bubbleSort(int * v)
{
    int ok = 0, aux = 0, bubbleActions = 0;
    do
    {
        ok = 1;
        for (int i = 0; i < 999; ++i) {
            bubbleActions++;
            if(v[i]>v[i+1])
            {
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                ok = 0;
                bubbleActions++;
            }
        }
    }while(!ok);
    return bubbleActions;
}

int mergeSort(int * vect, int left, int right, int *mergeActions)
{
    if (left < right)
    {
        int m = left+(right-left)/2;
        *mergeActions = *mergeActions + 1;
        mergeSort(vect, left, m, mergeActions);
        *mergeActions = *mergeActions + 1;
        mergeSort(vect, m+1, right, mergeActions);

        merge(vect, left, m, right,mergeActions);
    }
}
void merge(int *vect, int left, int m, int right, int *mergeActions)
{
    *mergeActions = *mergeActions + 1;
    int i = 0, j = 0, k = left;
    int n1 = m - left + 1;
    int n2 =  right - m;
    int leftVect[n1], rightVect[n2];

    for (i = 0; i < n1; i++)
    {
        *mergeActions = *mergeActions + 1;
        leftVect[i] = vect[left + i];
    }

    for (j = 0; j < n2; j++)
    {
        *mergeActions = *mergeActions + 1;
        rightVect[j] = vect[m + 1+ j];
    }

    while (i < n1 && j < n2)
    {
        *mergeActions = *mergeActions + 1;
        if (leftVect[i] <= rightVect[j])
        {
            vect[k] = leftVect[i];
            *mergeActions = *mergeActions + 1;
            i++;
        }
        else
        {
            vect[k] = rightVect[j];
            *mergeActions = *mergeActions + 1;
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        *mergeActions = *mergeActions + 1;
        vect[k] = leftVect[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        *mergeActions = *mergeActions + 1;
        vect[k] = rightVect[j];
        j++;
        k++;
    }
}

int countingSort(int *vect)
{
    int count = 0;
    int output[1000];

    for(int i = 0; i < 1000; ++i)
    {
        ++freqVector[vect[i]];
        count++;
    }

    for (int i = 1; i <= 1000; ++i)
    {
        freqVector[i] += freqVector[i-1];
        count++;
    }
    for (int i = 0; i < 1000; ++i)
    {
        output[freqVector[vect[i]]-1] = vect[i];
        --freqVector[vect[i]];
        count++;
    }
    return count;
}