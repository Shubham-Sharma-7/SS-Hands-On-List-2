/*
============================================================================
Name : 27a.c
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

    // Input message type
    printf("Enter msgtype:\n");
    scanf("%ld", &message.mesg_type);
    getchar(); // Clear the newline character from the buffer
    printf("Enter data: \n");
    fgets(message.mesg_text, 100, stdin);

    // Send message to the queue
    if (msgsnd(msgid, &message, sizeof(message), 0) == -1) {
        perror("Error in msgsnd");
        exit(1);
    }

    printf("Message sent: %s", message.mesg_text);
    return 0;
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc 27a.c -o 27a
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc 27b.c -o 27b
(base) mohitsharma@MacBook-Pro hands on list 2 % ./27a
Enter msgtype:
1
Enter data: 
Shubham
Message sent: Shubham
============================================================================
*/