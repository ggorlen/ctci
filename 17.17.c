/**
 * 17.17 Multi Search: 
 *
 * Given a string and an array of smaller strings T, design 
 * a method to search b for each small string in T.
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct search_task_t {
    int id;
    int haystack_len;
    int needle_len;
    char *haystack;
    char *needle;
    int *results;
} search_task_t;

static void *search(void *arg) {
    int i;
    search_task_t task = *((search_task_t*)arg);

    for (i = 0; i < task.haystack_len - task.needle_len; i++) {
        if (!memcmp(&task.haystack[i], task.needle, task.needle_len)) {
            task.results[task.id] = i;
            break;
        }
    }

    free(arg);
    return NULL;
}

int main() {
    int i;
    char haystack[] = "hello world! foo bar.";
    int haystack_len = strlen(haystack);
    char words[][16] = {
        "bar",
        "quux",
        "foo bar",
        "foo",
        "baz"
    };
    int words_len = 5;
    int thread_ids[words_len];
    int results[words_len];
    memset(results, -1, words_len * sizeof(int));
    pthread_t threads[words_len];

    for (i = 0; i < words_len; i++) {
        search_task_t *task = malloc(sizeof(*task));
        thread_ids[i] = i;
        task->id = thread_ids[i];
        task->haystack_len = haystack_len;
        task->needle_len = strlen(words[i]);
        task->needle = words[i];
        task->haystack = haystack;
        task->results = results;

        pthread_t thread;
        pthread_create(&thread, NULL, search, task);
        threads[i] = thread;
    }

    for (i = 0; i < words_len; i++) {
        pthread_join(threads[i], NULL);
        printf("'%s' position in '%s': %d\n", words[i], haystack, results[i]);
    }

    return 0;
}
