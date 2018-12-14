/**
 * 15.7 FizzBuzz: 
 * 
 * In the classic problem FizzBuzz, you are told to print the 
 * numbers from 1 to n. However, when the number is divisible 
 * by 3, print "Fizz". When it is divisible by 5, print "Buzz". 
 * When it is divisible by 3 and 5, print "FizzBuzz". In this 
 * problem, you are asked to do this in a multithreaded way.  
 * Implement a multithreaded version of FizzBuzz with four 
 * threads. One thread checks for divisibility of 3 and prints 
 * "Fizz". Another thread is responsible for divisibility of 
 * 5 and prints "Buzz". A third thread is responsible for 
 * divisibility of 3 and 5 and prints "FizzBuzz". A fourth 
 * thread does the numbers.
*/

#include <pthread.h>
#include <stdio.h>

int counter;
pthread_mutex_t counter_m = PTHREAD_MUTEX_INITIALIZER; 
pthread_cond_t counter_c = PTHREAD_COND_INITIALIZER;

void *fizz(void *arg) {
    for (;;) {
        pthread_mutex_lock(&counter_m);

            while ((counter % 3 != 0 || counter % 5 == 0) &&
                    counter < *(int *)arg) {
                pthread_cond_wait(&counter_c, &counter_m);
            }
            
            if (counter >= *(int *)arg) { 
                pthread_mutex_unlock(&counter_m);
                break; 
            }

            puts("Fizz");
            counter++;

        pthread_mutex_unlock(&counter_m);
        pthread_cond_broadcast(&counter_c);
    }

    return NULL;
}

void *buzz(void *arg) {
    for (;;) {
        pthread_mutex_lock(&counter_m);

            while ((counter % 5 != 0 || counter % 3 == 0) && 
                     counter < *(int *)arg) {
                pthread_cond_wait(&counter_c, &counter_m);
            }
            
            if (counter >= *(int *)arg) { 
                pthread_mutex_unlock(&counter_m);
                break; 
            }

            puts("Buzz");
            counter++;

        pthread_mutex_unlock(&counter_m);
        pthread_cond_broadcast(&counter_c);
    }

    return NULL;
}

void *fizzbuzz(void *arg) {
    for (;;) {
        pthread_mutex_lock(&counter_m);
            
            while ((counter % 3 != 0 || counter % 5 != 0) &&
                    counter < *(int *)arg) {
                pthread_cond_wait(&counter_c, &counter_m);
            }
            
            if (counter >= *(int *)arg) { 
                pthread_mutex_unlock(&counter_m);
                break; 
            }
        
            puts("FizzBuzz");
            counter++;
        
        pthread_mutex_unlock(&counter_m);
        pthread_cond_broadcast(&counter_c);
    }

    return NULL;
}

void *numbers(void *arg) {
    for (;;) {
        pthread_mutex_lock(&counter_m);
        
            while ((counter % 3 == 0 || counter % 5 == 0) && 
                    counter < *(int *)arg) {
                pthread_cond_wait(&counter_c, &counter_m);
            }
            
            if (counter >= *(int *)arg) { 
                pthread_mutex_unlock(&counter_m);
                break; 
            }
        
            printf("%d\n", counter++);
        
        pthread_mutex_unlock(&counter_m);
        pthread_cond_broadcast(&counter_c);
    }

    return NULL;
}

int main() {
    int i;
    int n = 100;
    void *(*funcs[4]) (void *arg) = {fizz, buzz, fizzbuzz, numbers};
    pthread_t threads[4];
    counter = 1;
    
    for (i = 0; i < 4; i++) {
        pthread_t thread;
        threads[i] = thread;
        pthread_create(&thread, NULL, funcs[i], &n);
    }
    
    for (i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
        pthread_cond_broadcast(&counter_c);
    }
    
    return 0;
}
