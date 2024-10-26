/*
============================================================================
Name : 6.c
Author : Shubham Sharma
Description : Write a simple program to create three threads.
Date: 12th Sep, 2024
============================================================================
*/
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
void print()
{
    printf("Printing from thread\n");
}

int main()
{
    pthread_t threadID1, threadID2, threadID3;
    int pstatus;
    pstatus = pthread_create(&threadID1, NULL, (void *)print, NULL);
    if (pstatus != 0)
    {
        perror("Error while creating thread");
        _exit(1);
    }

    pstatus = pthread_create(&threadID2, NULL, (void *)print, NULL);
    if (pstatus != 0)
    {
        perror("Error while creating thread");
        _exit(1);
    }

    pstatus = pthread_create(&threadID2, NULL, (void *)print, NULL);
    if (pstatus != 0)
    {
        perror("Error while creating thread");
        _exit(1);
    }

    pthread_exit(NULL);
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc -o 6.c 6
(base) mohitsharma@MacBook-Pro hands on list 2 % ./6
Printing from thread
Printing from thread
Printing from thread
============================================================================
*/