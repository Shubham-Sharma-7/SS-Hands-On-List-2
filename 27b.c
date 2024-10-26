/*
============================================================================
Name : 27b.c
Author : Shubham Sharma
Description : Write a program to receive messages from the message queue.
a. with 0 as a flag
b. with IPC_NOWAIT as a flag
Date: 17th Sep, 2024
============================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h> // Include for errno definitions

typedef struct mesg_buffer {
    long mesg_type;
    char mesg_text[100];
} mesg_buffer;

int main() {
    mesg_buffer message;
    key_t key = ftok(".", 1); // Unique key for the message queue
    int msgid = msgget(key, 0666 | IPC_CREAT); // Create or access the message queue

    if (msgid == -1) {
        perror("Error in msgget");
        exit(1);
    }

    // Receive message with IPC_NOWAIT flag
    if (msgrcv(msgid, &message, sizeof(message), 0, IPC_NOWAIT) == -1) {
        if (errno == ENOMSG) {
            printf("No messages available\n");
        } else {
            perror("Error in msgrcv");
            exit(1);
        }
    } else {
        printf("Received Message: %s", message.mesg_text);
        printf("Message Type: %ld\n", message.mesg_type);
    }

    return 0;
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc 27b.c -o 27b
(base) mohitsharma@MacBook-Pro hands on list 2 % ./27b
Shubham
============================================================================
*/