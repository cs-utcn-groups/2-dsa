#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int noOfActionsRadix=0;
int noOfActionsMerge=0;
void swap(int *a,int *b){
    int aux=*a;
    *a=*b;
    *b=aux;
}
int bubbleSort(int *array,int size){
    bool sorted=false;
    int noOfActions=0;
    while(!sorted){
        sorted=true;
        for(int i=0;i<size-1;i++) {
            noOfActions+=3;
            if (array[i] > array[i + 1]) {
                swap(&array[i], &array[i + 1]);
                sorted = false;
                noOfActions+=3;
            }
        }
    }
    return noOfActions;
}

void merge(int *array,int left,int middle,int right){
    int size1=middle-left+1;
    int size2=right-middle;
    noOfActionsMerge+=2;
    int *l=(int*)malloc(size1*sizeof(int));
    int *r=(int*)malloc(size2*sizeof(int));
    for(int i=0;i<size1;i++)
        l[i]=array[left+i];
    for(int i=0;i<size2;i++)
        r[i]=array[middle+i+1];
    noOfActionsMerge+=2*(right-left)+3;
    int i=0,j=0,k=left;
    while(i<size1 && j<size2){
        noOfActionsMerge+=2;
        if(l[i]<r[j]){
            noOfActionsMerge+=4;
            array[k]=l[i];
            i++;
        }
        else if(l[i]>r[j]){
            noOfActionsMerge+=5;
            array[k]=r[j];
            j++;
        }
        else{
            noOfActionsMerge+=6;
            array[k]=l[i];
            i++;
            j++;
        }
        noOfActionsMerge+=1;
        k++;
    }
    while(i<size1){
        noOfActionsMerge+=5;
        array[k]=l[i];
        i++;
        k++;
    }
    while(j<size2){
        noOfActionsMerge+=5;
        array[k]=r[j];
        k++;
        j++;
    }
}

int mergeSort(int *array,int left,int right){
    if(left<right) {
        int middle = (left + right) / 2;
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);
        merge(array, left, middle, right);
    }
    return noOfActionsMerge;
}

int getMax(int *array, int n){
    int mx = array[0];
    noOfActionsRadix+=2;
    for (int i = 1; i < n; i++) {
        noOfActionsRadix+=1;
        if (array[i] > mx) {
            mx = array[i];
            noOfActionsRadix += 2;
        }
    }
    return mx;
}

void countSort(int *array, int size, int exp){
    int *output=(int*)malloc(size*sizeof(int));
    int *freq=(int*)malloc(10*sizeof(int));
    for(int i=0;i<10;i++)
        freq[i]=0;
    noOfActionsRadix+=9;
    for (int i = 0; i < size; i++)
        freq[(array[i]/exp)%10]++;
    noOfActionsRadix+=2*size;
    for (int i = 1; i < 10; i++)
        freq[i] += freq[i-1];
    noOfActionsRadix+=8;
    for (int i = size - 1; i >= 0; i--){
        output[freq[(array[i]/exp)%10]-1]=array[i];
        freq[(array[i]/exp)%10]--;
        noOfActionsRadix+=7;
    }

    for (int i = 0; i < size; i++)
        array[i] = output[i];
    noOfActionsRadix+=2*size;
}

int radixSort(int *array, int size){
    int max = getMax(array, size);
    for (int exp = 1; max/exp > 0; exp *= 10)
        countSort(array, size, exp);
    return noOfActionsRadix;
}

void randomNumberFile(){
    int n = 10000;
    srand(0);
    FILE *f=fopen("../input.dat","w");
    for(int  i = 0 ; i < n ; i++) {
        fprintf(f,"%d ", rand());
        if(i%100==0 && i!=0)
            fprintf(f,"\n");
    }
}

int main() {
    randomNumberFile();
    const int N=10000;
    int *array=(int*)malloc(N*sizeof(int));
    FILE *f=fopen("../input.dat","r");

    for(int i=0;i<N;i++)
        fscanf(f,"%d",&array[i]);
    printf("Bubble sort:\nNo of actions: %d\n",bubbleSort(array,N));

    fclose(f);
    f=fopen("../input.dat","r");
    for(int i=0;i<N;i++)
        fscanf(f,"%d",&array[i]);
    printf("\nMerge sort:\nNo of actions: %d\n",mergeSort(array,0,N-1));

    fclose(f);
    f=fopen("../input.dat","r");
    for(int i=0;i<N;i++)
        fscanf(f,"%d",&array[i]);
    printf("\nRadix sort:\nNo of actions: %d\n",radixSort(array,N));

    return 0;
}
