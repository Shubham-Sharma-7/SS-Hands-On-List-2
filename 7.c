/*
============================================================================
Name : 7.c
Author : Shubham Sharma
Description : Write a simple program to print the created thread ids.
Date: 12th Sep, 2024
============================================================================
*/
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
void print()
{
    printf("Printing from thread :%lu\n", pthread_self());
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
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc -o 7.c 7
(base) mohitsharma@MacBook-Pro hands on list 2 % ./7
Printing from thread :6092484608
Printing from thread :6093058048
Printing from thread :6093631488
============================================================================
*/