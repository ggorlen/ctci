/**
 * 5.5 
 * 
 * Write a function to determine the number of bits required to convert integer A
 * to integer B.
 * 
 * EXAMPLE
 * Input: 31,14
 * Output: 2
*/

#include <stdio.h>

int popcount(int d) {
    int count = 0;

    while (d) {
        count += d & 1;
        d >>= 1;
    }

    return count;
}

int bits_required(int a, int b) {
    return popcount(a ^ b);
}

int main() {
    printf("31 to 14: %d\n", bits_required(31, 14));
    printf("12324 to 3452: %d\n", bits_required(12324, 3452));
    printf("102 to 102: %d\n", bits_required(102, 102));
    printf("32 to 31: %d\n", bits_required(32, 31));

    return 0;
}
