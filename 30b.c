/*
============================================================================
Name : 30b.c
Author : Shubham Sharma
Description : Write a program to create a shared memory.
    a.write some data to the shared memory
    b.attach with O_RDONLY and check whether you are able to overwrite.c.detach the shared memory
    d.remove the shared memory
Date: 17th Sep, 2024
============================================================================
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    key_t key = ftok(".", 'R'); // Use a character for the project ID
    if (key == -1) {
        perror("ftok error");
        return 1;
    }

    // Create shared memory
    int shmid = shmget(key, 1024, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget error");
        return 1;
    }

    // Attach shared memory
    char *data = shmat(shmid, NULL, 0);
    if (data == (char *)(-1)) {
        perror("shmat error");
        return 1;
    }

    // Write to shared memory
    printf("Write in shared memory:\n");
    fgets(data, 1024, stdin); // Using fgets for safer input

    // Detach shared memory
    if (shmdt(data) == -1) {
        perror("shmdt error");
        return 1;
    }

    // Optionally remove shared memory
    // shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc 30b.c -o 30b
(base) mohitsharma@MacBook-Pro hands on list 2 % ./30b
Write in shared memory:
sharma
============================================================================
*/