/*
============================================================================
Name : 29.c
Author : Shubham Sharma
Description : Write a program to remove the message queue.
Date: 17th Sep, 2024
============================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

int main()
{
    key_t key = ftok(".", 1);
    if (key == -1) {
        perror("Error generating key");
        return 1;
    }

    int msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("Error in msgget");
        return 1;
    }
    
    printf("Message Queue ID: %d\n", msgid);

    struct msqid_ds buf;
    if (msgctl(msgid, IPC_RMID, &buf) == -1) {
        perror("Error in msgctl");
        return 1;
    }

    printf("Message queue removed successfully.\n");
    return 0;
}

/*
============================================================================
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc 29.c -o 29
(base) mohitsharma@MacBook-Pro hands on list 2 % ./29
Message Queue ID: 393216
Message queue removed successfully.
============================================================================
*/