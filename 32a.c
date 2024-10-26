/*
============================================================================
Name : 32a.c
Author : Shubham Sharma
Description : Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
b. protect shared memory from concurrent write access
c. protect multiple pseudo resources ( may be two) using counting semaphore
d. remove the created semaphore
============================================================================
*/
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>  // For O_CREAT and O_EXCL
#include <unistd.h>
#include <stdlib.h>

#define NUM_THREADS 5
#define SEM_NAME "/ticket_semaphore"

int ticket_number = 0; // Shared resource
sem_t *semaphore;      // Semaphore pointer

// Critical section where the ticket is created
void* create_ticket(void* thread_id) {
    long tid = (long) thread_id;

    sem_wait(semaphore); // Acquire the semaphore to enter the critical section

    // Critical section
    printf("Thread %ld is entering the critical section.\n", tid);
    ticket_number++;
    printf("Thread %ld created ticket number: %d\n", tid, ticket_number);
    sleep(1); // Simulate some work

    printf("Thread %ld is leaving the critical section.\n", tid);

    sem_post(semaphore); // Release the semaphore

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    long i;

    // Open the named semaphore, creating it if it doesn't exist
    semaphore = sem_open(SEM_NAME, O_CREAT, 0644, 1);
    if (semaphore == SEM_FAILED) {
        perror("sem_open failed");
        exit(EXIT_FAILURE);
    }

    // Create threads
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, create_ticket, (void*) i);
    }

    // Wait for all threads to complete
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Close and unlink the semaphore
    sem_close(semaphore);
    sem_unlink(SEM_NAME);

    printf("Final ticket number: %d\n", ticket_number);

    return 0;
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc 32a.c -o 32a
(base) mohitsharma@MacBook-Pro hands on list 2 % ./32a
Thread 0 is entering the critical section.
Thread 0 created ticket number: 1
Thread 0 is leaving the critical section.
Thread 1 is entering the critical section.
Thread 1 created ticket number: 2
Thread 1 is leaving the critical section.
Thread 2 is entering the critical section.
Thread 2 created ticket number: 3
Thread 2 is leaving the critical section.
Thread 3 is entering the critical section.
Thread 3 created ticket number: 4
Thread 3 is leaving the critical section.
Thread 4 is entering the critical section.
Thread 4 created ticket number: 5
Thread 4 is leaving the critical section.
Final ticket number: 5
============================================================================
*/