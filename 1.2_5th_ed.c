/**
 * 1.2
 * Implement a function void reverse(char* str) in C or C++
 * which reverses a null-terminated string.
*/

#include <stdio.h>
#include <string.h>

void reverse(char *str) {
    int l, r;
    size_t len = strlen(str);

    for (l = 0, r = len - 1; l < len / 2; l++, r--) {
        char tmp = str[l];
        str[l] = str[r];
        str[r] = tmp;
    }
}

int main() {
    char str[] = "hello world";
    reverse(str);
    printf("%s\n", str);

    return 0;
}
