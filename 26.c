/*
============================================================================
Name : 26.c
Author : Shubham Sharma
Description : Write a program to create a message queue and print the key and message queue id.
Date: 17th Sep, 2024
============================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

typedef struct mesg_buffer
{
    /* data */
    long mesg_type;
    char mesg_text[100];
} mesg_buffer;
int main()
{
    /* code */
    mesg_buffer message;
    // generate unique no
    key_t key = ftok(".", 1); // projext path is current directory and project id=1
    // create message queue using msgget
    //  msgget creates a message queue
    //  and returns identifier
    int msgid = msgget(key, 0666 | IPC_CREAT);
    printf("enter msgtype:\n");
    scanf("%ld", &message.mesg_type);
    printf("enter data: \n");
    getchar();
    fgets(message.mesg_text, 100, stdin);
    msgsnd(msgid, &message, sizeof(message), 0);
    return 0;
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands on list 2 % ./26
enter msgtype:
1
enter data: 
Hello
============================================================================
*/