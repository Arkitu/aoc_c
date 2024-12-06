#include <stdlib.h>
#include <stdio.h>

int comp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    FILE *fptr;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fptr = fopen("input/1.txt","r");

    if (fptr == NULL) {
        printf("File pointer is NULL!");
        exit(1);
    }

    int la[1000];
    int lb[1000];
    for (size_t i=0; i<1000; i++) {
        fscanf(fptr, "%d   %d", la+i, lb+i);
    }

    qsort(la, 1000, sizeof(int), comp);
    qsort(lb, 1000, sizeof(int), comp);
    
    int count = 0;
    for (size_t i=0; i<1000; i++) {
        for (size_t j=0; j<1000; j++) {
            if (la[i] == lb[j]) {
                count += la[i];
            }
        }
    }

    printf("%i", count);

    fclose(fptr);
    return 0;
}