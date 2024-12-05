#include <stdlib.h>
#include <stdio.h>

int comp(unsigned int *a, unsigned int *b) {
    return a-b;
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

    unsigned int la[1000];
    unsigned int lb[1000];
    for (size_t i=0; i<1000; i++) {
        fscanf(fptr, "%u   %u", la+i, lb+i);
    }

    fclose(fptr);
    return 0;
}