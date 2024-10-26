/*
============================================================================
Name : 30c.c
Author : Shubham Sharma
Description : Write a program to create a shared memory.
    a.write some data to the shared memory
    b.attach with O_RDONLY and check whether you are able to overwrite.c.detach the shared memory
    c.remove the shared memory
Date: 17th Sep, 2024
============================================================================
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
int main()
{
    key_t key = ftok(".", 2);
    // shared memory created
    int shmid = shmget(key, 1024, IPC_CREAT | 0744);
    // attach shared memory to process adress space
    char *data_pointer;
    data_pointer = shmat(shmid, (void *)0, 0);
    if (data_pointer == (void *)-1)
    {
        perror("Shared memory not attach");
        return 1;
    }
    printf("Shared memory attached press any key to detach it\n");
    getchar();
    printf("Detaching pointer to shared memory\n");
    shmdt(data_pointer); // Dettach pointer to Shared Memory (data_pointer)
    return 1;
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc 30c.c -o 30c
(base) mohitsharma@MacBook-Pro hands on list 2 % ./30c
Shared memory attached press any key to detach it
1
Detaching pointer to shared memory
============================================================================
*/