/*
============================================================================
Name : 30a.c
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
int main()
{
    key_t key = ftok(".", 2);
    // shared memory created
    int shmid = shmget(key, 1024, IPC_CREAT | 0744);
    // attach shared memory to process adress space
    char *data;
    data = shmat(shmid, (void *)0, 0);
    printf("write in shared memory\n");
    scanf("%[^\n]", data);

    printf("data from shared memory : %s\n", data);
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc 30a.c -o 30a
(base) mohitsharma@MacBook-Pro hands on list 2 % ./30a
write in shared memory
shubham
data from shared memory : shubham
============================================================================
*/