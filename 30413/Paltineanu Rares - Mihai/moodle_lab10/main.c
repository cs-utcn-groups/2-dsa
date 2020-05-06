#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b) {

    return (a > b) ? b : a;

}
int min3(int a, int b, int c) {

    return min(min(a, b), c);

}

int minStepts(char* s1, char* s2, int size1, int size2) {

    if(size1 == 0)
        return size2;

    if(size2 == 0)
        return size1;

    if(s1[size1 -1] == s2[size2 - 1])
        return minStepts(s1, s2, size1 - 1, size2 - 1);

    return 1 + min3(minStepts(s1, s2, size1 - 1, size2), minStepts(s1, s2, size1, size2 - 1), minStepts(s1, s2, size1 - 1, size2 - 1));

}

int main() {

    int t;
    scanf("%d", &t);
    getchar();
    char* s1 = malloc(1001);
    char* s2 = malloc(1001);

    while(t--) {

        gets(s1);
        gets(s2);
        printf("%d\n", minStepts(s1, s2, strlen(s1), strlen(s2)));

    }
    return 0;
}
