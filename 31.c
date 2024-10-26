/*
============================================================================
Name : 31.c
Author : Shubham Sharma
Description : Write a program to create a semaphore and initialize value to the semaphore.
    a. create a binary semaphore
    b. create a counting semaphore
============================================================================
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    union semun arg;
    key_t key;

    // Create binary semaphore
    key = ftok(".", 'B'); // Use a character for better clarity
    int semid_binary = semget(key, 1, IPC_CREAT | 0666);
    if (semid_binary == -1) {
        perror("semget (binary) failed");
        exit(1);
    }

    arg.val = 1; // Initialize binary semaphore to 1
    if (semctl(semid_binary, 0, SETVAL, arg) == -1) {
        perror("semctl (binary) failed");
        exit(1);
    }
    printf("Binary semaphore created with id: %d\n", semid_binary);

    // Create counting semaphore
    key = ftok(".", 'C'); // Use a different character
    int semid_counting = semget(key, 1, IPC_CREAT | 0666);
    if (semid_counting == -1) {
        perror("semget (counting) failed");
        exit(1);
    }

    arg.val = 10; // Initialize counting semaphore to 10
    if (semctl(semid_counting, 0, SETVAL, arg) == -1) {
        perror("semctl (counting) failed");
        exit(1);
    }
    printf("Counting semaphore created with id: %d, initial value: %d\n", semid_counting, arg.val);

    return 0;
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc 31.c -o 31
(base) mohitsharma@MacBook-Pro hands on list 2 % ./31
Binary semaphore created with id: 65536
Counting semaphore created with id: 65537, initial value: 10
============================================================================
*/