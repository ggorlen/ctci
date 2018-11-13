/**
 * 1.6
 *
 * Implement a method to perform basic string compression using the counts of repeated characters.
 * For example, the string aabcccccaaa would become a2b1c5a3. If the "compressed" string would not
 * become smaller than the original string, your method should return the original string.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *compress(char *str) {
    int i, j, k, l;
    size_t len = strlen(str);
    size_t result_len = 0;
    char *result = malloc(sizeof(*result) * (len * 2 + 1));
    char digits[20];

    for (i = 0; i < len; i = j) {
        for (j = i, k = 0; j < len && str[i] == str[j]; j++, k++);

        result[result_len++] = str[i];

        for (l = 0; k; k /= 10) {
            digits[l++] = (k % 10) + '0';
        }

        while (l--) {
            result[result_len++] = digits[l];
        }
    }

    result[result_len] = '\0';

    if (len <= result_len) {
        strncpy(result, str, len);
        result[len] = '\0';
    }

    return result;
}

int main() {
    char *result = compress("aabcccccaaa");
    printf("%s\n", result);
    free(result);

    result = compress("aabccccccccccccccccccaaa");
    printf("%s\n", result);
    free(result);

    result = compress("abcdefghijk");
    printf("%s\n", result);
    free(result);

    return 0;
}
