/**
 * 1.5
 *
 * One Away: 
 * There are three types of edits that can be performed on strings: insert a character,
 * remove a character, or replace a character. Given two strings, write a function to 
 * check if they are one edit (or zero edits) away.
 *
 * EXAMPLE
 * pale, ple -> true
 * pales, pale -> true
 * pale, bale -> true
 * pale, bake -> false
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int one_away(char *a, char *b) {
    int i, j;
    int distance = 0;
    int a_len = strlen(a);
    int b_len = strlen(b);

    if (a_len - b_len > 1 || a_len - b_len < -1) {
        return 0;
    }

    for (i = 0, j = 0; i < a_len && j < b_len; i++, j++) {
        if (a[i] != b[j]) {
            if (distance++) {
                return 0;
            }

            if (i + 1 < a_len && a[i+1] == b[j]) {
                j--;
            }
            else if (j + 1 < b_len && a[i] == b[j+1]) {
                i--;
            }
        }
    }

    return a_len - i + b_len - j + distance <= 1;
}

int main() {
    int i;
    int tests_len = 6;
    char tests[][2][8] = {
        {"pale", "ple"},
        {"pales", "pale"},
        {"pale", "bale"},
        {"pale", "bake"},
        {"xbc", "ab"},
        {"accd", "abcc"}
    };

    for (i = 0; i < tests_len; i++) {
        printf(
            "%s, %s: %s\n", 
            tests[i][0], tests[i][1], 
            one_away(tests[i][0], tests[i][1]) ? "true" : "false"
        );
    }

    return 0;
}
