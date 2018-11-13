/**
 * 10.1
 * 
 * You are given two sorted arrays, A and B, where A has a large enough buffer 
 * at the end to hold B. Write a method to merge B into A in sorted order.
*/

#include <stdio.h>
#include <stdlib.h>

void merge_sorted(size_t a_len, size_t b_len, int *a, int *b) {
    int i = 0;
    int j = 0;
    int merged[a_len+b_len];
    size_t merged_len = 0;

    while (i < a_len && j < b_len) {
        merged[merged_len++] = a[i] < b[j] ? a[i++] : b[j++];
    }

    while (i < a_len) {
        merged[merged_len++] = a[i++];
    }

    while (j < b_len) {
        merged[merged_len++] = b[j++];
    }

    for (i = 0; i < merged_len; i++) {
        a[i] = merged[i];
    }
}

int main() {
    int i;
    size_t a_len = 4;
    size_t b_len = 6;
    size_t total_len = a_len + b_len;
    int *a = malloc(sizeof(*a) * total_len);
    int *b = malloc(sizeof(*b) * b_len);
    
    for (i = 0; i < a_len; i++) {
        a[i] = i;
    }
    
    for (i = 0; i < b_len; i++) {
        b[i] = i;
    }

    merge_sorted(a_len, b_len, a, b);

    for (i = 0; i < total_len; i++) {
        printf("%d ", a[i]);
    }

    puts("");
    free(a);
    free(b);
    return 0;
}
